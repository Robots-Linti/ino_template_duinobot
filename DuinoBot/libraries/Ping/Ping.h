#ifndef Ping__h
#define Ping__h

/*
   2011.12.23 (yyyy.mm.dd):
   This class is based on the sketch created by David A. Mellis and Tom Igoe (please see notice below).
   The class is a wrapper written by Julián U. da Silva Gillig and is under the RMPL (RobotGroup-Multiplo-Pacifist-License), but
   the code inside the functions is in the public domain (as is the original code from David A. Mellis).
   available from http://robotgroup.com.ar and from http://minibloq.org.
*/

/* Ping))) Sensor
     
   This sketch reads a PING))) ultrasonic rangefinder and returns the
   distance to the closest object in range. To do this, it sends a pulse
   to the sensor to initiate a reading, then listens for a pulse 
   to return.  The length of the returning pulse is proportional to 
   the distance of the object from the sensor.
 
   The circuit:
    * +V connection of the PING))) attached to +5V
    * GND connection of the PING))) attached to ground
    * SIG connection of the PING))) attached to digital pin 7
 
   http://www.arduino.cc/en/Tutorial/Ping
 
   created 3 Nov 2008
   by David A. Mellis
   modified 30 Jun 2009
   by Tom Igoe
 
   This example code is in the public domain.

*/ 
 
#include "Arduino.h"
struct PingSensor {
   int pin;
};

struct PingSensor PingSensor_create(int pin);
long PingSensor_measure(struct PingSensor*p);
long PingSensor_measureCM(struct PingSensor*p);
long PingSensor_measureInches(struct PingSensor*p);
long PingSensor_measureCM_prom(struct PingSensor*p);


#endif
