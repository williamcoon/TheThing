/*
 * MoveHand.cpp
 *
 *  Created on: Apr 28, 2015
 *      Author: williamcoon
 */

#include "MoveHand.h"

Hand* MoveHand::hand = Hand::getInstance();

MoveHand::MoveHand(int pinkyPosition,
					int ringPosition,
					int middlePosition,
					int indexPosition,
					int thumbPosition,
					unsigned long delay)
	: finished(false),
	  pinkyP(pinkyPosition),
	  ringP(ringPosition),
	  middleP(middlePosition),
	  indexP(indexPosition),
	  thumbP(thumbPosition),
	  delay(delay),
	  startTime(0)
{

}

MoveHand::~MoveHand() {
	// TODO Auto-generated destructor stub
}

void MoveHand::init(){
	hand->pinky.startMotion(pinkyP);
	hand->ring.startMotion(ringP);
	hand->middle.startMotion(middleP);
	hand->index.startMotion(indexP);
	hand->thumb.startMotion(thumbP);
	startTime = millis();
}

void MoveHand::execute(){
	//This command will be called periodically while the command is running
	if(hand->isFinished()){
		if((millis()-startTime) >= delay){
			finished = true;
		}
	}
}

bool MoveHand::isFinished(){
	//Return true when the command is done. This function is called before the call
	//to execute, and if it is finished it will be deleted.
	return finished;
}

void MoveHand::stop(){
	finished = true;
}

