int relay[] = {12, 11, 10, 9, 8, 7, 6, 5};
char incomingValue;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (int i = 0; i < 8; i++) {
    pinMode(relay[i], OUTPUT);
  }
  for (int i = 0; i < 8; i++) {
    digitalWrite(relay[i], HIGH);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
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
  else if (incomingValue == '3') {
    digitalWrite(relay[1], HIGH);
  }
  else if (incomingValue == '4') {
    digitalWrite(relay[1], LOW);
  }
  delay(100);
}
