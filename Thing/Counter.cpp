/*
 * Counter.cpp
 *
 *  Created on: Apr 22, 2015
 *      Author: williamcoon
 *
 *  The Counter class is responsible for reading the Hall effect sensors and
 *  counting the number of magnets passing by.
 */

#include <Counter.h>

Counter::Counter(int pin) {
	countPin = pin; //Arduino pin of the Hall effect sensor
	pinMode(countPin, INPUT);
	count = 0;
	lastPinState = digitalRead(countPin);
}

Counter::~Counter() {
	// TODO Auto-generated destructor stub
}

int Counter::getCount(){
	return count;
}

void Counter::update(bool direction){
	int inc = direction ? 1:-1; //Increment or decrement based on fwd/rev direction
	bool pinState = digitalRead(countPin);
	if(pinState!=lastPinState){
		//If the state has changed, the next magnet is in front of the sensor
		//so change the count accordingly
		lastPinState = pinState;
		count+=inc;
	}
}
