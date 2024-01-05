#include "WiFiHandler.h"
#include "logger.h"
#include "driver.h"

extern driver driverobj;
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
        Logger.logln("\nReceived remote signal", 5);
        Logger.log("Received : ", 4);        
        for (int i = 0; i < 2 * 5; i += 2) {
            arr[i] = (int16_t)((incomingData[i + 1] << 8) | incomingData[i]);
            Logger.log(String(arr[i]), 4);
            Logger.log(" | ", 4);
        }
        Logger.logln(" ", 4);
        
        driverobj.DriveMotor(arr[0],arr[1],arr[2]);
        // Adjust 
        bool sensorOn = sensorval>500;
        bool btnPressed = arr[4]==1;
        driverobj.DriveKick(sensorOn, btnPressed);

        esp_err_t result = esp_now_send(mac, (uint8_t *)&sensorOn, sizeof(int));
        Logger.logln(result == ESP_OK ? "Sent OK" : "Error sending", 3);
        if (result != ESP_OK) {
            Logger.logln("Error details: " + String(esp_err_to_name(result)), 2);
        }
    } else {
        // Data received from an unknown sender
        Logger.logln("\nReceived data from an unknown sender", 2);
    }
}