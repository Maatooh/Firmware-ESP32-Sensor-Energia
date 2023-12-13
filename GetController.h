String ModelAMC(int nodeID, String nodeLabel)
{
//-----SETTINGS------//
SetNode(nodeID);
uint32_t* xData;
float* xData2;
String xBuff;
//-------------------//
xBuff = ("[NameID]:" + nodeLabel + "|");
delay(500);
xData = IntReadAddress(node, 38, 3);
  if (xData != nullptr)
  {
    //Serial.println("");
    //Serial.print("Tension de fase A: ");
    //Serial.println(xData[0]/10);
    //Serial.print("Tension de fase B: ");
    //Serial.println(xData[1]/10);
    //Serial.print("Tension de fase C: ");
    //Serial.println(xData[2]/10);
    xBuff = xBuff + String(xData[0]/10) + "|";
    xBuff = xBuff + String(xData[1]/10) + "|";
    xBuff = xBuff + String(xData[2]/10) + "|";
    delete[] xData; // Liberar memoria asignada dinámicamente
  }
  delay(500);
  xData = IntReadAddress(node, 44, 3);
  if (xData != nullptr)
  {
    //Serial.println("");
    //Serial.print("Corriente de fase A: ");
    //Serial.println(xData[0]);
    //Serial.print("Corriente de fase B: ");
    //Serial.println(xData[1]);
    //Serial.print("Corriente de fase C: ");
    //Serial.println(xData[2]);
    xBuff = xBuff + String(xData[0]) + "|";
    xBuff = xBuff + String(xData[1]) + "|";
    xBuff = xBuff + String(xData[2]) + "|";
    delete[] xData; // Liberar memoria asignada dinámicamente
  }
  delay(500);
  //delayMicroseconds(500); 
  xData = IntReadAddress(node, 50, 1);
  if (xData != nullptr)
  {
    //Serial.println("");
    //Serial.print("Consumo:");
    //Serial.println(xData[0]);
    xBuff = xBuff + String(xData[0]) + "|";
    delete[] xData; // Liberar memoria asignada dinámicamente
  }
   delay(500);
  float Val_t;
  xData = IntReadAddress(node, 64, 2);
  if (xData != nullptr)
  {
    //Serial.print("Palabra 1:");
    //Serial.println(xData[0]);
    //Serial.print("Palabra 2:");
    //Serial.println(xData[1]);
    Val_t = xData[0] * 65536 + xData[1];
    delete[] xData; // Liberar memoria asignada dinámicamente
  }
   delay(500);
  float Val_s;
  xData = IntReadAddress(node, 4, 2);
  if (xData != nullptr)
  {
    //Serial.print("PT:");
    //Serial.println(xData[0]);
    //Serial.print("CT:");
    //Serial.println(xData[1]);
    Val_s = (Val_t / 1000) * xData[0] * xData[1];
    //Serial.print("Energia:");
    //Serial.print(Val_s);
    //Serial.println("kWh");
    xBuff = xBuff + String(uint32_t(Val_s));
    delete[] xData; // Liberar memoria asignada dinámicamente
  }
  delay(500);
return xBuff;
 }

String ModelPM800(int nodeID, String nodeLabel)
{
//-----SETTINGS------//
SetNode(nodeID);
uint32_t* xData;
float* xData2;
String xBuff;
//-------------------//
xBuff = ("[NameID]:" + nodeLabel + "|");
delay(500);
xData = IntReadAddress(node, 1120, 3);
  if (xData != nullptr)
  {
    //Serial.println("");
    //Serial.print("Tension de fase A: ");
    //Serial.println(xData[0]/10);
    //Serial.print("Tension de fase B: ");
    //Serial.println(xData[1]/10);
    //Serial.print("Tension de fase C: ");
    //Serial.println(xData[2]/10);
    xBuff = xBuff + String(xData[0]) + "|";
    xBuff = xBuff + String(xData[1]) + "|";
    xBuff = xBuff + String(xData[2]) + "|";
    delete[] xData; // Liberar memoria asignada dinámicamente
  }
  delay(500);
  xData = IntReadAddress(node, 1100, 3);
  if (xData != nullptr)
  {
    //Serial.println("");
    //Serial.print("Corriente de fase A: ");
    //Serial.println(xData[0]);
    //Serial.print("Corriente de fase B: ");
    //Serial.println(xData[1]);
    //Serial.print("Corriente de fase C: ");
    //Serial.println(xData[2]);
    xBuff = xBuff + String(xData[0]) + "|";
    xBuff = xBuff + String(xData[1]) + "|";
    xBuff = xBuff + String(xData[2]) + "|";
    delete[] xData; // Liberar memoria asignada dinámicamente
  }
  delay(500);
  //delayMicroseconds(500); 
  xData = IntReadAddress(node, 1143, 1);
  if (xData != nullptr)
  {
    //Serial.println("");
    //Serial.print("Consumo:");
    //Serial.println(xData[0]);
    xBuff = xBuff + String(xData[0]) + "|";
    delete[] xData; // Liberar memoria asignada dinámicamente
  }
   delay(500);
  xData2 = FloatReadAddress(node,2600, 1);
  if (xData2 != nullptr)
  {

   xBuff = xBuff + String(xData2[0]/1000);
    delete[] xData2; // Liberar memoria asignada dinámicamente
  }
  delay(500);
return xBuff;
 }
 
