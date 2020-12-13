



#include <SPI.h>
#include <MQ135.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(-1);
MQ135 gasSensor = MQ135(A0);
int val;
int sensorPin = A0;
int sensorValue = 0;

void setup() {
  		 // initialize with the I2C addr 0x3C
 			 gasSensor = MQ135(A0);
 			 Serial.begin(9600);
  			pinMode(sensorPin, INPUT);
 			 display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  
 			 display.clearDisplay();   
}

void loop() {
  			// put your main code here, to run repeatedly:
 			 display.setTextSize(3);
  			float rzero = gasSensor.getRZero();
  			float ppm = gasSensor.getPPM();
  			Serial.print ("ppm: ");
  			Serial.println (ppm);
 		 	 display.setTextSize(1.2);
 			 display.setTextColor(WHITE);
  			display.setCursor(0,28);
  			display.print("ppm   ");
 			 display.println(ppm); 
 			 display.display();
  			delay(200);
  			display.clearDisplay();
}
