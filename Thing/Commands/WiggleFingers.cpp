/*
 * WiggleFingers.cpp
 *
 *  Created on: May 22, 2015
 *      Author: williamcoon
 */

#include "WiggleFingers.h"

Hand* WiggleFingers::hand = Hand::getInstance();


WiggleFingers::WiggleFingers(int minPosition, int maxPosition, int thumbMin, int thumbMax, int fingerDelay, int cycleDelay, int repeats)
	:	finished(false),
		fingerDelay(fingerDelay),
		repeats(repeats),
		minAchieved(false),
		direction(FWD),
		minPosition(minPosition),
		maxPosition(maxPosition),
		thumbMin(thumbMin),
		thumbMax(thumbMax),
		cycleStart(0),
		cycleDelay(cycleDelay)
{

}

WiggleFingers::~WiggleFingers() {
	// TODO Auto-generated destructor stub

}

void WiggleFingers::init(){
	//Tell hand to start at minValues
	for(int i=0; i<5;i++){
		hand->fingers[i]->startMotion(i==4?thumbMin:minPosition); //TODO:Handle difference in thumb better
		state[i] = REV;
		cycleCount[i] = 0;
	}
}

void WiggleFingers::execute(){
	//This command will be called periodically while the command is running
	if(!minAchieved){
		if(hand->isFinished()){
			minAchieved = true;
			cycleStart = millis();
		}
	}else{
		unsigned long current = millis();
		for(int i=0; i<5; i++){
			if((state[i] == REV) && (cycleCount[i]<repeats)){
				if((current-cycleStart)>=(unsigned long)(fingerDelay*i + cycleDelay*cycleCount[i])){
					hand->fingers[i]->startMotion(i==4?thumbMax:maxPosition);
					state[i] = FWD;
				}
			}
			if((hand->fingers[i]->isFinished()) && (state[i]==FWD)){
				hand->fingers[i]->startMotion(i==4?thumbMin:minPosition);
				state[i] = REV;
				cycleCount[i]++;
			}
		}
	}
	bool done = true;
	for(int i=0; i<5;i++){
		if(cycleCount[i]<repeats){
			done = false;
		}
	}
	if(done){
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

