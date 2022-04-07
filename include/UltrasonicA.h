/*
	Helps you use ultrasonic sensors
	By Carlos Arena (arenamovediza)
	By VReality (https://vrealitybolivia.com)
*/

#pragma once
#include <Arduino.h>

class UltrasonicA
{
private:
	uint8_t triggerPin;
	uint8_t echoPin;
	
	unsigned int maxD;
	unsigned int minD;

	float soundSpeed = 0.343; // in mm/us by default
	unsigned int triggerPulseDuration = 10; // in us
	unsigned long echoPulseTimeout; // in us

public:
	UltrasonicA(uint8_t triggerPin, uint8_t echoPin, float soundSpeed = 0.343, unsigned int maxD=4000, unsigned int minD=20, unsigned int triggerPulseDuration=10);

	void triggerSensor();
	unsigned int getRawReading();
	unsigned int getDistance();
	void printParameters();

	unsigned int lastRawReading;
	unsigned int lastDistanceReading;
};


