const int ledPin = 2;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {

  for(int i=0; i<3; i++) {
    digitalWrite(ledPin, HIGH); delay(200);
    digitalWrite(ledPin, LOW); delay(200);
  }
  delay(600); 
  

  for(int i=0; i<3; i++) {
    digitalWrite(ledPin, HIGH); delay(600);
    digitalWrite(ledPin, LOW); delay(200);
  }
  delay(600); 
  

  for(int i=0; i<3; i++) {
    digitalWrite(ledPin, HIGH); delay(200);
    digitalWrite(ledPin, LOW); delay(200);
  }
  delay(2000); 
}
