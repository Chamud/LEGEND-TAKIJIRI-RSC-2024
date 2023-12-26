// Master.ino
#include <SPI.h>
#include "Data.h"

#define SS_PIN1 5
#define SS_PIN2 17
int count = 1;

void setup() {
  Serial.begin(115200);
  SPI.begin();

  pinMode(SS_PIN1, OUTPUT);
  digitalWrite(SS_PIN1, LOW); 
  pinMode(SS_PIN2, OUTPUT);
  digitalWrite(SS_PIN2, LOW); 
  
  Serial.println("Pin Config");
  Serial.print("MOSI: ");
  Serial.println(MOSI);
  Serial.print("MISO: ");
  Serial.println(MISO);
  Serial.print("SCK: ");
  Serial.println(SCK);
  Serial.print("SS1: ");
  Serial.println(SS_PIN1);

}

void loop() {
  Serial.print(count++);
  Serial.print(" ");
  
  digitalWrite(SS_PIN1, HIGH); 
  Serial.println("Slave is selected.");
  byte dataToSend = 42; 
  SPI.transfer((byte)dataToSend);

  digitalWrite(SS_PIN1, LOW); 
  Serial.println("Slave is Released.");
  delay(3000);
}


// Data sendData(42, 87); // Example data
//   Serial.print(count++);
//   Serial.print(" ");
//   sendData.printData();
//   delay(3000);




