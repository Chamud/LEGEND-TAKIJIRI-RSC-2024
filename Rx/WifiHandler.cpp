// #include "WiFiHandler.h"

// WiFiHandler::WiFiHandler() {
// }

// void WiFiHandler::initializeWiFi() {
//     // Set device as a Wi-Fi Station
//     WiFi.mode(WIFI_STA);

//     // Init ESP-NOW
//     if (esp_now_init() != ESP_OK) {
//         Serial.println("Error initializing ESP-NOW");
//         return;
//     }

//     // Once ESPNow is successfully initialized, register the callback function
//     esp_now_register_recv_cb(onDataRecv);
// }

// void WiFiHandler::onDataRecv(const uint8_t *mac, const uint8_t *incomingData, int len) {
//     // Your callback function code
//     // This function can access member variables of the class if needed
//     struct_message myData;
//     memcpy(&myData, incomingData, sizeof(myData));
//     Serial.print("Bytes received: ");
//     Serial.println(len);
//     Serial.print("Char: ");
//     Serial.println(myData.a);
//     Serial.print("Int: ");
//     Serial.println(myData.b);
//     Serial.print("Float: ");
//     Serial.println(myData.c);
//     Serial.print("Bool: ");
//     Serial.println(myData.d);
//     Serial.println();
// }
