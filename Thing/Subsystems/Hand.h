/*
 * Hand.h
 *
 *  Created on: Apr 23, 2015
 *      Author: williamcoon
 */

#ifndef HAND_H_
#define HAND_H_
#include "Finger.h"
#include "PinDefinitions.h"

class Hand {
public:
	static Finger pinky;
	static Finger ring;
	static Finger middle;
	static Finger index;
	static Finger thumb;
	static Finger *fingers[];
	bool isFinished();
	void update();
	static Hand* getInstance();
	void init();
	static void readCounters();
private:
	Hand();
	static Hand *instance;
};

#endif /* HAND_H_ */
