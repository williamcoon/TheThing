/*
 * Victor.h
 *
 *  Created on: May 1, 2015
 *      Author: williamcoon
 */


#ifndef SUBSYSTEMS_VICTOR_H_
#define SUBSYSTEMS_VICTOR_H_

#include "Arduino.h"
#include "Servo.h"

class Victor {
public:
	Victor(uint8_t pin);
	virtual ~Victor();
	void setSpeed(int8_t speed);
	void calibrate();
private:
	uint8_t servoPin;
	Servo servo;
};

#endif /* SUBSYSTEMS_VICTOR_H_ */
