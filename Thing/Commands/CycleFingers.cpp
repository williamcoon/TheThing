/*
 * CycleFingers.cpp
 *
 *  Created on: May 14, 2015
 *      Author: williamcoon
 */

#include <CycleFingers.h>
#define SAMPLES 64

Hand* CycleFingers::hand = Hand::getInstance();


CycleFingers::CycleFingers(int minPosition, int maxPosition, int period, int offset, int repeats)
	:	finished(false),
		cycleCount(0),
		period(period),
		offset(offset),
		repeats(repeats),
		index(0),
		minAchieved(false),
		minPosition(minPosition)
{
	//Tell hand to start at minValues
	for(int i=0; i<5;i++){
		hand->fingers[i]->startMotion(minPosition, 30);
	}
	//Create sin wave array
	int valRange = maxPosition - minPosition;
	double middle = valRange/2.0;
	Serial.print("Sine Wave: ");
	for(int i=0; i<SAMPLES; i++){
		sineWave[i] = (uint8_t)(((valRange/2.0)*sin(2*PI*i*(1.0/SAMPLES) - PI/2.0)) + middle + minPosition);
		Serial.print(sineWave[i]);
		Serial.print(", ");
	}
	Serial.println();
	lastIndexUpdate = millis();
}

CycleFingers::~CycleFingers() {
	// TODO Auto-generated destructor stub

}

void CycleFingers::execute(){
	//This command will be called periodically while the command is running
	if(!minAchieved){
		if(hand->isFinished()){
			minAchieved = true;
			lastIndexUpdate = millis();
			Serial.println("Min achieved");
		}
	}else{
		long current = millis();
		if((current-lastIndexUpdate) >= period){
			index++;
			if(index>=SAMPLES){
				index = 0;
				cycleCount++;
				Serial.print("Starting Cycle ");
				Serial.println(cycleCount);
			}
			if(cycleCount <= repeats){
				for(int i=0; i<5; i++){
					int myIndex = index - offset*i;
					if((myIndex < 0) && (cycleCount == 0)){
						//If we are in the first cycle, i.e. cycleCount==0, then don't start
						//this finger until it gets to the first positive index
						continue;
					}else if(myIndex < 0){
						myIndex+=SAMPLES;
					}
					hand->fingers[i]->startMotion(sineWave[myIndex], 90);
				}
			}else{
				stop();
			}
			lastIndexUpdate = current;
		}
	}
}

bool CycleFingers::isFinished(){
	//Return true when the command is done. This function is called before the call
	//to execute, and if it is finished it will be deleted.
	return finished;
}

void CycleFingers::stop(){
	for(int i=0; i<5; i++){
		hand->fingers[i]->startMotion(minPosition, 30);
	}
	finished = true;
}

