/*
 * EjectBlock.h
 *
 *  Created on: May 28, 2015
 *      Author: williamcoon
 */

#ifndef COMMANDS_EJECTBLOCK_H_
#define COMMANDS_EJECTBLOCK_H_

#include <CommandBase.h>
#include "RFID.h"
#include "Ejector.h"
#include "Arduino.h"

class RFID;

class EjectBlock: public CommandBase {
public:
	EjectBlock();
	virtual ~EjectBlock();
	void execute();
	bool isFinished();
	void stop();
private:
	static Ejector *ejector;
	static RFID* rfidReader;
	bool finished;
	unsigned long startTime;
};

#endif /* COMMANDS_EJECTBLOCK_H_ */
