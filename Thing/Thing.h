// Only modify this file to include
// - function definitions (prototypes)
// - include files
// - extern variable definitions
// In the appropriate section

#ifndef Thing_H_
#define Thing_H_

#include "Arduino.h"
#include <avr/wdt.h>
#include "PinDefinitions.h"
#include "CommandCenter.h"
#include "CommandCreator.h"
#include "SerialHandler.h"
#include "RFID.h"
#include "Hand.h"
#include "Wrist.h"
#include "Ejector.h"
#include "Poofer.h"
#include "LedButton.h"
#include "Joystick.h"
#include "TankDrive.h"

//end of add your includes here
#ifdef __cplusplus
extern "C" {
#endif
void loop();
void setup();
#ifdef __cplusplus
} // extern "C"
#endif

//add your function definitions for the project Thing here

class Thing{
public:
	Thing();
	void init();
	void checkSerial();
	void checkRFID();
	void updateExecution();
	void checkButtonStates();
	void stopAllSubsystems();
	void driveWithJoystick();
private:
	RFID *rfid;
	SerialHandler *serialHandler;
	CommandCenter *commandCenter;
	Hand *hand;
	TankDrive *tankDrive;
	Wrist *wrist;
	Ejector *ejector;
	Poofer *poofer;
	CommandCreator *commandCreator;
	LedButton *startButton;
	LedButton *stopButton;
	Joystick *joyStick;
	bool executingRFID;
	unsigned long lastRFIDTime;
	static const unsigned long RFID_TIMEOUT;
}thing;


//Do not add code below this line
#endif /* Thing_H_ */
