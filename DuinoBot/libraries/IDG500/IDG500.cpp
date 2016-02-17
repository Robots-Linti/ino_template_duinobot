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

#include "wiring.h"
#include "IDG500.h"

struct IDG500 IDG500_create()
{
  struct IDG500 idg500;
  // Read values for Zero Reference (supossing sensor is at rest)
  idg500.ZeroReferenceX = analogRead(IDG500_XAXIS_PIN);
  idg500.ZeroReferenceY = analogRead(IDG500_YAXIS_PIN); 	
  return idg500;
}
struct IDG500    IDG500_create_xy(int16_t ZroX, int16_t ZroY)
{
  struct IDG500 idg500; 
  idg500.ZeroReferenceX = ZroX;
  idg500.ZeroReferenceY = ZroY;
  return idg500;
}
void IDG500_setReferences (struct IDG500 * idg,int16_t ZroX, int16_t ZroY)
{
	idg->ZeroReferenceX = ZroX;
    idg->ZeroReferenceY = ZroY;
}
void IDG500_setCurrentAsReferences (struct IDG500 * idg)
{
  // Read values for Zero Reference (supossing sensor is at rest)
  idg->ZeroReferenceX = analogRead(IDG500_XAXIS_PIN);
  idg->ZeroReferenceY = analogRead(IDG500_YAXIS_PIN);  	
}
float IDG500_getXAngularRate (struct IDG500 * idg)
{
	int16_t XValue;
  
  XValue = analogRead(IDG500_XAXIS_PIN);
  return (((XValue - idg->ZeroReferenceX) * IDG500_RESOLUTION) / IDG500_SENSITIVITY);
}
float IDG500_getYAngularRate (struct IDG500 * idg)
{
	int16_t YValue;

  YValue = analogRead(IDG500_YAXIS_PIN);
  return (((YValue - idg->ZeroReferenceY) * IDG500_RESOLUTION) / IDG500_SENSITIVITY);
}









