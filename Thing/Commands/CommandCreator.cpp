/*
 * CommandCreator.cpp
 *
 *  Created on: Apr 27, 2015
 *      Author: williamcoon
 */

#include <CommandCreator.h>

CommandCenter* CommandCreator::commandCenter = CommandCenter::getInstance();

CommandCreator::CommandCreator() {
	commandHash = StringHashTable();
	commandHash.put("print", printSomething);
	commandHash.put("moveFinger", moveFinger);
}

CommandCreator::~CommandCreator() {
	// TODO Auto-generated destructor stub
}

bool CommandCreator::createCommand(String command, Parameters *params){
	fptr cmdPtr = commandHash.get(command);
	if(cmdPtr==NULL){
		Serial.println("Unrecognized Command");
		return false;
	}else{
		return cmdPtr(params);
	}
}

/*
 * printSomething(String str, int numberOfRepeats)
 */
bool CommandCreator::printSomething(Parameters *params){
	String str;
	int numberOfRepeats;
	if(params->getString(0, &str)&&params->getInt(1, &numberOfRepeats)){
		CommandBase *command = new PrintCommand(str, numberOfRepeats);
		commandCenter->addCommand(command);
		delete params;
		params = NULL;
		return true;
	}else{
		return false;
	}
}

/*
 * moveFinger(int fingerIndex, int targetPosition, int speed)
 */
bool CommandCreator::moveFinger(Parameters *params){
	int fingerIndex;
	int targetPosition;
	int speed;
	if(params->getInt(0, &fingerIndex)&&params->getInt(1, &targetPosition)&&params->getInt(2, &speed)){
		CommandBase *command = new MoveFinger(fingerIndex, targetPosition, speed);
		commandCenter->addCommand(command);
		delete params;
		params = NULL;
		return true;
	}else{
		return false;
	}
}


