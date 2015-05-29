/*
 * MoveWrist.h
 *
 *  Created on: May 29, 2015
 *      Author: williamcoon
 */

#ifndef COMMANDS_MOVEWRIST_H_
#define COMMANDS_MOVEWRIST_H_

#include <CommandBase.h>
#include "Wrist.h"
#include "Arduino.h"
#include "PinDefinitions.h"

class MoveWrist: public CommandBase {
public:
	MoveWrist(int speed, bool direction, unsigned long time);
	virtual ~MoveWrist();
	void init();
	void execute();
	bool isFinished();
	void stop();
private:
	bool finished;
	int speed;
	bool direction;
	unsigned long time;
	unsigned long startTime;
	static Wrist *wrist;
};

#endif /* COMMANDS_MOVEWRIST_H_ */
