/*
 * Hand.cpp
 *
 *  Created on: Apr 23, 2015
 *      Author: williamcoon
 */

#include <Hand.h>

Hand* Hand::instance = NULL;

Hand::Hand()
	: pinky(PINKY_CONTROL_PIN, PINKY_COUNT_PIN),
	  ring(RING_CONTROL_PIN, RING_COUNT_PIN),
	  middle(MIDDLE_CONTROL_PIN, MIDDLE_COUNT_PIN),
	  index(INDEX_CONTROL_PIN, INDEX_COUNT_PIN),
	  thumb(THUMB_CONTROL_PIN, THUMB_COUNT_PIN)
{
	fingers[0] = &pinky;
	fingers[1] = &ring;
	fingers[2] = &middle;
	fingers[3] = &index;
	fingers[4] = &thumb;
}

void Hand::init(){
	for(int i=0; i<5; i++){
		fingers[i]->init();
	}
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
	for(int i=0; i<5; i++){
		fingers[i]->update();
	}
}




