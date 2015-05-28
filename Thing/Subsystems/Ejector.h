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

class Ejector {
public:
	virtual ~Ejector();
	static Ejector* getInstance();
	void init();
	void extend();
	void retract();
private:
	Ejector();
	static Ejector* instance;
	int ejectorPin;
};

#endif /* SUBSYSTEMS_EJECTOR_H_ */
