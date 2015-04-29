#include "Thing.h"
#include "CommandCenter.h"
#include "SerialHandler.h"
#include "RFID.h"
#include "Hand.h"

//The setup function is called once at startup of the sketch
void setup()
{
// Add your initialization code here
	pinMode(13, OUTPUT);
	Serial.begin(115200);
	Serial1.begin(9600);
	delay(500);
}

CommandCenter *commandCenter = CommandCenter::getInstance();
Hand *hand = Hand::getInstance();
SerialHandler serialHandler(&Serial);
RFID rfid(&Serial1);

// The loop function is called in an endless loop
void loop()
{
	static unsigned long lastUpdate = 0UL;
	static unsigned long lastBlink = 0UL;
	static unsigned long lastSerial = 0UL;
	unsigned long current = millis();
	if((current - lastUpdate) > 20){
		hand->update();
		commandCenter->update();
		lastUpdate = current;
	}
	if((current-lastSerial) > 200){
		serialHandler.update();
		rfid.update();
		lastSerial = current;
	}
	if((current-lastBlink) > 1000){
		digitalWrite(13, !digitalRead(13));
		lastBlink = current;
	}
}

//Thing class functions will go here

Thing::Thing(){

}
