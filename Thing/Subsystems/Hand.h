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
	static Hand* getInstance();
	static void handleInterrupt0();
	static void handleInterrupt1();
	static void handleInterrupt2();
	static void handleInterrupt3();
	static void handleInterrupt4();
	void init();
	bool isFinished();
	void update();
private:
	Hand();
	static Hand *instance;
};

#endif /* HAND_H_ */
