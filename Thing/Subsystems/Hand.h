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
	Finger pinky;
	Finger ring;
	Finger middle;
	Finger index;
	Finger thumb;
	bool isFinished();
	void update();
	static Hand* getInstance();
private:
	Finger *fingers[5];
	Hand();
	static Hand *instance;
};

#endif /* HAND_H_ */
