/*
 * BackAndForth.h
 *
 *  Created on: May 5, 2015
 *      Author: billcoon
 */

#ifndef COMMANDS_BACKANDFORTH_H_
#define COMMANDS_BACKANDFORTH_H_

#include <CommandBase.h>
#include "Hand.h"
#include "PinDefinitions.h"

class BackAndForth: public CommandBase {
public:
	BackAndForth(int fingerIndex, int speed, int cycles);
	virtual ~BackAndForth();
	void init();
	void execute();
	bool isFinished();
	void stop();
private:
	bool finished;
	static Hand *hand;
	int finger;
	bool direction;
	int speed;
	int count;
	int cycles;
};

#endif /* COMMANDS_BACKANDFORTH_H_ */
