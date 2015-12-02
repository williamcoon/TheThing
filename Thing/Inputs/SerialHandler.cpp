/*
 * SerialHandler.cpp
 *
 *  Created on: Apr 24, 2015
 *      Author: williamcoon
 */

#include "SerialHandler.h"

const char* SerialHandler::NO_COMMAND = "NOCOMMAND";
const char* COMMAND_START = "<";
const char* COMMAND_END = ">";


SerialHandler::SerialHandler(HardwareSerial *s, unsigned long baud)
	:	MAX_SIZE(50),
		baud(baud)
{
	// TODO Auto-generated constructor stub
	serial = s;
	buffer = "";
}

void SerialHandler::init(){
	serial->begin(baud);
}

/*
 * readSerial - Read and return anything available on the serial line
 * up to MAX_SIZE
 */
String SerialHandler::readSerial(){
	String string = "";
	unsigned int size = 0;
	char newChar = 0;
	while(size<MAX_SIZE&&((serial->available())>0)){
		newChar = serial->read();
		string += newChar;
		size++;
	}
	return string;
}

/*
 * parseCommand(String *command, Parameters *params)
 * Parse the current buffer to get any new commands and parameters.
 * We are looking for a command of the format <commandName(param1,param2, ...)>
 */
String SerialHandler::parseCommand(){
	int startIndex = buffer.indexOf(COMMAND_START); // Find the beginning of the new command
	if(startIndex < 0){
		//No Commands are available
		return NO_COMMAND;
	}
	int endIndex = buffer.indexOf(COMMAND_END); //Find the end of the new command
	if(endIndex < 0){
		//Command is incomplete
		return NO_COMMAND;
	}
	String newCommand = buffer.substring(startIndex+1, endIndex);
	buffer.remove(0, endIndex+1);
	return newCommand;
}


int freeRam () {
  extern int __heap_start, *__brkval;
  int v;
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}

String SerialHandler::checkForCommand(){
	buffer += readSerial();
	if(buffer.length() > 0){
		String cmd = parseCommand();
		if(cmd.equals("")){
			Serial.print("Free RAM: ");
			Serial.println(freeRam());
			return NO_COMMAND;
		}else
			return cmd;
	}else{
		return NO_COMMAND;
	}
}



