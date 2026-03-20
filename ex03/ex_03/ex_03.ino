#define LED_PIN 2


const long sosPattern[] = {
  200, 200,  
  200, 200,  
  200, 600,  
  600, 200, 
  600, 200,  
  600, 600, 
  200, 200,  
  200, 200,  
  200, 2000  
};
int patternIndex = 0; 
unsigned long previousMillis = 0;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= sosPattern[patternIndex]) {
    previousMillis = currentMillis;
    patternIndex = (patternIndex + 1) % (sizeof(sosPattern) / sizeof(long));
    
    
    digitalWrite(LED_PIN, patternIndex % 2 == 0 ? HIGH : LOW);
  }
}