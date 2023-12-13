#define DevID 0
#define DE 18
#define RE 19

void SetModeDR(long baudrate, int RX, int TX){
  Serial.begin(baudrate, SERIAL_8N1, RX, TX);
  pinMode(DE, OUTPUT);
  pinMode(RE, OUTPUT);
}

void SetInRead(){
  digitalWrite(DE, LOW);
  digitalWrite(RE, LOW);
}

void SetInWrite(){
  digitalWrite(DE, HIGH);
  digitalWrite(RE, HIGH);
}

String ReadPort(){
while (Serial.available()<=0){
    delay(10);
  }
  String PW_M = Serial.readString();
  return (PW_M);
}

boolean ReadSolPort(){
while (Serial.available()<=0){
    delay(100);
  }
  String PW_M = Serial.readString();
  if (PW_M.indexOf("[D"+String(DevID)+"S]") != -1){
    return (true);
  }
    return (false);
}

void WritePort(String SData){
  Serial.write(SData.c_str(), SData.length());      //Serial Write ADC_Value to MSP Bus
  delay(100);
}

void WriteSolPort(int EID){
  String output = "[D" + String(EID) + "S]";
  Serial.write(output.c_str(), output.length());      //Serial Write ADC_Value to MSP Bus
  delay(100);
}

void WriteResPort(String SData){
  String output = "[D" + String(DevID) + "I]" + SData + "[D" + String(DevID) + "F]";
  Serial.write(output.c_str(), output.length());      //Serial Write ADC_Value to MSP Bus
  delay(100);
}
