/*
 * FindHome.h
 *
 *  Created on: May 14, 2015
 *      Author: williamcoon
 */

#ifndef COMMANDS_FINDHOME_H_
#define COMMANDS_FINDHOME_H_

#include <CommandBase.h>
#include "Hand.h"
#include "Arduino.h"
#include "PinDefinitions.h"

class FindHome: public CommandBase {
public:
	FindHome(int speed);
	virtual ~FindHome();
	void execute();
	bool isFinished();
	void stop();
private:
	bool finished;
	static Hand *hand;
	int reed_pins[5];
};

#endif /* COMMANDS_FINDHOME_H_ */
