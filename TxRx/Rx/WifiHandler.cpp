#include "WiFiHandler.h"
#include "logger.h"
#include "driver.h"

extern driver driverobj;
extern uint8_t senderMacAddress[];
extern int16_t arr[];

WiFiHandler::WiFiHandler() {
    memcpy(this->peerInfo.peer_addr, senderMacAddress, 6);
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
    // get the status of Transmitted packet
    esp_now_register_send_cb(OnDataSent);

    // Set other peer properties
    this->peerInfo.channel = 0;
    this->peerInfo.encrypt = false;

    // Add peer
    if (esp_now_add_peer(&this->peerInfo) != ESP_OK) {
        Serial.println("Failed to add peer");
        return false;
    }
    
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
        
        driverobj.DriveMotor(-arr[2],arr[0],arr[4]);
        // Logger.logln(String(sensorval), 4);
        // Adjust 
        int sensorval = analogRead(KICK_PF);
        bool sensorOn = sensorval > 10;
        bool btnPressed = (arr[8] != 0);

        Logger.log("| "+(String)sensorval+" ", 4);
        
        driverobj.DriveKick(sensorOn, btnPressed);

        int sensorvalsend = sensorOn;

        esp_err_t result = esp_now_send(mac, (uint8_t *)&sensorvalsend, sizeof(int));
        Logger.logln(result == ESP_OK ? "Sent : " +String(sensorvalsend) : "Error sending", 3);
        if (result != ESP_OK) {
            Logger.logln("Error details: " + String(esp_err_to_name(result)), 2);
        }
    } else {
        // Data received from an unknown sender
        Logger.logln("\nReceived data from an unknown sender", 2);
    }
}

void WiFiHandler::OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  //Logger.log(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail", 4);
}