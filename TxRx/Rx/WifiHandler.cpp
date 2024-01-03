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
    esp_now_register_send_cb(OnDataSent);
    esp_now_register_recv_cb(onDataRecv);
    return true;
}

void WiFiHandler::sendData(const int16_t data[]) {
    uint8_t kicksensor[2];
    kicksensor[0] = (uint8_t)(data[0] & 0xFF);            
    kicksensor[1] = (uint8_t)((data[0] >> 8) & 0xFF); 
    esp_err_t result = esp_now_send(senderMacAddress, kicksensor, sizeof(kicksensor));   
    
    Logger.log("Sending "+String(data[0])+" | ", 4);
    Logger.logln(result == ESP_OK ? "Sent OK | " : "Error sending | ", 4);
    // Print more details if there's an error
    if (result != ESP_OK) {
        Logger.logln("Error details: " + String(esp_err_to_name(result)), 2);
    }
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

    } else {
        // Data received from an unknown sender
        Logger.logln("\nReceived data from an unknown sender", 2);
    }
}

void WiFiHandler::OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Logger.logln(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail", 4);
}