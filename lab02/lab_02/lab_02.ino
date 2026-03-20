const int ledPin = 2; 
const int ledPin_R = 16; 
const int ledPin_B = 5; 
void setup() {
  // 初始化串口通信，设置波特率为115200
  Serial.begin(115200);
  // 将LED引脚设置为输出模式
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin_R, OUTPUT);
  pinMode(ledPin_B, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);
  digitalWrite(ledPin_R, HIGH);
  digitalWrite(ledPin_B, HIGH);  // 点亮LED
  Serial.println("LED ON");    // 串口输出提示
  delay(1000);                 // 保持1秒（1000毫秒）
  
  digitalWrite(ledPin, LOW); 
  digitalWrite(ledPin_R, LOW); 
  digitalWrite(ledPin_B,LOW);   // 熄灭LED
  Serial.println("LED OFF");   // 串口输出提示
  delay(1000);                 // 保持1秒
}
