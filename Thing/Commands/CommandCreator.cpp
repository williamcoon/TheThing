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
	commandHash.put("moveHand", moveHand);
	commandHash.put("drive", drive);
	commandHash.put("7C0055F126FE", rfidDrive1);
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

/*
 * moveHand(int pinkyPosition, int ringPosition, int middlePosition, int indexPosition, int thumbPosition, int speed)
 */
bool CommandCreator::moveHand(Parameters *params){
	int pinkyPosition;
	int ringPosition;
	int middlePosition;
	int indexPosition;
	int thumbPosition;
	int speed;
	if(params->getInt(0, &pinkyPosition)
			&&params->getInt(1, &ringPosition)
			&&params->getInt(2, &middlePosition)
			&&params->getInt(3, &indexPosition)
			&&params->getInt(4, &thumbPosition)
			&&params->getInt(5, &speed))
	{
		CommandBase *command = new MoveHand(pinkyPosition,
											ringPosition,
											middlePosition,
											indexPosition,
											thumbPosition,
											speed);
		commandCenter->addCommand(command);
		delete params;
		params = NULL;
		return true;
	}else{
		return false;
	}
}

/*
 * drive(int leftSpeed, int rightSpeed, int driveTime)
 * leftSpeed: Integer from -100 to 100
 * rightSpeed: Integer from -100 to 100
 * driveTime: Seconds to drive before stopping. Use -1 to set indefinitely.
 */
bool CommandCreator::drive(Parameters *params){
	int leftSpeed;
	int rightSpeed;
	int driveTime;
	if(params->getInt(0, &leftSpeed)&&params->getInt(1, &rightSpeed)&&params->getInt(2, &driveTime)){
		CommandBase *command = new Drive(leftSpeed, rightSpeed, driveTime);
		commandCenter->addCommand(command);
		delete params;
		params = NULL;
		return true;
	}else{
		return false;
	}
}

/*
 * rfidDrive1(NULL)
 * No Parameters, this responds to an rfid tag and drives forward full speed for 3 seconds
 */
bool CommandCreator::rfidDrive1(Parameters *params){
	CommandBase *command = new Drive(100, 100, 3);
	commandCenter->addCommand(command);
	return true;
}
