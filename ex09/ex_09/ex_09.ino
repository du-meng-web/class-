#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "hid93845913的Pura 70 Pro+";
const char* password = "D2m0y060122@";
const int TOUCH_PIN = T0;

WebServer server(80);

String makePage() {
  String html = R"rawliteral(
<!DOCTYPE html>
<html lang="zh-CN">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>实时仪表盘</title>
  <style>
    #value { font-size: 80px; color: blue; font-weight: bold; }
  </style>
</head>
<body style="font-family:Arial; text-align:center; margin-top:100px;">
  <h1>触摸传感器实时数据</h1>
  <div id="value">--</div>
  <p>手靠近数值变小，远离变大</p >

  <script>
    setInterval(async () => {
      const res = await fetch('/data');
      const val = await res.text();
      document.getElementById('value').innerText = val;
    }, 100);
  </script>
</body>
</html>
)rawliteral";
  return html;
}

void handleRoot() {
  server.send(200, "text/html; charset=UTF-8", makePage());
}

void handleData() {
  int val = touchRead(TOUCH_PIN);
  server.send(200, "text/plain", String(val));
}

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  Serial.print("连接WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\n连接成功");
  Serial.print("访问地址: http://");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/data", handleData);
  server.begin();
}

void loop() {
  server.handleClient();
}