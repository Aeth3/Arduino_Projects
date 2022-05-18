int ledPin = 13;
int buttonPin = A1;
int buttonRead;
int dt = 100;
int relay[] = {12, 11, 10, 9, 8, 7, 6, 5};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (int i = 0; i < 8; i++) {
    pinMode(relay[i],OUTPUT);
  }
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  buttonRead = digitalRead(buttonPin);
  Serial.println(buttonRead);
  delay(dt);
  if (buttonRead == 0) {
    for(int i=0;i<8;i++){
      digitalWrite(relay[i],HIGH);
    }
  }
  else if (buttonRead == 1) {
    for(int i=0;i<8;i++){
      digitalWrite(relay[i],LOW);
    }
  }
}
