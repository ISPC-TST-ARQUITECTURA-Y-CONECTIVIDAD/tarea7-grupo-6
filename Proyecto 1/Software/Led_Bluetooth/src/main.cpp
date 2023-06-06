#include <Arduino.h>

int LED=13;//////////// PIN 13 DEL ARDUINO ES PARA EL LED

char action;

 void setup(){
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
 
 }
 void loop(){
if(Serial.available()){
  action=Serial.read();
}
if (action == 'H'){
  Serial.println(action);
  digitalWrite(LED,HIGH);
}

if (action == 'L'){
  Serial.println(action);
  digitalWrite(LED,LOW);
}

 }