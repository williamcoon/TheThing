/*
 * CommandCenter.cpp
 *
 *  Created on: Apr 23, 2015
 *      Author: williamcoon
 */

#include <CommandCenter.h>

CommandCenter::CommandCenter() {
	// TODO Create list of commands for parallel execution
	currentCommand = NULL;
}

CommandCenter::~CommandCenter() {
	while(!commands.isEmpty()){
		CommandBase *cmd = commands.pop();
		delete cmd;
		cmd = NULL;
	}
}

void CommandCenter::addCommand(CommandBase *command){
	//Put the command in the back of the queue
	commands.push(command);
}

void CommandCenter::update(){
	if(currentCommand == NULL){
		//Check if there is a new command on the queue
		if(!commands.isEmpty()){
			currentCommand = commands.pop();
		}
	}
	if(currentCommand!= NULL){
		if(currentCommand->isFinished()){
			//If the command is finished, set current to NULL and delete it
			delete currentCommand;
			currentCommand = NULL;
		}else{
			currentCommand->execute();
		}
	}
}
