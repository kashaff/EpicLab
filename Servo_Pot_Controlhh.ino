#include <Servo.h>
#include <LiquidCrystal.h>
// Initialize LCD with following connections
LiquidCrystal lcd(10, 9, 8, 7, 6, 5);
//speed control of servo motor using pot
Servo myservo1;
//myservo1.attach(6, 800, 2200);
int potpin1 = 0;  // defines pin used for the potentiometer
int pot1val;
int servoVal;
int d=2;

void setup()
{
//lcd.begin(16, 2);
myservo1.attach(6,800,2200);  // defines pin used for the servo
//lcd.clear();
//lcd.setCursor(0, 0);
pinMode(2,INPUT);
pinMode(6,OUTPUT);

}

void loop()
{d=digitalRead(2);
if(d==0)
{
pot1val = analogRead(potpin1);
servoVal = map(pot1val, 0, 1023, 0, 179);
myservo1.write(servoVal);
delay(20);
}
else
{digitalWrite(6,HIGH);}
}

/*lcd.clear();
lcd.setCursor(0,0);
lcd.print("Pot value:");
 // set the cursor to column 0, line 1
lcd.setCursor(11, 0);
lcd.print(pot1val);
  // (note: line 1 is the second row, since counting begins with 0):
lcd.setCursor(0, 1);
  // print the number of seconds since reset:
lcd.print("Angle     :");
lcd.setCursor(11, 1);
lcd.print(servoVal);
delay(2000);
}
*/
