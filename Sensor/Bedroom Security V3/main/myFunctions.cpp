#include "myFunctions.h"
#include "wifiCredentials.h"
#include <WiFi.h>
#include <HTTPClient.h>

bool laserState = false;
bool buttonState = HIGH;
bool lastButtonState = HIGH;

void laserSensor() {
  buttonState = digitalRead(buttonPin);

  // Check if button state changed
  if (buttonState == LOW && lastButtonState == HIGH) {
    // Toggle the laser state
    laserState = !laserState;
  }

  // Update the laser based on the current laserState
  if (laserState) {
    digitalWrite(laserPin, HIGH);
    if (digitalRead(laserSensorPin) != 0) {
      digitalWrite(ledPin, HIGH);
      alarmMessage = "laser alarm: set";
    }
    else {
      digitalWrite(ledPin, LOW);
      alarmMessage = "laser alarm: ALARM DETECTION";
    }
  }
  else {
    digitalWrite(laserPin, LOW);
    alarmMessage = "laser alarm: off";
  }

  // Save current button state as the last button state for next loop iteration
  lastButtonState = buttonState;
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
			int httpResponseCode = http.POST("laser alarm: CONNECTED TO SERVER");
			
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