/*
 * Hand.cpp
 *
 *  Created on: Apr 23, 2015
 *      Author: williamcoon
 */

#include <Hand.h>

Hand::Hand()
	: pinky(PINKY_PWM_PIN, PINKY_COUNT_PIN),
	  ring(RING_PWM_PIN, RING_COUNT_PIN),
	  middle(MIDDLE_PWM_PIN, MIDDLE_COUNT_PIN),
	  index(INDEX_PWM_PIN, INDEX_COUNT_PIN),
	  thumb(THUMB_PWM_PIN, THUMB_COUNT_PIN)
{
	fingers[0] = &pinky;
	fingers[1] = &ring;
	fingers[2] = &middle;
	fingers[3] = &index;
	fingers[4] = &thumb;
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
	for(int i=0; i<5; i++){
		fingers[i]->update();
	}
}



