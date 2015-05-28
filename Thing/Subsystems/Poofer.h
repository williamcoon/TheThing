/*
 * Poofer.h
 *
 *  Created on: May 28, 2015
 *      Author: williamcoon
 */

#ifndef COMMANDS_POOFER_H_
#define COMMANDS_POOFER_H_

#include <CommandBase.h>
#include "Arduino.h"
#include "PinDefinitions.h"

class Poofer{
public:
	virtual ~Poofer();
	static Poofer* getInstance();
	void init();
	void openFire();
	void ceaseFire();
private:
	Poofer();
	static Poofer* instance;
	int pooferPin;
};

#endif /* COMMANDS_POOFER_H_ */
