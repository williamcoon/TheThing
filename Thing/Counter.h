/*
 * Counter.h
 *
 *  Created on: Apr 22, 2015
 *      Author: williamcoon
 */

#ifndef COUNTER_H_
#define COUNTER_H_
#define FWD true
#define REV false

#include "Arduino.h"

class Counter {

public:
	Counter(int);
	virtual ~Counter();
	int getCount();
	void update(bool);
private:
	int countPin;
	int count;
	bool lastPinState;
};

#endif /* COUNTER_H_ */
