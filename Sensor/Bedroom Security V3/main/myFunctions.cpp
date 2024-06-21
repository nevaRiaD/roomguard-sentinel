#include "myFunctions.h"
#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>

void laserSensor() {
	if (digitalRead(buttonPin) == LOW) {
		digitalWrite(laserPin, HIGH);
		if (digitalRead(laserSensorPin) != 0) {
			alarmMessage = "laser alarm: ALARM DETECTION";
		}
		else {
			alarmMessage = "laser alarm: set";
		}
	}
	else {
		digitalWrite(laserPin, LOW);
		alarmMessage = "laser alarm: off";
	}
}

void serverConnection() {
	
	unsigned long currentMillis = millis();
	
	if (currentMillis - previousMillis >= interval) {
		previousMillis = currentMillis;
		
		if (WiFi.status() == WL_CONNECTED) {
			Serial.println("WiFi connected, starting HTTP request...");
			
			HTTPClient http;
			http.begin(serverUrl);
			http.addHeader("Content-Type", "application/x-www-form-urlencoded");
			int httpResponseCode = http.POST(alarmMessage);
			
			if (httpResponseCode > 0) {
				String response = http.getString();
				Serial.print("HTTP Response code: ");
				Serial.println(httpResponseCode);
				Serial.print("Response: ");
				Serial.println(response);
			}
			else {
				Serial.print("Error on sending POST: ");
				Serial.println(httpResponseCode);
			}
			
			http.end();
		}
		else {
			Serial.println("WiFi not connected");
		}
	}
}