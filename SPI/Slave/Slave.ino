// SPI_Slave.ino
#include <SPI.h>

#define SCLK_PIN_SLAVE SCK
#define MOSI_PIN_SLAVE MOSI
#define MISO_PIN_SLAVE MISO
#define SS_PIN_SLAVE   SS

void setup() {
  Serial.begin(115200);

  // Start the SPI library
  SPI.begin();

  // Configure SPI settings for slave
  SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));

  // Set Slave Select pin as INPUT
  // Set Slave Select pin as INPUT_PULLUP
  pinMode(SS_PIN_SLAVE, INPUT_PULLUP);

  Serial.println("-------------");
  Serial.println("Slave Began");
  Serial.println("-------------");

  Serial.print("MOSI: ");
  Serial.println(MOSI_PIN_SLAVE);

  Serial.print("MISO: ");
  Serial.println(MISO_PIN_SLAVE);

  Serial.print("SCK: ");
  Serial.println(SCLK_PIN_SLAVE);

  Serial.print("SS: "); 
  Serial.println(SS_PIN_SLAVE);

  Serial.println("-------------");
}

void loop() {
  if (digitalRead(SS_PIN_SLAVE) == LOW) {  // Check if selected by master
    
    byte dataToSend = 0x08; // Data to be sent
    byte receivedData = SPI.transfer(dataToSend); 

    Serial.print("Sent: ");
    Serial.print(dataToSend, HEX);
    Serial.print(" | Received: ");
    Serial.println(receivedData, HEX);

  }
}
