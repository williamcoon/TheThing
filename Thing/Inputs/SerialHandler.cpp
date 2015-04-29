/*
 * SerialHandler.cpp
 *
 *  Created on: Apr 24, 2015
 *      Author: williamcoon
 */

#include <SerialHandler.h>

SerialHandler::SerialHandler(HardwareSerial *s)
	:	MAX_SIZE(50),
		commandCreator()
{
	// TODO Auto-generated constructor stub
	serial = s;
	buffer = "";
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

void SerialHandler::parseCommand(){
	int startIndex = buffer.indexOf("<"); // Find the beginning of the new command
	if(startIndex < 0){
		//No Commands are available
		return;
	}
	int endIndex = buffer.indexOf(">"); //Find the end of the new command
	if(endIndex < 0){
		//Command is incomplete
		return;
	}
	String newCommand = buffer.substring(startIndex+1, endIndex);
	buffer.remove(0, endIndex+1);
	int paramStart = newCommand.indexOf("(");
	int paramEnd = newCommand.indexOf(")");
	Parameters *params = NULL;
	if(paramStart>0){
		//Get parameters
		String paramString = newCommand.substring(paramStart+1, paramEnd);
		newCommand.remove(paramStart);
		params = getParameters(paramString);
	}
	if(!commandCreator.createCommand(newCommand, params)){
		serial->print("Bad Command: ");
		serial->println(newCommand);
		delete params;
		params = NULL;
	}
}

Parameters* SerialHandler::getParameters(String paramString){
	Parameters *params = new Parameters();
	int commaIndex = paramString.indexOf(",");
	int paramCount = 0;
	do{
		String parameter = "";
		commaIndex = paramString.indexOf(",");
		if(commaIndex>0){
			parameter = paramString.substring(0,commaIndex);
			paramString.remove(0, commaIndex+1);
		}else{
			parameter = paramString;
		}
		params->setValue(paramCount, parameter);
		paramCount++;
	}while(commaIndex>=0);
	return params;
}

int freeRam () {
  extern int __heap_start, *__brkval;
  int v;
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}

void SerialHandler::update(){
	buffer += readSerial();
	if(buffer.length() > 0){
		serial->print("Free RAM: ");
		serial->println(freeRam());
		parseCommand();
	}
}



