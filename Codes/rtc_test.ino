#include <Ds1302.h>
#include <virtuabotixRTC.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
// Init the DS3231 using the hardware interface

Ds1302  rtc(6,7,8);
LiquidCrystal_I2C lcd(0x27,20,4);

void setup()
{
  lcd.begin(16,2);
  lcd.init();
  lcd.init();
  lcd.backlight();
  // Setup Serial connection
  Serial.begin(9600);
  rtc.setDS1302Time(0,8,1,2,25,4,2022);
}

void loop()
{
  lcd.setCursor(0,1);
  lcd.print("Time:");
  lcd.setCursor(5, 1);
  lcd.print(rtc.getTimeStr());
  lcd.setCursor(0, 0);
  lcd.print("Date:");
  lcd.setCursor(5,0);
  lcd.print(rtc.getDateStr(FORMAT_SHORT, FORMAT_LITTLEENDIAN, '/'));
  //lcd.setCursor(13,1);
  //lcd.print(rtc.getDOWStr());
  delay (1000); 
}
