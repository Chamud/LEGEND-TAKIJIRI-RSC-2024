// WifiHandler.cpp

#include "WifiHandler.h"

extern uint8_t broadcastAddress[];
int receivedData;

WifiHandler::WifiHandler(const uint8_t* broadcastAddress) {
  // Initialize the broadcast address
  memcpy(this->peerInfo.peer_addr, broadcastAddress, 6);
}

bool WifiHandler::init() {
  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);
  Serial.println("--------------SENDER MAC-----------------");
  Serial.println(WiFi.macAddress());

  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return false;
  }

  // get the status of Transmitted packet
  esp_now_register_send_cb(OnDataSent);
  esp_now_register_recv_cb(onDataRecv);

  // Set other peer properties
  this->peerInfo.channel = 0;
  this->peerInfo.encrypt = false;

  // Add peer
  if (esp_now_add_peer(&this->peerInfo) != ESP_OK) {
    Serial.println("Failed to add peer");
    return false;
  }

  return true;
}

void WifiHandler::sendData(const int16_t data[]) {
  uint8_t unitdata[2 * 10];
  for (int i = 0; i < 5; ++i) {
    unitdata[2 * i] = (uint8_t)(data[i] & 0xFF);            // Low byte
    unitdata[2 * i + 1] = (uint8_t)((data[i] >> 8) & 0xFF); // High byte
}
  // Send message via ESP-NOW
  esp_err_t result = esp_now_send(this->peerInfo.peer_addr, unitdata, sizeof(unitdata));

  Serial.print("Sending : ");
  for (int i = 0; i < 5; ++i) {
    Serial.print(data[i]);
    Serial.print(" | ");
  }

  Serial.print(result == ESP_OK ? "Sent OK | " : "Error sending | ");
}

void WifiHandler::OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}

void WifiHandler::onDataRecv(const uint8_t *mac, const uint8_t *incomingData, int len) {
    // Check if the data is received from a known sender
    if (memcmp(mac, broadcastAddress, 6) == 0) {       
      memcpy(&receivedData, incomingData, sizeof(int));
      Serial.print("Received from slave: ");
      Serial.println(receivedData);
    } 
}