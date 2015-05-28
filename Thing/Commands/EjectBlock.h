/*
 * EjectBlock.h
 *
 *  Created on: May 28, 2015
 *      Author: williamcoon
 */

#ifndef COMMANDS_EJECTBLOCK_H_
#define COMMANDS_EJECTBLOCK_H_

#include <CommandBase.h>
#include "Ejector.h"
#include "Arduino.h"

class EjectBlock: public CommandBase {
public:
	EjectBlock();
	virtual ~EjectBlock();
	void execute();
	bool isFinished();
	void stop();
private:
	bool finished;
	static Ejector *ejector;
	unsigned long startTime;
};

#endif /* COMMANDS_EJECTBLOCK_H_ */
