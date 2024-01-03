#include "WifiHandler.h"
#include "driver.h"

// REPLACE WITH desired Loop delay
#define ping 50
// REPLACE WITH SENDER MAC Address
uint8_t senderMacAddress[] = {0xc4, 0xde, 0xe2, 0xc0, 0x7f, 0xdc};

WiFiHandler wifiHandler;

int loglevel = 3;

int16_t arr[4] = {0,0,0,0};

#define PWM_frequency 8000

driver driverobj = driver();

void setup() {
    Serial.begin(115200);
    
    if (!wifiHandler.init()) {
        Serial.println("WiFi initialization failed");
        return;
    }
    pinMode(MFL,OUTPUT);
    pinMode(MFR,OUTPUT);
    pinMode(MBL,OUTPUT);
    pinMode(MBR,OUTPUT);

    pinMode(MFL_RELAY1,OUTPUT);
    pinMode(MFL_RELAY2,OUTPUT);

    pinMode(MFR_RELAY1,OUTPUT);
    pinMode(MFR_RELAY2,OUTPUT);

    pinMode(MBL_RELAY1,OUTPUT);
    pinMode(MBL_RELAY2,OUTPUT);

    pinMode(MBR_RELAY1,OUTPUT);
    pinMode(MBR_RELAY2,OUTPUT);

    pinMode(KICK,OUTPUT);
    pinMode(KICK_PF,ANALOG);
    analogSetAttenuation(ADC_11db);

    ledcSetup(0, PWM_frequency, 12);
    ledcAttachPin(MFL, 0);

    ledcSetup(1, PWM_frequency, 12);
    ledcAttachPin(MFR, 1);

    ledcSetup(2, PWM_frequency, 12);
    ledcAttachPin(MBL, 2);

    ledcSetup(3, PWM_frequency, 12);
    ledcAttachPin(MBR, 3);
}

void loop() {
    int16_t data[] = {1};
    //wifiHandler.sendData(data);
    delay(ping);  
}
