int mic = 3;
int out = 2;
void setup() {
pinMode(out, OUTPUT);
pinMode(mic, INPUT);
}

void loop() {
if (digitalRead(mic) == HIGH) {
  if(digitalRead(out) == HIGH) {
    digitalWrite(out, LOW);
    delay(500);
  }
  else {
    digitalWrite(out, HIGH);
    delay(500);
  }
}
}
