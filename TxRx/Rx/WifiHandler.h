#ifndef WiFiHandler_h
#define WiFiHandler_h

#include <WiFi.h>
#include <esp_now.h>

class WiFiHandler {
public:
    WiFiHandler();
    bool init();
    static void onDataRecv(const uint8_t *mac, const uint8_t *incomingData, int len);
};

#endif
