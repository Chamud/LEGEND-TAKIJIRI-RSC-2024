#include "WiFiHandler.h"
#include "logger.h"

extern uint8_t senderMacAddress[];
extern int16_t arr[];

WiFiHandler::WiFiHandler() {
}

bool WiFiHandler::init() {
    // Set device as a Wi-Fi Station
    WiFi.mode(WIFI_STA);
    Serial.println("--------------Receiver MAC------------------");
    Serial.println(WiFi.macAddress());

    // Init ESP-NOW
    if (esp_now_init() != ESP_OK) {
        Logger.logln("Error initializing ESP-NOW", 2);
        return false;
    }
    Logger.logln("Initialized ESP-NOW", 2);
    // Once ESPNow is successfully initialized, register the callback function
    esp_now_register_recv_cb(onDataRecv);
    return true;
}

void WiFiHandler::onDataRecv(const uint8_t *mac, const uint8_t *incomingData, int len) {
    // Check if the data is received from a known sender
    if (memcmp(mac, senderMacAddress, 6) == 0) {
        // Data received from the known sender
        // for (int i = 0; i < 8; ++i) {
        //     arr[i] = (int16_t)((incomingData[2 * i + 1] << 8) | incomingData[2 * i]);
        //     arr[i] -= 255;
        // }

        Logger.logln("\nReceived remote signal", 4);
        Logger.log("Data : ", 4);
        for (int i = 0; i < 8; ++i) {
            Logger.log(String(arr[i]), 4);
            if (i < 4) {
                Logger.log(" | ", 4);
            }
        }
        Logger.logln("",4);
        for (int i = 0; i < 2 * 8; i += 2) {
            Logger.log(String(incomingData[i]), 4);
            if(i<10){
            Logger.log(" | ", 4);
            }
        }
    } else {
        // Data received from an unknown sender
        Logger.logln("\nReceived data from an unknown sender", 2);
    }
}