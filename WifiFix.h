unsigned long previusMillis = 0;
const long pInterval = 2500; 
const long pRestart = 5000;
unsigned long sRestart = 0;

void rPing(){
if (client.connected() && WiFi.status() == WL_CONNECTED){
  unsigned long currentMillis = millis();
  if (currentMillis - previusMillis >= pInterval){
   client.print(char(1));
    previusMillis = currentMillis;
    }
 }
}

void reconnectWifi(){
if (WiFi.status() != WL_CONNECTED) {
  Serial.println("Reconnecting to WiFi...");
  WiFi.disconnect();
  //WiFi.reconnect();
   sRestart = millis();
  while (WiFi.status() != WL_CONNECTED) {
    WiFi.begin(ssid, password);
    Serial.println("...");
    unsigned long cRestart = millis();
  if (cRestart - sRestart >= pRestart){
    Serial.println("Device Reset...");
    ESP.restart();
    }
    delay(500);
  }
  Serial.print("WiFi connected with IP: ");
  Serial.println(WiFi.localIP());
  if (!client.connected() && WiFi.status() == WL_CONNECTED) {
  sRestart = millis();
  while (!client.connect(host, port)) {
        Serial.println("Connection to host failed");
        unsigned long cRestart = millis();
        if (cRestart - sRestart >= pRestart){
        Serial.println("Device Reset...");
        ESP.restart();
        }
        delay(500);
    }
    Serial.println("Connected to server successful!");
    client.print(deviceName+ " - connected");
    }
  }
}

void reconnectTCP(){
  if (!client.connected() && WiFi.status() == WL_CONNECTED) {
     sRestart = millis();
     while (!client.connect(host, port)) {
        Serial.println("Connection to host failed");
        unsigned long cRestart = millis();
        if (cRestart - sRestart >= pRestart){
        Serial.println("Device Reset...");
        ESP.restart();
        }
        delay(500);
    }
    Serial.println("Connected to server successful!");
    client.print(deviceName+ " - connected");
    }
}
