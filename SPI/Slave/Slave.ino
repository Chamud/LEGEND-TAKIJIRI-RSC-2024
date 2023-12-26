#include <Wire.h>

const int SLAVE_ADDRESS = 9;

void setup() {
  Serial.begin(115200);
  Wire.begin(SLAVE_ADDRESS);
  Wire.onReceive(receiveEvent);
}

void loop() {
  // Do nothing in the loop
}

void receiveEvent(int numBytes) {
  int sendData = 273;

  if (Wire.available() >= 2) {
    byte highByte = Wire.read();
    byte lowByte = Wire.read();
    int receivedData = (int16_t)((highByte << 8) | lowByte);

    sendResponse(sendData);

    Serial.print("Sent: ");
    Serial.print(sendData);
    Serial.print(" | Received: ");
    Serial.println(receivedData);
  }
}

void sendResponse(int data) {
  Wire.beginTransmission(SLAVE_ADDRESS);
  Wire.write(highByte(data));
  Wire.write(lowByte(data));
  Wire.endTransmission();
}
