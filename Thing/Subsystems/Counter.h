/*
 * Counter.h
 *
 *  Created on: Apr 22, 2015
 *      Author: williamcoon
 */

#ifndef COUNTER_H_
#define COUNTER_H_

#include "Arduino.h"
#include "PinDefinitions.h"

class Counter {

public:
	Counter(int);
	int getCount();
	void update(bool);
private:
	int countPin;
	int count;
	bool lastPinState;
};

#endif /* COUNTER_H_ */
