#include "Thing.h"
#include "CommandCenter.h"
#include "SerialHandler.h"
#include "RFID.h"
#include "Hand.h"
#include "Wrist.h"

CommandCenter *commandCenter = CommandCenter::getInstance();
Hand *hand = Hand::getInstance();
TankDrive *tankDrive = TankDrive::getInstance();
Wrist *wrist = Wrist::getInstance();
SerialHandler serialHandler(&Serial);
RFID rfid(&Serial1);

const int STATUS_LED = 13;

//The setup function is called once at startup of the sketch
void setup()
{
	pinMode(STATUS_LED, OUTPUT);
	Serial.begin(115200);
	Serial1.begin(9600);
	hand->init();
	tankDrive->init();
	wrist->init();
}

// The loop function is called in an endless loop
void loop()
{
	static unsigned long lastUpdate = 0UL;
	static unsigned long lastBlink = 0UL;
	static unsigned long lastSerial = 0UL;

	unsigned long current = millis();
	if((current - lastUpdate) > 5){
		/*
		 * These are all the tasks that update at a 20ms interval.
		 */
		hand->update();
		commandCenter->update();
		lastUpdate = current;
	}
	if((current-lastSerial) > 200){
		/*
		 * Tasks that update on a 200ms interval
		 */
		serialHandler.update();
		rfid.update();
		lastSerial = current;
	}
	if((current-lastBlink) > 1000){
		/*
		 * Blink a light to let us know we're still alive
		 */
		digitalWrite(STATUS_LED, !digitalRead(STATUS_LED));
		lastBlink = current;
	}
}



//Thing class functions will go here

Thing::Thing(){

}
