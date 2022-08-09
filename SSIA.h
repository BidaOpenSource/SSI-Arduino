// Copyright (c) 2022 Pavlo Bida

#ifndef SSIA
#define SSIA

#include "Arduino.h"

void ToSimulink(float number);      //  Write float to Simulink (no terminator)
float FromSimulink();               //  Read data from Simulink (no terminator)

float FromSimulinkRT();             //  Writes float to Simulink Desktop RT  (terminator "\r\n")
void ToSimulinkRT(float number);    //  Reads float from Simulink Desktop RT (terminator "\r\t")

#endif
