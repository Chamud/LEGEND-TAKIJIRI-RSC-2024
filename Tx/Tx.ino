#include "Remote.h"
#include "WifiHandler.h"

#define J1_X_PIN A3
#define J1_Y_PIN A4

#define J2_X_PIN A5

#define J3_X_PIN A7
#define J3_Y_PIN A10

#define J4_X_PIN A5
#define J5_X_PIN A5
#define J6_Y_PIN A5

#define S1_PIN 5
#define S2_PIN 18
#define S3_PIN 18

// REPLACE WITH RECEIVER MAC Address
uint8_t broadcastAddress[] = {0xc4, 0xde, 0xe2, 0xc0, 0x7f, 0xdc};

WifiHandler wifiHandler(broadcastAddress);

Remote remote(J1_X_PIN, J1_Y_PIN,
                J2_X_PIN, 
                J3_X_PIN, J3_Y_PIN,
                J4_X_PIN, 
                J5_X_PIN,
                J6_Y_PIN,
                S1_PIN, S2_PIN, S3_PIN);

void setup() {
    Serial.begin(115200);
    remote.initialize();
    
    if (!wifiHandler.init()) {
        Serial.println("WiFi initialization failed");
        return;
    }
}

void loop() {
    remote.readValues();

    wifiHandler.sendData(remote);

    delay(1000);
}
