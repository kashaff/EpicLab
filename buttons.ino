int redLed = 13;
//int greenLed = 13;
//int buzzer = 10;
int smokeA0 = A5;
// Your threshold value
int sensorThres = 120;

void setup() {
  pinMode(redLed, OUTPUT);
//  pinMode(greenLed, OUTPUT);
//pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);
}

void loop() {
  int analogSensor = analogRead(smokeA0);

  Serial.print("Pin A5: ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThres)
  {
    digitalWrite(redLed, HIGH);
    //digitalWrite(greenLed, LOW);
    //tone(buzzer, 1000, 200);
  }
  else
  {
    digitalWrite(redLed, LOW);
    //digitalWrite(greenLed, HIGH);
    //noTone(buzzer);
  }
  delay(100);
}
