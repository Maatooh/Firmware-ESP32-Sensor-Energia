long analogReadFx(int PinRead){
  double PinVal = 0;
  for (int i = 0; i < 64; i++) {
    PinVal += analogRead(PinRead);
  }
  return long(PinVal / 64);
}

String xBuffer;

void SendData(){
//[CMD S0]:0|0|0|0|0|0|0|0|0|0|0|0|0
xBuffer = "";
xBuffer = xBuffer + (ModelPM800(1, "Extracto")) + "\n";
xBuffer = xBuffer + (ModelAMC(2, "Limpia")) + "\n";
xBuffer = xBuffer + (ModelAMC(3, "Malta"));
//xBuffer = xBuffer + (ModelAMC(1, "Caldera"));
xBuffer = "[Ri]"+ xBuffer.substring(0,xBuffer.length());

delay(600);
Serial.print ("[CMD " + CMDName + "]:" + xBuffer);
client.print ("[CMD " + CMDName + "]:" + xBuffer);
}

void onDataSend(){
  if (client.connected()){
      SendData();
    }
}

void onDataReceived(){
  if (client.available() > 0) {
    String cData = client.readString();
    //RevData(cData);
    //delay(100);
    }
}
