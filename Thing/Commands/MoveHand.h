/*
 * MoveHand.h
 *
 *  Created on: Apr 28, 2015
 *      Author: williamcoon
 */

#ifndef COMMANDS_MOVEHAND_H_
#define COMMANDS_MOVEHAND_H_

#include <CommandBase.h>
#include "Hand.h"

class MoveHand: public CommandBase {
public:
	MoveHand(int pinkyPosition,
			int ringPosition,
			int middlePosition,
			int indexPosition,
			int thumbPosition,
			int speed);
	virtual ~MoveHand();
	void init();
	void execute();
	bool isFinished();
	void stop();
private:
	bool finished;
	static Hand* hand;
	int pinkyP;
	int ringP;
	int middleP;
	int indexP;
	int thumbP;
	int speed;
};

#endif /* COMMANDS_MOVEHAND_H_ */
