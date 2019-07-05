#include "config.h"
void setup() {
  initialization();
}

void loop() {
while (!timeClient.update()) {
    timeClient.forceUpdate();
  }
  formattedDate = timeClient.getFormattedDate();
  long unix_timestamp = date2unix(formattedDate);
  Serial.println(unix_timestamp);
  delay(1000);
}
