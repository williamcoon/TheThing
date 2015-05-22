/*
 * WiggleFingers.h
 *
 *  Created on: May 22, 2015
 *      Author: williamcoon
 */

#ifndef COMMANDS_WIGGLEFINGERS_H_
#define COMMANDS_WIGGLEFINGERS_H_

#include <CommandBase.h>
#include "Hand.h"
#include "PinDefinitions.h"

class WiggleFingers: public CommandBase {
public:
	WiggleFingers(int minPosition, int maxPosition, int rate, int delay, int repeats);
	virtual ~WiggleFingers();
	void execute();
	bool isFinished();
	void stop();
private:
	bool finished;
	static Hand *hand;
	int cycleCount;
	int delay;
	int speed;
	int repeats;
	bool minAchieved;
	bool direction;
	bool state[5];
	int minPosition;
	int maxPosition;
	unsigned long cycleStart;
};

#endif /* COMMANDS_WIGGLEFINGERS_H_ */
