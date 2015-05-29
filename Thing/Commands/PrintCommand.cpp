/*
 * PrintCommand.cpp
 *
 *  Created on: Apr 23, 2015
 *      Author: williamcoon
 */

#include <Commands/PrintCommand.h>

PrintCommand::PrintCommand(String s, int timesToRepeat) {
	// This is where you initialize any variables you declared in the header.
	str = s;
    repeats = timesToRepeat;
    count = 0;
    finished = false;
}

void PrintCommand::init(){

}

void PrintCommand::execute(){
	//This command will be called periodically while the command is running
	if(count<=repeats){
		count++;
		Serial.print(str);
		Serial.print(" ");
		Serial.println(count);
	}else{
		stop();
	}
}

bool PrintCommand::isFinished(){
	//Return true when the command is done. This function is called before the call
	//to execute, and if it is finished it will be deleted.
	return finished;
}

void PrintCommand::stop(){
	//Perform anything you need to do before finishing (stop motors and such)
	finished = true;
}
