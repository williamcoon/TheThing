/*
 * WiggleFingers.cpp
 *
 *  Created on: May 22, 2015
 *      Author: williamcoon
 */

#include <WiggleFingers.h>

Hand* WiggleFingers::hand = Hand::getInstance();


WiggleFingers::WiggleFingers(int minPosition, int maxPosition, int delay, int speed, int repeats)
	:	finished(false),
		cycleCount(0),
		delay(delay),
		speed(speed),
		repeats(repeats),
		minAchieved(false),
		direction(FWD),
		minPosition(minPosition),
		maxPosition(maxPosition),
		cycleStart(0)
{
	//Tell hand to start at minValues
	for(int i=0; i<5;i++){
		hand->fingers[i]->startMotion(minPosition, speed);
		state[i] = REV;
	}
}

WiggleFingers::~WiggleFingers() {
	// TODO Auto-generated destructor stub

}

void WiggleFingers::execute(){
	//This command will be called periodically while the command is running
	if(!minAchieved){
		if(hand->isFinished()){
			minAchieved = true;
		}
	}else if(cycleCount < repeats){
		unsigned long current = millis();
		for(int i=0; i<5; i++){
			if(state[i] != direction){
				if((current-cycleStart)>=(delay*i)){
					if(direction == FWD){
						hand->fingers[i]->startMotion(maxPosition, speed);
					}else{
						hand->fingers[i]->startMotion(minPosition, speed);
					}
					state[i] = direction;
				}
			}
		}
		if(hand->fingers[0]->isFinished()){
			if(direction == REV){
				cycleCount++;
			}
			direction = !direction;
			cycleStart = current;
		}
	}else{
		stop();
	}
}

bool WiggleFingers::isFinished(){
	//Return true when the command is done. This function is called before the call
	//to execute, and if it is finished it will be deleted.
	return finished;
}

void WiggleFingers::stop(){
	finished = true;
}

