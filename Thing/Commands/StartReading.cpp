/*
 * StartReading.cpp
 *
 *  Created on: Jun 1, 2015
 *      Author: williamcoon
 */

#include <StartReading.h>

RFID* StartReading::rfid = RFID::getInstance();

StartReading::StartReading() : finished(false){
	// TODO Auto-generated constructor stub

}

StartReading::~StartReading() {
	// TODO Auto-generated destructor stub
}

void StartReading::init(){
	rfid->startReading();
	stop();
}

void StartReading::execute(){

}

bool StartReading::isFinished(){
	return finished;
}

void StartReading::stop(){
	finished = true;
}
