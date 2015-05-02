/*
 * Victor.h
 *
 *  Created on: May 1, 2015
 *      Author: williamcoon
 */


#ifndef SUBSYSTEMS_VICTOR_H_
#define SUBSYSTEMS_VICTOR_H_

#include "Arduino.h"
#include <MegaServo.h>

class Victor {
public:
	Victor(int pin);
	virtual ~Victor();
	void setSpeed(int speed);
	void startServo();
	void calibrate();
private:
	int servoPin;
	MegaServo servo;
};

#endif /* SUBSYSTEMS_VICTOR_H_ */
