/*
	Helps you use ultrasonic sensors
	By Carlos Arena (arenamovediza)
*/

#include <UltrasonicA.h>

UltrasonicA::UltrasonicA(uint8_t triggerPin, uint8_t echoPin, float soundSpeed, unsigned int maxD, unsigned int minD, unsigned int triggerPulseDuration)
{
	this->triggerPin = triggerPin;
	this->echoPin = echoPin;
	this->minD = minD;
	this->maxD = maxD;
	this->triggerPulseDuration = triggerPulseDuration;
	this->soundSpeed = soundSpeed;
	this->echoPulseTimeout = 2 * this->maxD / this->soundSpeed;
	pinMode(triggerPin, OUTPUT);
	pinMode(echoPin, INPUT);
	
}

void UltrasonicA::triggerSensor(){
	digitalWrite(triggerPin, LOW);
	delayMicroseconds(5);
	digitalWrite(triggerPin, HIGH);
	delayMicroseconds(triggerPulseDuration);
	digitalWrite(triggerPin, LOW);
}

unsigned int UltrasonicA::getRawReading(){
	this->triggerSensor();
	this->lastRawReading = pulseIn(this->echoPin, HIGH, this->echoPulseTimeout);
	return lastRawReading;
}

unsigned int UltrasonicA::getDistance(){
	unsigned int timeToGetThere = this->getRawReading() / 2;
	this->lastDistanceReading = timeToGetThere * this->soundSpeed; // d = v * t
	return this->lastDistanceReading;
}

void UltrasonicA::printParameters(){
	Serial.print("triggerPin : ");
	Serial.println(triggerPin);
	Serial.print("echoPin : ");
	Serial.println(echoPin);
	Serial.print("maxD : ");
	Serial.println(maxD);
	Serial.print("minD : ");
	Serial.println(minD);
	Serial.print("soundSpeed : ");
	Serial.println(soundSpeed);
	Serial.print("triggerPulseDuration : ");
	Serial.println(triggerPulseDuration);
	Serial.print("echoPulseTimeOut : ");
	Serial.println(echoPulseTimeout);
}

