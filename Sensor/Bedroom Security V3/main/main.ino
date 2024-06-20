#include <WiFi.h>
#include <HTTPClient.h>

// credentials to log onto wifi
const char* ssid = "PINOIBLUE";
const char* password = "man1ya2kis3ka456";

const char* serverUrl = "http://89.117.21.206:5000/endpoint";  // Replace with your server's IP

void setup() {
  Serial.begin(115200);
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
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("WiFi connected, starting HTTP request...");

    HTTPClient http;
    http.begin(serverUrl);

    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    int httpResponseCode = http.POST("message=Hello, server!");

    if (httpResponseCode > 0) {
      String response = http.getString();
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
      Serial.print("Response: ");
      Serial.println(response);
    } else {
      Serial.print("Error on sending POST: ");
      Serial.println(httpResponseCode);
    }

    http.end();
  } else {
    Serial.println("WiFi not connected");
  }

  delay(10000);  // Send a message every 10 seconds
}