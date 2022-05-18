//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#define pin 12
int lightPen = 0;
int lightVal;
int dv = 1000;
LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  Serial.begin(9600);
  pinMode(pin,OUTPUT);
  lcd.begin(16,2);
  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
}


void loop()
{
  lightVal = analogRead(lightPen);
 if(lightVal >= 300){
  lcd.setCursor(0,0);
  lcd.print("Lights off!");
  lcd.setCursor(10,1);
  lcd.print(lightVal);
  digitalWrite(pin,LOW);
}
else {
  lcd.setCursor(0,0);
  lcd.print("Lights on!");
  lcd.setCursor(10,1);
  lcd.print(lightVal);
  digitalWrite(pin,HIGH);
}
delay(dv);
}
