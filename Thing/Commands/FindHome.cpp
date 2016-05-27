/*
 * FindHome.cpp
 *
 *  Created on: May 14, 2015
 *      Author: williamcoon
 */

#include "FindHome.h"

Hand* FindHome::hand = Hand::getInstance();

FindHome::FindHome(int speed)
	: speed(speed)
{
	finished = false;
}

FindHome::~FindHome() {
	// TODO Auto-generated destructor stub
}

void FindHome::init(){
	if(speed<0){
		hand->setHome();
	}else{
		for(int i=0; i<5; i++){
			hand->fingers[i]->startMotion(100);
		}
	}
}

void FindHome::execute(){
	//This command will be called periodically while the command is running
	finished = true;
	for(int i=0; i<5; i++){
		if(hand->fingers[i]->isFinished()){
			hand->fingers[i]->stopMotion();
			hand->fingers[i]->setHomePosition();
		}else{
				finished = false;
		}
	}
}

bool FindHome::isFinished(){
	//Return true when the command is done. This function is called before the call
	//to execute, and if it is finished it will be deleted.
	return finished;
}

void FindHome::stop(){
	finished = true;
}

