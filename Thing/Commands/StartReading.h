/*
 * StartReading.h
 *
 *  Created on: Jun 1, 2015
 *      Author: williamcoon
 */

#ifndef COMMANDS_STARTREADING_H_
#define COMMANDS_STARTREADING_H_

#include <CommandBase.h>
#include "RFID.h"

class RFID;

class StartReading: public CommandBase {
public:
	StartReading();
	virtual ~StartReading();
	void init();
	void execute();
	bool isFinished();
	void stop();
private:
	bool finished;
	static RFID *rfid;
};

#endif /* COMMANDS_STARTREADING_H_ */
