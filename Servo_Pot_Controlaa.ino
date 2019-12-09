#include <Servo.h>
#include <LiquidCrystal.h>

Servo servo1;  
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int potin;    

void setup()
{
  servo1.attach(9); 
  lcd.begin(16, 2);
  lcd.print("position="); 
  delay(2000);
}

void loop() 
{ 
  potin = analogRead(A0);            
  potin = map(potin, 0, 1023, 0, 91);     
  servo1.write(potin);                  
  delay(20);    
  lcd.setCursor(9, 0);
  lcd.print(potin);
  lcd.print("degree");
}
