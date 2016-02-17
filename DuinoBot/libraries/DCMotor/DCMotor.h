#ifndef DCMotor__h
#define DCMotor__h

/* 	DCMotor

	A small DC motor control class.

	Copyright (C) 2010-2012 Multiplo
	http://robotgroup.com.ar
	http://multiplo.org
	Developers: Julián U. da Silva Gillig
	Created: 2010.04.06 (yyyy.mm.dd)
	Last modified: 2012.11.13 (yyyy.mm.dd)

	IMPORTANT NOTICE: This library is based on code from the SNAPI library, which is under The RobotGroup-Multiplo
	Pacifist License (RMPL). This license is (or may be) not compatible with the GNU Lesser General Public
	License (LGPL), so this notice constitutes an special written exception from Multiplo, to allow deployment
	under the LGPL, in order to be compiled with the Arduino libraries and still hold compatibility	between
	both licenses.
	But this does not affects the SNAPI original license in any way, and DOES NOT AUTHORIZES ANY THIRD PARTY
	TO USE OR REDISTRIBUTE THE SNAPI LIBRARY UNDER THE LGPL. In other words: This exception ONLY AFFECTS the
	library when compiled with Arduino libraries, if and only if, this license (the RMPL) results in some
	inconpatibility with the LGPL (so in this last case, then LGPL applies):

        This library is free software; you can redistribute it and/or
        modify it under the terms of the GNU Lesser General Public
        License as published by the Free Software Foundation; either
        version 2.1 of the License, or (at your option) any later version.

        This library is distributed in the hope that it will be useful,
        but WITHOUT ANY WARRANTY; without even the implied warranty of
        MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
        Lesser General Public License for more details.

    Any way, we strongly believe in peace, so we would not like to see our work in any non-civil or military
    project. But, due to the possible incompatibilty with the LGPL licenses, this may be only a recommendation
    and an expression of our wishes. But, if some clever guy can determine that LGPL and RMPL are compatible
    licenses, then RMPL applies here. You can contact us at: info_t1@multiplo.com.ar
*/

#include "Arduino.h"

#if defined(DUINOBOT_V1X) || defined(DUINOBOT_V1X_HID) || defined(DUINOBOT_KITS_V1X)
#define MOTOR_DELAY_TB6612	80
#endif
const float dcMotMaxSpeed = 100.0;
const float dcMotMinSpeed = -dcMotMaxSpeed;

struct DCMotor
{
 int clockwise;
 int braked;
 float speed;
 float prevSpeed;
 float zeroZone;
 int enable_pin;
 int d0_pin;
 int d1_pin;  
};



struct DCMotor DCMotor_create(const int enable_pin, const int d0_pin, const int d1_pin, int clockwise);
void DCMotor_setSpeed(struct DCMotor* m,const float value);
void DCMotor_brake(struct DCMotor* m);
void DCMotor_setClockwise(struct DCMotor *m,int  value);








#endif
