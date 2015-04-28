/*
 * MoveHand.cpp
 *
 *  Created on: Apr 28, 2015
 *      Author: williamcoon
 */

#include <MoveHand.h>

Hand* MoveHand::hand = Hand::getInstance();

MoveHand::MoveHand(int pinkyPosition,
					int ringPosition,
					int middlePosition,
					int indexPosition,
					int thumbPosition,
					int speed)
{
	finished = false;
	hand->pinky.startMotion(pinkyPosition, speed);
	hand->ring.startMotion(ringPosition, speed);
	hand->middle.startMotion(middlePosition, speed);
	hand->index.startMotion(indexPosition, speed);
	hand->thumb.startMotion(thumbPosition, speed);
}

MoveHand::~MoveHand() {
	// TODO Auto-generated destructor stub
}

void MoveHand::execute(){
	//This command will be called periodically while the command is running
	if(hand->isFinished()){
		finished = true;
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

