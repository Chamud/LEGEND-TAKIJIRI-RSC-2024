#include "WiFiHandler.h"

extern Remote remote;
extern uint8_t senderMacAddress[];

WiFiHandler::WiFiHandler() {
}

bool WiFiHandler::init() {
    // Set device as a Wi-Fi Station
    WiFi.mode(WIFI_STA);

    // Init ESP-NOW
    if (esp_now_init() != ESP_OK) {
        Serial.println("Error initializing ESP-NOW");
        return false;
    }

    // Once ESPNow is successfully initialized, register the callback function
    esp_now_register_recv_cb(onDataRecv);
    return true;
}

void WiFiHandler::onDataRecv(const uint8_t *mac, const uint8_t *incomingData, int len) {
    // Check if the data is received from a known sender
    if (memcmp(mac, senderMacAddress, 6) == 0) {
        // Data received from the known sender
        memcpy(&remote, incomingData, sizeof(remote));
        Serial.println("\nReceived remote signal");
        // remote.printValues();
    } else {
        // Data received from an unknown sender
        Serial.println("\nReceived data from an unknown sender");
    }
}

Remote WiFiHandler::getRemote() {
    return remote;
}
