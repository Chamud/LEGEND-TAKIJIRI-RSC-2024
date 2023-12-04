#include "Remote.h"
#include "WifiHandler.h"

Remote remote;

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
    remote.printValues();
    wifiHandler.sendData(remote);

    delay(1000);
}
