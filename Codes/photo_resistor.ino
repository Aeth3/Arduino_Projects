int lightPen = A0;
int lightVal;
int dv = 1000;
int pin = 13;
void setup() {
  // put your setup code here, to run once:
pinMode(lightPen,INPUT);
pinMode(pin, OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
lightVal = analogRead(lightPen);
if(lightVal >= 400){
  Serial.print("I am lighted! and light value is: ");
  Serial.println(lightVal);
  digitalWrite(pin,HIGH);
}
else {
  Serial.print("I am covered! and light value: ");
  Serial.println(lightVal);
  digitalWrite(pin,LOW);
}
delay(dv);
}
