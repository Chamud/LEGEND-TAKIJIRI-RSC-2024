// WifiHandler.h

#ifndef WIFI_HANDLER_H
#define WIFI_HANDLER_H

#include <esp_now.h>
#include <WiFi.h>
#include "Remote.h"

class WifiHandler {
public:
  WifiHandler(const uint8_t* broadcastAddress);

  bool init();

  void sendData(const Remote &data);

private:
  static void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status);

  esp_now_peer_info_t peerInfo;
};

#endif // WIFI_HANDLER_H
