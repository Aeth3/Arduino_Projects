#include <Time.h>

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);
#include <DS1302.h>
DS1302 rtc(2, 3, 4); //RST,DAT,CLK Pins of the DS1302 Module
String t;
String d;
String dw;
int relay[] = {12, 11, 10, 9, 8, 7, 6, 5};
char incomingValue;

void setup()
{
  Serial.begin(9600);
  for (int i = 0; i < 8; i++) {
    pinMode(relay[i], OUTPUT);
  }
  //pinMode(relay1, OUTPUT);
  //pinMode(relay2, OUTPUT);
  //pinMode(relay3, OUTPUT);
  //pinMode(relay4, OUTPUT);
  //pinMode(relay5, OUTPUT);
  //pinMode(relay6, OUTPUT);
  //pinMode(relay7, OUTPUT);
  //pinMode(relay8, OUTPUT);
  rtc.halt(false);
  rtc.writeProtect(false);
  lcd.backlight();
  lcd.init();
  lcd.begin(16, 2);
  //comment this section later
  //rtc.setDOW(MONDAY);      //name of the day of the week
  //rtc.setTime(9, 54, 00);  //Hour, Min, Sec
  //rtc.setDate(2, 5, 2022); //Day, Month, Year

  for (int i = 0; i < 8; i++) {
    digitalWrite(relay[i], HIGH);
  }
  //digitalWrite(relay1,HIGH);
  //digitalWrite(relay2,HIGH);
  //digitalWrite(relay3,HIGH);
  //digitalWrite(relay4,HIGH);
  //digitalWrite(relay5,HIGH);
  //digitalWrite(relay6,HIGH);
  //digitalWrite(relay7,HIGH);
  //digitalWrite(relay8,HIGH);
}

void loop()
{
  t = rtc.getTimeStr();
  d = rtc.getDateStr();
  dw = rtc.getDOWStr();
  lcd.setCursor(0, 1);
  lcd.print("Time:");
  lcd.setCursor(5, 1);
  lcd.print(t);
  lcd.setCursor(0, 0);
  lcd.print("Date:");
  lcd.setCursor(5, 0);
  lcd.print(d);
  lcd.setCursor(13, 1);
  lcd.print(dw);
  delay (1000);

  if (Serial.available()) {
    incomingValue = Serial.read();
    Serial.print(incomingValue);
    Serial.println();
  }
  if (incomingValue == '1') {
    digitalWrite(relay[0], HIGH);
  }
  else if (incomingValue == '2') {
    digitalWrite(relay[0], LOW);
  }
  else if (incomingValue == '3'){
    digitalWrite(relay[1], HIGH);
  }
  else if (incomingValue == '4'){
    digitalWrite(relay[1], LOW);
  }
  delay(100);
}

void relaySequence() {
  for (int i = 0; i < 8; i++) {
    digitalWrite(relay[i], LOW);
    delay(100);
    digitalWrite(relay[i], HIGH);
  }
  for (int i = 8; i >= 0; i--) {
    digitalWrite(relay[i], LOW);
    delay(100);
    digitalWrite(relay[i], HIGH);
  }
}
