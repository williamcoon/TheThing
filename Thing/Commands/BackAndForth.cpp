/*
 * BackAndForth.cpp
 *
 *  Created on: May 5, 2015
 *      Author: billcoon
 */

#include <BackAndForth.h>

Hand* BackAndForth::hand = Hand::getInstance();

BackAndForth::BackAndForth(int fingerIndex, int speed, int cycles)
	:	finished(false),
		finger(fingerIndex),
		direction(REV),
		speed(speed),
		count(0),
		cycles(cycles)
{
	hand->fingers[fingerIndex]->startMotion(0, speed);
}

BackAndForth::~BackAndForth() {
	// TODO Auto-generated destructor stub
}

void BackAndForth::execute(){
	//This command will be called periodically while the command is running
	if(count < cycles){
		if(hand->isFinished()){
			if(direction==REV){
				direction = FWD;
				hand->fingers[finger]->startMotion(24, speed);
			}else{
				direction = REV;
				hand->fingers[finger]->startMotion(0, speed);
				count++;
			}
		}
	}else{
		finished = true;
	}
}

bool BackAndForth::isFinished(){
	//Return true when the command is done. This function is called before the call
	//to execute, and if it is finished it will be deleted.
	return finished;
}

void BackAndForth::stop(){
	finished = true;
}
