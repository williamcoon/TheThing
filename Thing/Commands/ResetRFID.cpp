/*
 * ResetRFID.cpp
 *
 *  Created on: May 27, 2016
 *      Author: williamcoon
 */

#include <ResetRFID.h>

RFID* ResetRFID::rfid = RFID::getInstance();

ResetRFID::ResetRFID()
	: finished(false)
{

}

ResetRFID::~ResetRFID() {
	// TODO Auto-generated destructor stub
}

void ResetRFID::init(){
	rfid->resetReader();
	finished = true;
}

void ResetRFID::execute(){

}

bool ResetRFID::isFinished(){
	return finished;
}

void ResetRFID::stop(){

}
