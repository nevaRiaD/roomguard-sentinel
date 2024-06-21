#ifndef MYFUNCTIONS_H
#define MYFUNCTIONS_H

// Function declarations
void laserSensor();
void serverConnection();

// External variables needed by functions
extern const int laserPin;
extern const int laserSensorPin;
extern const int buttonPin;
extern char* alarmMessage;
extern const char* serverUrl;
extern unsigned long previousMillis;
extern const long interval;

#endif