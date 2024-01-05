#ifndef WiFiHandler_h
#define WiFiHandler_h

#include <WiFi.h>
#include <esp_now.h>

class WiFiHandler {
public:
    WiFiHandler();
    bool init();
    static void onDataRecv(const uint8_t *mac, const uint8_t *incomingData, int len);
private:
  static void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status);

  esp_now_peer_info_t peerInfo;
  
};

#endif
