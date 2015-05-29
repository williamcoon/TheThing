/*
 * StopAll.h
 *
 *  Created on: May 29, 2015
 *      Author: billcoon
 */

#ifndef COMMANDS_STOPALL_H_
#define COMMANDS_STOPALL_H_

#include <CommandBase.h>
#include "TankDrive.h"
#include "Hand.h"
#include "Poofer.h"
#include "Wrist.h"

class StopAll: public CommandBase {
public:
	StopAll();
	virtual ~StopAll();
	void init();
	void execute();
	bool isFinished();
	void stop();
private:
	bool finished;
	static TankDrive *tankDrive;
	static Hand *hand;
	static Poofer *poofer;
	static Wrist *wrist;
};

#endif /* COMMANDS_STOPALL_H_ */
