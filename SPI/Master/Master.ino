#include <Wire.h>

const int SLAVE_ADDRESS = 9;

void setup() {
  Serial.begin(115200);
  Wire.begin();
}

void loop() {
  int dataToSend = 567;
  Wire.beginTransmission(SLAVE_ADDRESS);
  Wire.write(highByte(dataToSend));
  Wire.write(lowByte(dataToSend));
  Wire.endTransmission();

  Serial.print("Sent: ");
  Serial.print(dataToSend);

  Wire.requestFrom(SLAVE_ADDRESS, 2);
  if (Wire.available() >= 2) {
    byte highByteResponse = Wire.read();
    byte lowByteResponse = Wire.read();
    int receivedResponse = (int16_t)((highByteResponse << 8) | lowByteResponse);

    Serial.print(" | Received: ");
    Serial.println(receivedResponse);
  }

  delay(100);
}
