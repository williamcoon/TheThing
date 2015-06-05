/*
 * Ejector.h
 *
 *  Created on: May 28, 2015
 *      Author: williamcoon
 */

#ifndef SUBSYSTEMS_EJECTOR_H_
#define SUBSYSTEMS_EJECTOR_H_

#include "Arduino.h"
#include "PinDefinitions.h"
#include "Solenoid.h"

class Ejector {
public:
	virtual ~Ejector();
	static Ejector* getInstance();
	void init();
	void extend();
	void retract();
	void turnOff();
	unsigned long getLastRetractTime();
private:
	Ejector();
	static Ejector* instance;
	Solenoid *solenoid;
	unsigned long lastRetractTime;
};

#endif /* SUBSYSTEMS_EJECTOR_H_ */
