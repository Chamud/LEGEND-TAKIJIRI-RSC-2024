#include "driver.h"

driver::driver(){}

void driver::DriveMotor(int16_t j1, int16_t j2, int16_t j3){

  int M1 = j1 - j2 - j3;
  int M2 = j1 + j2 - j3;
  int M3 = j1 + j2 + j3;
  int M4 = j1 - j2 + j3;

  Serial.println("Motors : "+String(M1)+" : "+String(M2)+" : "+String(M3)+" : "+String(M4));

  digitalWrite(MFL_RELAY1, M1 > 0 ? LOW : HIGH);
  digitalWrite(MFL_RELAY2, M1 < 0 ? LOW : HIGH);

  digitalWrite(MFR_RELAY1, M2 > 0 ? LOW : HIGH);
  digitalWrite(MFR_RELAY2, M2 < 0 ? LOW : HIGH);

  digitalWrite(MBL_RELAY1, M3 > 0 ? LOW : HIGH);
  digitalWrite(MBL_RELAY2, M3 < 0 ? LOW : HIGH);

  digitalWrite(MBR_RELAY1, M4 > 0 ? LOW : HIGH);
  digitalWrite(MBR_RELAY2, M4 < 0 ? LOW : HIGH);

  ledcWrite(0, 4095 - abs(M1));
  ledcWrite(1, 4095 - abs(M2));
  ledcWrite(2, 4095 - abs(M3));
  ledcWrite(3, 4095 - abs(M4));

//   ledcWrite(0, 4095 - abs(M1) > 4095 ? 4095 : abs(M1));
//   ledcWrite(1, 4095 - abs(M2) > 4095 ? 4095 : abs(M2));
//   ledcWrite(2, 4095 - abs(M3) > 4095 ? 4095 : abs(M3));
//   ledcWrite(3, 4095 - abs(M4) > 4095 ? 4095 : abs(M4));
}

void driver::DriveKick(bool sensor, bool btn){

  counter++;

  if(sensor && !btn && counter > delaytime/ping){
    runkick = false;
    counter = 0;
  }else{
    runkick = true;
  }

  if(runkick){
    digitalWrite(KICK, HIGH);
  }else{
    digitalWrite(KICK, LOW);
  }
}