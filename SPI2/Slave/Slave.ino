// Slave.ino
#include <SPI.h>
#include "Data.h"

#define SS_PIN 5
int count = 1;

void setup() {
  Serial.begin(115200);
  pinMode(SS_PIN, INPUT); // Set slave select pin as input
  SPI.begin(); 
  
  Serial.println("Pin Config");
  Serial.print("MOSI: ");
  Serial.println(MOSI);
  Serial.print("MISO: ");
  Serial.println(MISO);
  Serial.print("SCK: ");
  Serial.println(SCK);
  Serial.print("SS: ");
  Serial.println(SS_PIN);
}

void loop() {
  Serial.print(count++);
  Serial.print(" ");

  if (digitalRead(SS_PIN) == LOW) { 
    Serial.println("Slave is selected.");
    byte receivedData = SPI.transfer(0);
    Serial.println("Received Data: " + String((int)receivedData));

    delay(1000);
  } else {
    Serial.println("Slave is not selected.");
    delay(1000);
  }
}

// Data receivedDatas;
//     Serial.print(count++);
//     Serial.print(" ");
//     receivedDatas.printData();