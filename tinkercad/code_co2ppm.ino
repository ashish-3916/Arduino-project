
// video available at https://drive.google.com/file/d/142EQS4xu3rDvMHQ3KwjbZVtvGprCWU-K/view?usp=drivesdk
// tickercad playground https://www.tinkercad.com/things/c5qt1CwyIoA 

#include <LiquidCrystal.h>
LiquidCrystal lcd(5,6,8,9,10,11); // lcd object 
  
int redled = 2;
int greenled = 3;
int sensor = A0;
int sensorThresh = 400;

void setup()
{
pinMode(redled, OUTPUT);
pinMode(greenled,OUTPUT);
pinMode(sensor,INPUT);
Serial.begin(9600);
lcd.begin(16,2);
}

void loop()
{
  int analogValue = analogRead(sensor); //read from pin A0
  Serial.print(analogValue);
  if(analogValue>sensorThresh)
  {
    digitalWrite(redled,HIGH);
    digitalWrite(greenled,LOW);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("ALERT");
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("HIGH PPM CONCENTRATION");
    delay(1000);
  }
  else
  {
    digitalWrite(greenled,HIGH);
    digitalWrite(redled,LOW);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("SAFE");
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("MODERATE PPM CONCENTRATION");
    delay(1000);
  }  
     
}
