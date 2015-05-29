/*
 * Poof.h
 *
 *  Created on: May 28, 2015
 *      Author: williamcoon
 */

#ifndef COMMANDS_POOF_H_
#define COMMANDS_POOF_H_

#include <CommandBase.h>
#include "Poofer.h"
#include "Arduino.h"

class Poof: public CommandBase {
public:
	Poof(unsigned long poofLength);
	virtual ~Poof();
	void init();
	void execute();
	bool isFinished();
	void stop();
private:
	bool finished;
	static Poofer *poofer;
	unsigned long poofLength;
	unsigned long startTime;
};

#endif /* COMMANDS_POOF_H_ */
