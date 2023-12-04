#ifndef WiFiHandler_h
#define WiFiHandler_h

#include <WiFi.h>
#include <esp_now.h>
#include "Remote.h"

class WiFiHandler {
public:
    WiFiHandler();
    bool init();
    Remote getRemote();
    static void onDataRecv(const uint8_t *mac, const uint8_t *incomingData, int len);
};

#endif
