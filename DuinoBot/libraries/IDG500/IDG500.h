/*

IDG500 - Library for Gyroscope IDG500
Federico Lanza for RobotGroup

Notes:
Connection IDG500 <------> DuinoBot
-----------------------------------
VCC --- 5V
GND --- GND
XOUT --- ANALOG 4
YOUT --- ANALOG 5

Changes:
  V0.1: Apr 2012                First release

*/

#ifndef IDG500_H
#define IDG500_H

#include "inttypes.h"

// Analog pins to read
#define IDG500_XAXIS_PIN      4
#define IDG500_YAXIS_PIN      5

// Sensitivity in mV/gr/s
#define IDG500_SENSITIVITY    2

// Duinobot resolution in mV/bit
#define IDG500_RESOLUTION     4.88

// Zero-Rate Reference voltage
#define IDG500_ZRO_XMV        1303
#define IDG500_ZRO_YMV        1264
struct IDG500 IDG500_create();
struct IDG500    IDG500_create_xy(int16_t ZroX, int16_t ZroY);
void IDG500_setReferences (int16_t ZroX, int16_t ZroY);
void IDG500_setCurrentAsReferences (struct IDG500 * idg);
float IDG500_getXAngularRate (struct IDG500 * idg);
float IDG500_getYAngularRate (struct IDG500 * idg);
struct IDG500
{
      int16_t ZeroReferenceX;
    int16_t ZeroReferenceY;  
  
};

#endif
