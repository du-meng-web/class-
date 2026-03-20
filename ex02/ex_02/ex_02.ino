const int ledPin = 2;

unsigned long prev = 0;
const long interval = 1000;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  unsigned long now = millis();
  if (now - prev >= interval) {
    prev = now;
    digitalWrite(ledPin, !digitalRead(ledPin));
  }
}
