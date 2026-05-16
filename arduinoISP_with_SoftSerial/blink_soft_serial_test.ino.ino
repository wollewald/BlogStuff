#include<SoftwareSerial.h>
SoftwareSerial softSerial(99, 4); // RX, TX - we don't need RX

void setup() {
  softSerial.begin(9600); // set Baud 19200 in Serial Monitor!!!
  pinMode(PB3, OUTPUT);
}

void loop() {
  digitalWrite(PB3, HIGH); 
  delay(1000);                      
  digitalWrite(PB3, LOW); 
  delay(1000);              
  softSerial.println("Hello World");
}
