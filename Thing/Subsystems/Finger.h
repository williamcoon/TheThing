/*
 * Finger.h
 *
 *  Created on: Apr 22, 2015
 *      Author: williamcoon
 */

#ifndef FINGER_H_
#define FINGER_H_

#include "Counter.h"
#define CENTER_PWM 127
#define MAX_PWM 127


class Finger {
public:
	Finger(int pwmPin, int counterPin);
	void startMotion(int targetPosition, int motionSpeed);
	void update();
	bool isFinished();
private:
	Counter counter;
	int pwmPin;
	bool direction;
	int currentPos;
	int targetPos;
	bool finished;
	void stopMotion();
};

#endif /* FINGER_H_ */
