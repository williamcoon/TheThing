/*
 * MoveFinger.h
 *
 *  Created on: Apr 28, 2015
 *      Author: williamcoon
 */

#ifndef COMMANDS_MOVEFINGER_H_
#define COMMANDS_MOVEFINGER_H_

#include <CommandBase.h>
#include "Hand.h"

class MoveFinger: public CommandBase {
public:
	MoveFinger(int fingerIndex, int targetPosition, int speed);
	virtual ~MoveFinger();
	void init();
	void execute();
	bool isFinished();
	void stop();
private:
	bool finished;
	static Hand *hand;
	int fingerIndex;
	int targetPosition;
	int speed;
};

#endif /* COMMANDS_MOVEFINGER_H_ */
