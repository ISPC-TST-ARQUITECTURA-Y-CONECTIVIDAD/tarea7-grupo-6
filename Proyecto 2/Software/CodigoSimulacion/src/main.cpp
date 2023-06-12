#include <Arduino.h>

String recibe;

void setup()
{
  pinMode(7, OUTPUT); // establecemos como salida
  pinMode(8, OUTPUT); // establecemos como salida
  Serial.begin(9600); // Inicializamos  el puerto serie nativo
}
void loop()
{
  while (Serial.available())
  {
    delay(10);
    char c = Serial.read();
    recibe += c;
  }
  if (recibe.length() > 0)
  {

    if (recibe == "ventilar" || recibe == "Ventilar") // comparo con el string ventilador
    {
      digitalWrite(7, HIGH); // si el if es true cambio estado del pin
    }
    if (recibe == "no ventilar" || recibe == "No ventilar") // comparo con el string ventilador
    {
      digitalWrite(7, LOW); // si el if es true cambio estado del pin
    }

    if (recibe == "iluminar" || recibe == "Iluminar") // comparo con el string lampara
    {
      digitalWrite(8, HIGH); // si el if es true cambio estado del pin
    }
    if (recibe == "no iluminar" || recibe == "No iluminar") // comparo con el string lampara
    {
      digitalWrite(8, LOW); // si el if es true cambio estado del pin
    }

    if (recibe == "apagar todo" || recibe == "Apagar todo") // comparo con el string lampara
    {
      digitalWrite(8, LOW); //
      digitalWrite(7, LOW); // s
    }
    if (recibe == "encender todo" || recibe == "Encender todo") // comparo con el string lampara
    {
      digitalWrite(8, HIGH); //
      digitalWrite(7, HIGH); //
    }
    recibe = "";
  }
}