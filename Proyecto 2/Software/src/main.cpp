#include <Arduino.h>
#include <SoftwareSerial.h>  // Incluimos la librería  SoftwareSerial  
SoftwareSerial BT(10,11);    // Definimos los pines RX y TX del Arduino conectados al Bluetooth
String recibe;

void setup()
{
  BT.begin(9600);       // Inicializamos el puerto serie BT
  Serial.begin(9600);   // Inicializamos  el puerto serie nativo 
  pinMode(7, OUTPUT);  //establecemos como salida
  pinMode(8, OUTPUT);     //establecemos como salida
}
void loop(){
  while (BT.available())
  {
    delay(1);
    char c = BT.read();
    recibe += c;
  }
  if (recibe.length() > 0)
  {
    if (recibe=="ventilador") //comparo con el string ventilador
    {
      digitalWrite(7, !digitalRead(7));// si el if es true cambio estado del pin 
    }
    if (recibe=="lámpara")//comparo con el string lampara
    {
      digitalWrite(8, !digitalRead(8));// si el if es true cambio estado del pin 
    }
    recibe="";
  }
}
