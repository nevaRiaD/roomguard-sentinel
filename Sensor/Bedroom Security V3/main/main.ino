#include <WiFi.h>
#include <HTTPClient.h>

// credentials to log onto wifi
const char* ssid = "PINOIBLUE";
const char* password = "man1ya2kis3ka456";

// pins for hardware
const int laserPin = 13;
const int laserSensorPin = 12;
const int ledPin = 14;
const int buttonPin = 27;

char* alarmType = "Laser Alarm";
char* alarmMessage = "";

const char* serverUrl = "http://89.117.21.206:5000/endpoint";  // Replace with your server's IP

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

  bool sensorValue = digitalRead(laserSensorPin);
  int sensorDelay = 10000;

  if (digitalRead(buttonPin) == HIGH) {
    digitalWrite(laserPin, HIGH);

    if (sensorValue != 0)
    {
      
      alarmMessage = "laser alarm: ALARM DETECTION";
      sensorDelay = 2000;
    }
    else {
      sensorDelay = 10000;
    }
    alarmMessage = "laser alarm: set";

  }
  else { 
    digitalWrite(laserPin, LOW);
    alarmMessage = "laser alarm: off";
  }

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
    delay(sensorDelay);
  }
  else {
    Serial.println("WiFi not connected");
    delay(10000);
  }

}