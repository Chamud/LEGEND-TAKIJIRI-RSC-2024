// WifiHandler.cpp

#include "WifiHandler.h"

WifiHandler::WifiHandler(const uint8_t* broadcastAddress) {
  // Initialize the broadcast address
  memcpy(this->peerInfo.peer_addr, broadcastAddress, 6);
}

bool WifiHandler::init() {
  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return false;
  }

  // get the status of Transmitted packet
  esp_now_register_send_cb(OnDataSent);

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

void WifiHandler::sendData(const Remote &data) {
  // Send message via ESP-NOW
  esp_err_t result = esp_now_send(this->peerInfo.peer_addr, (uint8_t *)&data, sizeof(data));

  if (result == ESP_OK) {
    Serial.println("Sent with success");
  } else {
    Serial.println("Error sending the data");
  }
}

void WifiHandler::OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}
