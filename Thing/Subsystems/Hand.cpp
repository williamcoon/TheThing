/*
 * Hand.cpp
 *
 *  Created on: Apr 23, 2015
 *      Author: williamcoon
 */

#include <Hand.h>

Hand* Hand::instance = NULL;
Finger Hand::pinky(PINKY_CONTROL_PIN, PINKY_COUNT_PIN);
Finger Hand::ring(RING_CONTROL_PIN, RING_COUNT_PIN);
Finger Hand::middle(MIDDLE_CONTROL_PIN, MIDDLE_COUNT_PIN);
Finger Hand::index(INDEX_CONTROL_PIN, INDEX_COUNT_PIN);
Finger Hand::thumb(THUMB_CONTROL_PIN, THUMB_COUNT_PIN);
Finger* Hand::fingers[] = {&pinky, &ring, &middle, &index, &thumb};

Hand::Hand()
{
	/*
	 * Setup Timer3 for triggering interrupt to check counters
	 */
	double sampleRate = 1000.0; //Sample at 1kHz
	noInterrupts();
    TCCR3A = 0;// set entire TCCR1A register to 0
    TCCR3B = 0;// same for TCCR1B
    TCNT3  = 0;//initialize counter value to 0
    // set compare match register (clock speed)/(sampleRate*prescaler) - 1 - must be <65536
    long comp = (long)(16000000)/(sampleRate) - 1;
    OCR3A = comp;
    // turn on CTC mode
    TCCR3B |= (1 << WGM12);
    // Set CS10 bit for no prescaler (CS11 + CS00 = 64 prescaler)
    TCCR3B |=  (1 << CS10); // (1 << CS11) |
    // enable timer compare interrupt
    TIMSK3 |= (1 << OCIE3A);
    interrupts();
}

void Hand::init(){
	for(int i=0; i<5; i++){
		fingers[i]->init();
	}
}

Hand* Hand::getInstance(){
	if(!instance)
		instance = new Hand();
	return instance;
}

bool Hand::isFinished(){
	//Returns true if all fingers are done with their motions
	for(int i=0; i<5; i++){
		if(!(fingers[i]->isFinished())){
			return false;
		}
	}
	return true;
}

void Hand::update(){
	for(int i=0; i<5; i++){
		fingers[i]->update();
	}
}

void Hand::readCounters(){
	for(int i=0; i<5; i++){
		fingers[i]->readCounter();
	}
}

//timer3 interrupt
ISR(TIMER3_COMPA_vect){
	Hand::readCounters();
}




