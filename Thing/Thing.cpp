#include "Thing.h"
#include "PinDefinitions.h"
#include "CommandCenter.h"
#include "SerialHandler.h"
#include "RFID.h"
#include "Hand.h"
#include "Wrist.h"
#include "Ejector.h"
#include "Poofer.h"

RFID *rfid = RFID::getInstance();
CommandCenter *commandCenter = CommandCenter::getInstance();
Hand *hand = Hand::getInstance();
TankDrive *tankDrive = TankDrive::getInstance();
Wrist *wrist = Wrist::getInstance();
Ejector *ejector = Ejector::getInstance();
Poofer *poofer = Poofer::getInstance();
SerialHandler *serialHandler = new SerialHandler(&Serial1);


//The setup function is called once at startup of the sketch
void setup()
{
	pinMode(STATUS_PIN, OUTPUT);
	rfid->init();
	serialHandler->init();
	hand->init();
	tankDrive->init();
	wrist->init();
	ejector->init();
	poofer->init();
}

long count = 0;

// The loop function is called in an endless loop
void loop()
{
	static unsigned long lastUpdate = 0UL;
	static unsigned long lastBlink = 0UL;
	static unsigned long lastSerial = 0UL;

	unsigned long current = millis();
	if((current - lastUpdate) > 20){
		/*
		 * Tasks that update at a 20ms interval.
		 */
		hand->update();
		commandCenter->update();
		lastUpdate = current;
	}
	if((current-lastSerial) > 200){
		/*
		 * Tasks that update on a 200ms interval
		 */
		serialHandler->update();
		rfid->update();
		lastSerial = current;
	}
	if((current-lastBlink) > 1000){
		/*
		 * Blink a light to let us know we're still alive
		 */
		digitalWrite(STATUS_PIN, !digitalRead(STATUS_PIN));
		lastBlink = current;
	}
}



//Thing class functions will go here

Thing::Thing(){

}
