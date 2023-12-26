#include "WiFiHandler.h"

extern uint8_t senderMacAddress[];
extern int16_t arr[];

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
        for (int i = 0; i < 5; ++i) {
            arr[i] = (int16_t)((incomingData[2 * i + 1] << 8) | incomingData[2 * i]);
        }
        Serial.println("\nReceived remote signal");
        Serial.print("Data : ");
        for (int i = 0; i < 5; ++i) {
            Serial.print(arr[i]);
            if (i < 4) {
            Serial.print(" | ");
            }
        }
        Serial.println();
        // for (int i = 0; i < 2 * 5; i += 2) {
        //     Serial.print(incomingData[i], HEX);
        //     if(i<10){
        //     Serial.print(" | ");
        //     }
        // }
    } else {
        // Data received from an unknown sender
        Serial.println("\nReceived data from an unknown sender");
    }
}