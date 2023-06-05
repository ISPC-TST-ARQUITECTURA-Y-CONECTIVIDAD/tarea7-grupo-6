#include <Arduino.h>

// put function declarations here:
String voice;

void setup()
{
  pinMode(7, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  while (Serial.available())
  {
    delay(10);
    char c = Serial.read();
    voice += c;
  }
  if (voice.length() > 0)
  {
    Serial.println(voice);
    if (voice == "on")
    {
      digitalWrite(7, HIGH);
    }
    if (voice == "off")
    {
      digitalWrite(7, LOW);
    }
  }
  voice = "";
}
