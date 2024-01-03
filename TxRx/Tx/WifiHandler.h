// WifiHandler.h

#ifndef WIFI_HANDLER_H
#define WIFI_HANDLER_H

#include <esp_now.h>
#include <WiFi.h>

class WifiHandler {
public:
  WifiHandler(const uint8_t* broadcastAddress);

  bool init();

  void sendData(const int16_t data[]);
  static void onDataRecv(const uint8_t *mac, const uint8_t *incomingData, int len);
private:
  static void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status);

  esp_now_peer_info_t peerInfo;
};

#endif // WIFI_HANDLER_H
