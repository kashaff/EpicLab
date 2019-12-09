#include <Servo.h>
#include <LiquidCrystal.h>
// Initialize LCD with following connections
LiquidCrystal lcd(10, 9, 8, 7, 6, 5);
//speed control of servo motor using pot
Servo myservo1;

//int potpin1 = 0;  // defines pin used for pot 
//int pot1val;
//int servoVal;
int counter=10;
int d=2;

void setup()
{
//lcd.begin(16, 2);
myservo1.attach(9,800,2200);  // defines pin used for the servo
//lcd.clear();
//lcd.setCursor(0, 0);
pinMode(2,INPUT);
//pinMode(6,OUTPUT);
}

void loop()
{d=digitalRead(2);
myservo1.write(180);
if(d==0)
{
  counter--;
  delay(150);
}
if(counter==10)
{myservo1.write(180);}
else if(counter == 9)
{myservo1.write(120);}
else if(counter == 8)
{myservo1.write (100);} 
else if(counter == 7)
{myservo1.write (90);}
else if(counter == 6)  
{myservo1.write (80);}
else if(counter == 5)  
{myservo1.write (70);}
else if(counter == 4)  
{myservo1.write (60);}
else if(counter == 3)  
{myservo1.write (50);}
else if(counter == 2)  
{myservo1.write (40);}
else if(counter == 1)  
{myservo1.write (20);}
/*else if(counter == 10)  
{myservo1.write (110);}
   else if(counter == 11)  
   { myservo1.write (120);}
   else if(counter == 12)  
   { myservo1.write (130);}
   else if(counter == 13)  
   { myservo1.write (140);}
   else if(counter == 14)  
   { myservo1.write (150);}
   else if(counter == 15)  
   { myservo1.write (160);}
   else if(counter == 16)  
   { myservo1.write (170);}
   else if(counter == 18)  
   { myservo1.write (180);}
   else if(counter == 19)  
   { myservo1.write (190);}
  //else reset the counter to 0 which resets thr servo to 0 degrees*/
else
{counter = 10;}
//pot1val = analogRead(potpin1);
//servoVal = map(pot1val, 0, 1023, 0, 179);
//myservo1.write(servoVal);
delay(20);
}
