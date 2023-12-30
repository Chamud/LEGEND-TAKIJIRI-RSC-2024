#include "WiFiHandler.h"
#include "logger.h"
#include "driver.h"

extern uint8_t senderMacAddress[];
extern int16_t arr[];
extern driver M1;
extern driver M2;
extern driver M3;
extern driver M4;

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
        Logger.logln("\nReceived remote signal", 5);
        Logger.log("Data : ", 4);        
        for (int i = 0; i < 2 * 4; i += 2) {
            arr[i] = (int16_t)((incomingData[i + 1] << 8) | incomingData[i]);
            Logger.log(String(arr[i]), 4);
            Logger.log(" | ", 4);
        }
        Logger.logln("",4);
        
        M1.run(arr[0]);
        M2.run(arr[1]);
        M3.run(arr[2]);
        M4.run(arr[3]);               
    } else {
        // Data received from an unknown sender
        Logger.logln("\nReceived data from an unknown sender", 2);
    }
}