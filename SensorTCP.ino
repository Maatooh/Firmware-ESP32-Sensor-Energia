#include <WiFi.h>
#include <WiFiClient.h>
TaskHandle_t Task2;
const char* ssid = "MedicionesMaltexco";
const char* password =  "malta2023@";
const uint16_t port = 8081;
const char * host = "medicionesmaltexco.com"; //"192.168.21.175";
String deviceName = "sDev0";
String CMDName = "S0";
//int vsp[] = {33,32,35,34,39,36};
WiFiClient client;
#include "MaatoohBusRTU.h"
#include "GetController.h"
#include "RvData.h"
#include "WifiFix.h"


void loop2( void * pvParameters ){
  while (1){
  reconnectWifi();
  reconnectTCP();
  rPing();
  delay(500);
  //Serial.print("Task1 running on core ");
  //Serial.println(xPortGetCoreID());
  } 
}

void setup()
{
  DeclareOutput();
  SetSerial(9600,16,17);
//-----------Set Pins----------//
//#include "SetPins.h"
//-------------------------------//
  WiFi.setHostname((String("ESP32-") + deviceName).c_str());
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("...");
  }
  Serial.print("WiFi connected with IP: ");
  Serial.println(WiFi.localIP());
  reconnectTCP();
    Serial.println("Connected to server successful!");
    client.print(deviceName+ " - connected");
    xTaskCreatePinnedToCore(loop2, "Task2", 10000, NULL, 1, &Task2, 0);        
    delay(500); 
}

void loop(){
  onDataSend();
  delay(600);
  //Serial.print("Task1 running on core ");
  //Serial.println(xPortGetCoreID());
}
