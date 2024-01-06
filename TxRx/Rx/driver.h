#ifndef driver_h
#define driver_h

#include <Arduino.h>
#define MFL 26
#define MFR 25
#define MBL 33
#define MBR 32

#define MFL_RELAY1 15
#define MFL_RELAY2 2

#define MFR_RELAY1 4
#define MFR_RELAY2 16

#define MBL_RELAY1 17
#define MBL_RELAY2 5

#define MBR_RELAY1 18
#define MBR_RELAY2 19

#define KICK 27
#define KICK_PF 35

static int sensorval;
static bool runkick = false;
static int counter = 0;
static int delaytime = 10;
extern int ping;

class driver {
public:
    driver();
    void DriveMotor(int16_t j1, int16_t j2, int16_t j3);
    void DriveKick(bool sensor, bool btn);

};
#endif