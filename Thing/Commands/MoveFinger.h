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
	void execute();
	bool isFinished();
	void stop();
private:
	int m_fingerIndex;
	int m_targetPosition;
	int m_speed;
	bool finished;
	static Hand *hand;
};

#endif /* COMMANDS_MOVEFINGER_H_ */
