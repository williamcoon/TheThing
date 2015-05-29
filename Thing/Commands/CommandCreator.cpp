/*
 * CommandCreator.cpp
 *
 *  Created on: Apr 27, 2015
 *      Author: williamcoon
 */

#include <CommandCreator.h>

CommandCenter* CommandCreator::commandCenter = CommandCenter::getInstance();
CommandCreator* CommandCreator::instance = NULL;

CommandCreator::CommandCreator() {
	commandHash = StringHashTable();
	//Serial commands
	commandHash.put("print", printSomething);
	commandHash.put("moveFinger", moveFinger);
	commandHash.put("moveHand", moveHand);
	commandHash.put("drive", drive);
	commandHash.put("bnf", backAndForth);
	commandHash.put("calibrate", calibrateVictor);
	commandHash.put("findHome", findHome);
	commandHash.put("wiggle", wiggleFingers);
	commandHash.put("testParallel", testParallel);

	//RFID tags
	commandHash.put("7C0055F126FE", rfidDrive1);
	commandHash.put("2500ABCCBFFD", rfidDrive2);
	commandHash.put("2500AC101188", rfidDrive3);
	commandHash.put("2500AC27E749", smallPoof);
}

CommandCreator::~CommandCreator() {
	// TODO Auto-generated destructor stub
}

CommandCreator* CommandCreator::getInstance(){
	if(!instance)
		instance = new CommandCreator();
	return instance;
}

bool CommandCreator::createCommand(String command, Parameters *params){
	fptr cmdPtr = commandHash.get(command);
	if(cmdPtr==NULL){
		Serial.println("Unrecognized Command");
		return false;
	}else{
		bool success = cmdPtr(params);
		delete params;
		params = NULL;
		return success;
	}
}

/*
 * printSomething(String str, int numberOfRepeats)
 */
bool CommandCreator::printSomething(Parameters *params){
	String str;
	int numberOfRepeats;
	if(!params->getString(0, &str)){
		return false;
	}else if(!params->getInt(1, &numberOfRepeats)){
		return false;
	}else{
		CommandBase *command = new PrintCommand(str, numberOfRepeats);
		commandCenter->addCommand(command);
		return true;
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
	Serial.println("RFID Drive 1");
	CommandBase *command = new Drive(100, 100, 3);
	commandCenter->addCommand(command);
	CommandBase *ejectCommand = new EjectBlock();
	commandCenter->addCommand(ejectCommand);
	return true;
}

/*
 * rfidDrive2(NULL)
 * No Parameters, this responds to an rfid tag and drives reverse full speed for 3 seconds
 */
bool CommandCreator::rfidDrive2(Parameters *params){
	Serial.println("RFID Drive 2");
	CommandBase *command = new Drive(-100, -100, 3);
	commandCenter->addCommand(command);
	CommandBase *ejectCommand = new EjectBlock();
	commandCenter->addCommand(ejectCommand);
	return true;
}

/*
 * rfidDrive3(NULL)
 * No Parameters, this responds to an rfid tag and spins full speed for 3 seconds
 */
bool CommandCreator::rfidDrive3(Parameters *params){
	Serial.println("RFID Drive 3");
	CommandBase *command = new Drive(-100, 100, 3);
	commandCenter->addCommand(command);
	CommandBase *ejectCommand = new EjectBlock();
	commandCenter->addCommand(ejectCommand);
	return true;
}

/*
 * calibrateVictor(int pin)
 * pin: the control pin for the victor
 * This command bypasses the command center and just executes here. It shouldn't
 * be used during normal operation and will screw up any currently running commands.
 * Before running this command, power up the victor and hold the "Cal" button
 * down until it starts alternating RED/GREEN. Release the button after you see
 * "Calibration Complete" printed to the console. The victor should then blink
 * green to confirm successful calibration.
 */
bool CommandCreator::calibrateVictor(Parameters *params){
	int pin;
	if(params->getInt(0,&pin)){
		Victor victor(pin);
		victor.startServo();
		Serial.println("Calibrating...");
		victor.calibrate();
		Serial.println("Calibration Complete");
		return true;
	}else{
		return false;
	}
}

bool CommandCreator::backAndForth(Parameters *params){
	int fingerIndex;
	int speed;
	int cycles;
	if(params->getInt(0, &fingerIndex)&&params->getInt(1, &speed)&&params->getInt(2, &cycles)){
		CommandBase *command = new BackAndForth(fingerIndex, speed, cycles);
		commandCenter->addCommand(command);
		return true;
	}else{
		return false;
	}
}

bool CommandCreator::findHome(Parameters *params){
	int speed;
	if(params->getInt(0, &speed)){
		CommandBase *command = new FindHome(speed);
		commandCenter->addCommand(command);
		return true;
	}else{
		return false;
	}
}

/*
 * wiggleFingers(int minPosition, int maxPosition, int fingerDelay, int cycleDelay, int speed, int repeats)
 */
bool CommandCreator::wiggleFingers(Parameters *params){
	int minPosition;
	int maxPosition;
	int fingerDelay;
	int cycleDelay;
	int speed;
	int repeats;
	if(params->getInt(0, &minPosition)
			&&params->getInt(1, &maxPosition)
			&&params->getInt(2, &fingerDelay)
			&&params->getInt(3, &cycleDelay)
			&&params->getInt(4, &speed)
			&&params->getInt(5, &repeats))
	{
		CommandBase *command = new WiggleFingers(minPosition, maxPosition, fingerDelay, cycleDelay, speed, repeats);
		commandCenter->addCommand(command);
		return true;
	}else{
		return false;
	}
}

bool CommandCreator::testParallel(Parameters *params){
	CommandBase *command1 = new PrintCommand("Command 1 - ", 2);
	command1->setParallel(true);
	CommandBase *command2 = new PrintCommand("Command 2 - ", 4);
	command2->setParallel(true);
	CommandBase *command3 = new PrintCommand("Command 3 - ", 3);
	CommandBase *command4 = new PrintCommand("Command 4 - ", 5);
	command4->setParallel(true);
	CommandBase *command5 = new PrintCommand("Command 5 - ", 4);
	command5->setParallel(true);
	CommandBase *command6 = new PrintCommand("Command 6 - ", 3);
	commandCenter->addCommand(command1);
	commandCenter->addCommand(command2);
	commandCenter->addCommand(command3);
	commandCenter->addCommand(command4);
	commandCenter->addCommand(command5);
	commandCenter->addCommand(command6);
	return true;
}

bool CommandCreator::smallPoof(Parameters *params){
	CommandBase *command = new Poof(100UL);
	commandCenter->addCommand(command);
	CommandBase *ejectCommand = new EjectBlock();
	commandCenter->addCommand(ejectCommand);
	return true;
}

