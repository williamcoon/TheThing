#include "Thing.h"

const unsigned long Thing::RFID_TIMEOUT = 2000;

//The setup function is called once at startup of the sketch
void setup()
{
	pinMode(STATUS_PIN, OUTPUT);
	wdt_enable(WDTO_1S); //Setup watchdog timer to reset after 1 second
	thing.init();
}

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
		thing.updateExecution();
		lastUpdate = current;
	}
	if((current-lastSerial) > 200){
		/*
		 * Tasks that update on a 200ms interval
		 */
		thing.checkSerial();
		thing.checkRFID();
		wdt_reset(); //reset watchdog timer
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

Thing::Thing(){
	rfid = new RFID(&Serial2, 9600);
	serialHandler = new SerialHandler(&Serial, 115200);
	commandCenter = CommandCenter::getInstance();
	hand = Hand::getInstance();
	tankDrive = TankDrive::getInstance();
	wrist = Wrist::getInstance();
	ejector = Ejector::getInstance();
	poofer = Poofer::getInstance();
	commandCreator = new CommandCreator();
	startButton = new LedButton(START_BUTTON, START_LED);
	stopButton = new LedButton(STOP_BUTTON, STOP_LED);
	joyStick = new Joystick(X_AXIS_PIN, Y_AXIS_PIN);
	executingRFID = false;
	lastRFIDTime = 0;
}

void Thing::init(){
	serialHandler->init();
	rfid->init();
	hand->init();
	tankDrive->init();
	wrist->init();
	ejector->init();
	poofer->init();
	startButton->init();
	stopButton->init();
	joyStick->init();
}

void Thing::updateExecution(){
	hand->update();
	commandCenter->update();
	startButton->poll();
	stopButton->poll();
	thing.checkButtonStates();
	thing.driveWithJoystick();
}

void Thing::driveWithJoystick(){
	joyStick->readJoystick();
	tankDrive->drive(joyStick->getLeftSpeed(), joyStick->getRightSpeed());
}

void Thing::checkSerial(){
	String command = serialHandler->checkForCommand();
	if(!command.equals(SerialHandler::NO_COMMAND)){
		stopButton->enable();
		commandCreator->createCommand(command);
	}
}

void Thing::checkRFID(){
	String rfidCommand = rfid->getCurrentTag();
	if(!rfidCommand.equals(RFID::NO_TAG)){
		if(executingRFID){
			lastRFIDTime = millis();
			commandCreator->createCommand(rfidCommand);
		}else{
			Serial.print("Tag ID: ");
			Serial.println(rfidCommand);
			startButton->enable();
			rfid->resetReader();
		}
	}else{
		if(executingRFID){
			if(ejector->getLastRetractTime() >= lastRFIDTime){
				if((millis()-ejector->getLastRetractTime()) > RFID_TIMEOUT){
					executingRFID = false;
					stopAllSubsystems();
				}
			}
		}else{
			startButton->disable();
		}
	}
}

void Thing::checkButtonStates(){
	if(stopButton->readButton()){
		stopButton->disable();
		stopAllSubsystems();
		commandCreator->ejectBlock(NULL);
	}
	if(startButton->readButton()){
		startButton->disable();
		executingRFID = true;
		stopButton->enable();
	}
}

void Thing::stopAllSubsystems(){
	commandCenter->clearCommands();
	tankDrive->stop();
	hand->stop();
	poofer->ceaseFire();
	wrist->stopMotion();
	ejector->turnOff();
	stopButton->disable();
	executingRFID = false;
	rfid->resetReader();
	Serial.println("Stopping Everything");
}
