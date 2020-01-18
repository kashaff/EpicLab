//TMRpcm library is needed

#include "SD.h"
#define SD_ChipSelectPin 10
#include "TMRpcm.h"
#include "SPI.h"

TMRpcm tmrpcm;
const int buzzerPin = 9; // declaring the PWM pin</p><p>void setup() {
  





const int buttonPin = 2; 
const int ledPin =  13;
int buttonState = 0;         // variable for reading the pushbutton status


void setup(){
 pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
Serial.begin(9600);
if(!SD.begin(SD_ChipSelectPin))
{
  Serial.println("SD fail");
  return;
}
tmrpcm.setVolume(6);

}

void loop() {

    buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH  ){
tmrpcm.play("test.wav");
digitalWrite(ledPin, HIGH);
 Serial.print("on");
 Serial.begin(8600);
pinMode(buzzerPin, OUTPUT); //addigning pin to Output mode</p><p>}</p><p>void loop() {
  tone(buzzerPin, 50);
  delay(50);
  noTone(buzzerPin);
  delay(100);

 }
 else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }

}
