/*
 * BeanieLed.h
 *
 *  Created on: May 27, 2016
 *      Author: williamcoon
 */

#ifndef SUBSYSTEMS_BEANIELED_H_
#define SUBSYSTEMS_BEANIELED_H_

#include "Arduino.h"
#include "PinDefinitions.h"
#include "Solenoid.h"

class BeanieLed {
public:
	static BeanieLed *getInstance();
	virtual ~BeanieLed();
	void init();
	void turnOn();
	void turnOff();
private:
	BeanieLed();
	static BeanieLed *instance;
	int ledPin;
};

#endif /* SUBSYSTEMS_BEANIELED_H_ */
