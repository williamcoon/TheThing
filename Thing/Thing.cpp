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
	rfid = RFID::getInstance();
	serialHandler = new SerialHandler(&Serial, 115200);
	commandCenter = CommandCenter::getInstance();
	hand = Hand::getInstance();
	tankDrive = TankDrive::getInstance();
	wrist = Wrist::getInstance();
	commandCreator = new CommandCreator();
	startButton = new LedButton(START_BUTTON, START_LED);
	stopButton = new LedButton(STOP_BUTTON, STOP_LED);
	joyStick = new Joystick(X_AXIS_PIN, Y_AXIS_PIN);
	beanieLed = BeanieLed::getInstance();
	executingRFID = true;
	lastRFIDTime = 0;
	driveTrainEnabled = false;
	lastCommand = "";
}

void Thing::init(){
	serialHandler->init();
	rfid->init(&Serial2, 9600);
	hand->init();
	tankDrive->init();
	wrist->init();
	startButton->init();
	startButton->enable();
	stopButton->init();
	stopButton->disable();
	joyStick->init();
	beanieLed->init();
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
	if(driveTrainEnabled){
		joyStick->readJoystick();
		double left = joyStick->getLeftSpeed();
		double right = joyStick->getRightSpeed();
//		if(left != 0 || right != 0){
//			Serial.print("Left Speed: ");
//			Serial.print(joyStick->getLeftSpeed());
//			Serial.print("    Right Speed: ");
//			Serial.println(joyStick->getRightSpeed());
//		}
		//tankDrive->drive(joyStick->getLeftSpeed(), joyStick->getRightSpeed());
	}
}

void Thing::checkSerial(){
	String command = serialHandler->checkForCommand();
	if(!command.equals(SerialHandler::NO_COMMAND)){
		//stopButton->enable();
		commandCreator->createCommand(command);
	}
}

void Thing::checkRFID(){
	String rfidCommand = rfid->getCurrentTag();
	if(!rfidCommand.equals(lastCommand)){
		lastCommand = rfidCommand;
		if(!rfidCommand.equals(RFID::NO_TAG)){
			if(executingRFID){
				lastRFIDTime = millis();
				beanieLed->turnOff();
				commandCreator->createCommand(rfidCommand);
				rfid->resetReader();
			}else{
				Serial.print("Tag ID: ");
				Serial.println(rfidCommand);
				rfid->resetReader();
			}
		}else{
			beanieLed->turnOn();
		}
	}else{
		//Tag has been executed and is still there
		rfid->resetReader();
	}
}

void Thing::checkButtonStates(){
	if(stopButton->readButton()){
		Serial.println("Stop");
		stopButton->disable();
		stopAllSubsystems();
		startButton->enable();
	}
	if(startButton->readButton()){
		Serial.println("Start");
		startButton->disable();
		driveTrainEnabled = true;
		stopButton->enable();
	}
}

void Thing::stopAllSubsystems(){
	commandCenter->clearCommands();
	driveTrainEnabled = false;
	tankDrive->stop();
	hand->stop();
	wrist->stopMotion();
	stopButton->disable();
	Serial.println("Stopping Everything");
}
