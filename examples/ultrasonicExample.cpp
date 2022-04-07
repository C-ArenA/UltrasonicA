/*
	Helps you use ultrasonic sensors
	By Carlos Arena (arenamovediza)
	By VReality (https://vrealitybolivia.com)
	
*/

#include <Arduino.h>
#include <UltrasonicA.h>

#define TRIGGER_PIN 6
#define ECHO_PIN 7

UltrasonicA ultrasonic = UltrasonicA(TRIGGER_PIN, ECHO_PIN);

void setup() {
	Serial.begin(9600);
}

void loop() {
  Serial.print("RawReading:");
  Serial.print(ultrasonic.getRawReading());
  Serial.print(",Distance:");
  Serial.print("Distance:");
  Serial.print(ultrasonic.getDistance());
  Serial.println();
  delay(100);
}