/*
 * Solenoid.h
 *
 *  Created on: Jun 4, 2015
 *      Author: billcoon
 */

#ifndef SUBSYSTEMS_SOLENOID_H_
#define SUBSYSTEMS_SOLENOID_H_

#include "Arduino.h"

class Solenoid {
public:
	Solenoid(int extendPin, int retractPin);
	virtual ~Solenoid();
	void init();
	void extend();
	void retract();
	void turnOff();
private:
	int extendPin;
	int retractPin;
};

#endif /* SUBSYSTEMS_SOLENOID_H_ */
