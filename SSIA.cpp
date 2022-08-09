// Copyright (c) 2022 Pavlo Bida

#include "Arduino.h"

#define BSSIA_BUFF_SIZE 4

union BytesToFloat
{
  float value;
  byte bytes[BSSIA_BUFF_SIZE];
};

BytesToFloat BSSIA_INPUT_BUFFER;
BytesToFloat BSSIA_OUTPUT_BUFFER;

//  Write float to Simulink (no terminator)
void ToSimulink(float number)
{
  BSSIA_OUTPUT_BUFFER.value = number;
  Serial.write(BSSIA_OUTPUT_BUFFER.bytes, BSSIA_BUFF_SIZE);
}

//  Read data from Simulink (no terminator)
//  If data is unavailable returns previous value
float FromSimulink()
{
  if (Serial.available() >= 4)
    Serial.readBytes(BSSIA_INPUT_BUFFER.bytes, BSSIA_BUFF_SIZE);
  return BSSIA_INPUT_BUFFER.value;
}

//  Writes float to Simulink Desktop RT (terminator "\r\n")
void ToSimulinkRT(float number)
{
  BSSIA_OUTPUT_BUFFER.value = number;
  Serial.println(BSSIA_OUTPUT_BUFFER.value);
}

//  Reads float from Simulink Desktop RT (terminator "\r\t")
float FromSimulinkRT()
{
  BSSIA_INPUT_BUFFER.value = Serial.parseFloat(SKIP_ALL);
  return BSSIA_INPUT_BUFFER.value;
}
