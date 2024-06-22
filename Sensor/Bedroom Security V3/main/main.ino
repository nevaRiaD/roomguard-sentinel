#include <WiFi.h>
#include <HTTPClient.h>
#include "myFunctions.h"
#include "wifiCredentials.h"

// pins for hardware
const int laserPin = 13;
const int laserSensorPin = 12;
const int ledPin = 14;
const int buttonPin = 27;

char* alarmMessage = "";
const char* serverUrl = "http://89.117.21.206:5000/endpoint";  // Replace with your server's IP

unsigned long previousMillis = 0;
const long interval = 10000;

void setup() {
  Serial.begin(115200);
  pinMode(buttonPin, INPUT);
  pinMode(laserSensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(laserPin, OUTPUT);

  delay(1000); // Wait for Serial to initialize
  Serial.println("Starting setup...");

  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi...");

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Waiting for WiFi connection...");
  }

  Serial.println("Connected to WiFi");
  Serial.println(WiFi.localIP());  // Print the local IP address
}

void loop() {
	laserSensor();
	serverConnection();
}