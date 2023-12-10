// SPI_Master.ino
#include <SPI.h>

#define SCLK_PIN SCK   // Serial Clock
#define MOSI_PIN MOSI   // Master Out Slave In
#define MISO_PIN MISO   // Master In Slave Out
#define SS_PIN   SS   // Slave Select/Chip Select

void setup() {
  Serial.begin(115200);

  // Start the SPI library
  SPI.begin();

  // Configure SPI settings for master
  SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));

  // Set the Slave Select pin as OUTPUT
  pinMode(SS_PIN, OUTPUT);

  Serial.println("-------------");
  Serial.println("Master Began");
  Serial.println("-------------");

  Serial.print("MOSI: ");
  Serial.println(MOSI_PIN);

  Serial.print("MISO: ");
  Serial.println(MISO_PIN);
  
  Serial.print("SCK: ");
  Serial.println(SCLK_PIN);
  
  Serial.print("SS: ");
  Serial.println(SS_PIN);
  
  Serial.println("-------------");
}

void loop() {
  digitalWrite(SS_PIN, LOW);  // Select the slave
  delay(10);

  byte dataToSend = 0x55; // Data to be sent
  byte receivedData = SPI.transfer(dataToSend); // Send data and receive from the slave

  digitalWrite(SS_PIN, HIGH); // End communication with the slave

  Serial.print("Sent: ");
  Serial.print(dataToSend, HEX);
  Serial.print(" | Received: ");
  Serial.println(receivedData, HEX);

  delay(1000);
}
