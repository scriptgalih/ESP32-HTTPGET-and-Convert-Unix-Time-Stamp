#include "config.h"
void setup() {
  initialization();
  deviceId = 1;
  pulse = 85;
}

void loop() {
    int raw, pulse_int;
  while (Serial.available()) {
//    raw = Serial.parseInt();
    pulse_int = Serial.parseInt();
    //    Serial.print(char(Serial.read()));
    if (pulse_int != 0) {
//      Serial.println(raw);
      Serial.println(pulse_int);
      kirim_data(pulse_int);
    }
//Serial.flush();
//  delay(1000);
}
}
