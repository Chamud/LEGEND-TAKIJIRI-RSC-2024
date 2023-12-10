#include "Remote.h"
#include "WifiHandler.h"

// REPLACE WITH desired Loop delay
#define ping 1000
// REPLACE WITH SENDER MAC Address
uint8_t senderMacAddress[] = {0xb0, 0xa7, 0x32, 0x23, 0x16, 0x38};

Remote remote;
WiFiHandler wifiHandler;

void setup() {
    Serial.begin(115200);
    
    if (!wifiHandler.init()) {
        Serial.println("WiFi initialization failed");
        return;
    }
}

void loop() {
    delay(ping);

    remote = wifiHandler.getRemote();

    
}
