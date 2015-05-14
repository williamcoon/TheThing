/*
 * CycleFingers.h
 *
 *  Created on: May 14, 2015
 *      Author: williamcoon
 */

#ifndef COMMANDS_CYCLEFINGERS_H_
#define COMMANDS_CYCLEFINGERS_H_

#include <CommandBase.h>
#include "Hand.h"

class CycleFingers: public CommandBase {
public:
	CycleFingers(int minPosition, int maxPosition, int rate, int delay, int repeats);
	virtual ~CycleFingers();
	void execute();
	bool isFinished();
	void stop();
private:
	bool finished;
	static Hand *hand;
	int cycleCount;
	int period;
	int offset;
	int repeats;
	int index;
	bool minAchieved;
	int minPosition;
	uint8_t sineWave[64];
	long lastIndexUpdate;
};

#endif /* COMMANDS_CYCLEFINGERS_H_ */
