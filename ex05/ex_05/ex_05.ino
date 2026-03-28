// 定义LED引脚
const int ledPin = 2; 

// 触摸引脚（T0 = GPIO4）
const int touchPin = T0;

// 设置PWM属性
const int freq = 5000;          // 频率 5000Hz
const int resolution = 8;       // 分辨率 8位 (0-255)

// 档位变量：1=慢、2=中、3=快
int level = 1;

// 防抖
unsigned long lastTouch = 0;
const int debounce = 200;

void setup() {
  Serial.begin(115200);
  ledcAttach(ledPin, freq, resolution);
}

void loop() {
  // 触摸切换档位（循环 1→2→3→1）
  if (touchRead(touchPin) < 500 && millis() - lastTouch > debounce) {
    lastTouch = millis();
    level++;
    if (level > 3) level = 1;
    Serial.print("档位：");
    Serial.println(level);
  }

  // 根据档位选择 delay 时间（区别非常明显）
  int d;
  if (level == 1) d = 16;   // 慢
  else if (level == 2) d = 8;  // 中
  else d = 2;              // 快

  // 逐渐变亮
  for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){   
    ledcWrite(ledPin, 255-dutyCycle);
    delay(d);
  }

  // 逐渐变暗
  for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle--){
    ledcWrite(ledPin, 255-dutyCycle);   
    delay(d);
  }
  
  Serial.println("Breathing cycle completed");
}