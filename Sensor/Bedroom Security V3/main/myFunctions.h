#ifndef MYFUNCTIONS_H
#define MYFUNCTIONS_H

#include <Arduino.h>

// Function declarations
void laserSensor();
void serverConnection();

// External variables needed by functions
extern const int laserPin;
extern const int laserSensorPin;
extern const int ledPin;
extern const int buttonPin;
extern char* alarmMessage;
extern const char* serverUrl;
extern unsigned long previousMillis;
extern const long interval;
extern bool laserState;
extern bool buttonState;
extern bool lastButtonState;

#endif