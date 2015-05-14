/*
 * Hand.cpp
 *
 *  Created on: Apr 23, 2015
 *      Author: williamcoon
 */

#include <Hand.h>

Hand* Hand::instance = NULL;
Finger Hand::pinky(PINKY_CONTROL_PIN);
Finger Hand::ring(RING_CONTROL_PIN);
Finger Hand::middle(MIDDLE_CONTROL_PIN);
Finger Hand::index(INDEX_CONTROL_PIN);
Finger Hand::thumb(THUMB_CONTROL_PIN);
Finger* Hand::fingers[] = {&pinky, &ring, &middle, &index, &thumb};

Hand::Hand()
{

}

void Hand::init(){
	for(int i=0; i<5; i++){
		fingers[i]->init();
	}

	/*
	 * Set all of the sensor pins to inputs w/ pullup resistors
	 */

	pinMode(PINKY_COUNT_PIN, INPUT_PULLUP);
	pinMode(RING_COUNT_PIN, INPUT_PULLUP);
	pinMode(MIDDLE_COUNT_PIN, INPUT_PULLUP);
	pinMode(INDEX_COUNT_PIN, INPUT_PULLUP);
	pinMode(THUMB_COUNT_PIN, INPUT_PULLUP);

	pinMode(PINKY_REED_PIN, INPUT_PULLUP);
	pinMode(RING_REED_PIN, INPUT_PULLUP);
	pinMode(MIDDLE_REED_PIN, INPUT_PULLUP);
	pinMode(INDEX_REED_PIN, INPUT_PULLUP);
	pinMode(THUMB_REED_PIN, INPUT_PULLUP);

	/*
	 * Attach external interrupts for rotary encoders
	 */
	attachInterrupt(0, &Hand::handleInterrupt0, CHANGE);
	attachInterrupt(1, &Hand::handleInterrupt1, CHANGE);
	attachInterrupt(2, &Hand::handleInterrupt2, CHANGE);
	attachInterrupt(3, &Hand::handleInterrupt3, CHANGE);
	attachInterrupt(4, &Hand::handleInterrupt4, CHANGE);
}

Hand* Hand::getInstance(){
	if(!instance)
		instance = new Hand();
	return instance;
}

bool Hand::isFinished(){
	//Returns true if all fingers are done with their motions
	for(int i=0; i<5; i++){
		if(!(fingers[i]->isFinished())){
			return false;
		}
	}
	return true;
}

void Hand::update(){
	// Update all of the fingers
	for(int i=0; i<5; i++){
		fingers[i]->update();
	}
}

void Hand::handleInterrupt0(){
	//Interrupt on pin 2
	fingers[0]->incrementCount();
}

void Hand::handleInterrupt1(){
	//Interrupt on pin 3
	fingers[1]->incrementCount();
}

void Hand::handleInterrupt2(){
	//Interrupt on pin 21
	fingers[2]->incrementCount();
}

void Hand::handleInterrupt3(){
	//Interrupt on pin 20
	fingers[3]->incrementCount();
}

void Hand::handleInterrupt4(){
	//Interrupt on pin 19
	fingers[4]->incrementCount();
}



