# SSI Arduino
Simulink Serial Interface library for Arduino

[SSI Examples for MATLAB/Simulink](https://github.com/OpenSourceByBida/Simulink-Serial-Interface)

## Installation

- Download project as *.Zip* file
- Open *Arduino IDE*
- In *Arduino IDE* select *Sketch* -> *Include Library* -> *Add .ZIP library...*
- Select downloaded *.Zip* file

## Library usage

Include header
```C
#include "SSIA.h"
```

### MATLAB/Simulink

```C
float FromSimulink();           // Try to read data from MATLAB/Simulink
void  ToSimulink(float value);  // Try to write data to  MATLAB/Simulink
```

### Simulink Desktop RealTime

```C
float FromSimulinkRT();           // Try to read data from SimulinkRT
void  ToSimulinkRT(float value);  // Try to write data to  SimulinkRT
```