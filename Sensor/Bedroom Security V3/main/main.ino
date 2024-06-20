/*
  PROGRAM: BedSecured
  Programmer: Jaycee Alipio
  Date: 6/17/2024
  Version: 3.00
  Description: Uses laser sensor to detect when someone enters room and sends into server
*/

const int laserPin = 13;
const int laserSensorPin = 12;
const int ledPin = 14;

void setup() {
  Serial.begin(115200);
  //pinMode(buttonPin, INPUT);
  pinMode(laserSensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(laserPin, OUTPUT);
}

void loop() {
//  buttonState = digitalRead(buttonPin);

  bool sensorValue = digitalRead(laserSensorPin);
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
  digitalWrite(laserPin, HIGH);

  if (sensorValue == 0) 
  {
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }

/*
  if (buttonState != oldButtonState && buttonState == HIGH)
  {
    ledState = (ledState == LOW ? HIGH : LOW);
    digitalWrite(ledPin, ledState);
    delay(50);
  }
  oldButtonState = buttonState;
*/
}
