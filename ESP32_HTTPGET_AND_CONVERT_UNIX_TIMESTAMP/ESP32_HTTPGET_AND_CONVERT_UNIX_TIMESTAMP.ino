#include "config.h"
void setup() {
  initialization();
  deviceId = 1;
  pulse = 85;
}

void loop() {
  while (!timeClient.update()) {
    timeClient.forceUpdate();
  }
  formattedDate = timeClient.getFormattedDate();
  long unix_ = timeClient.getEpochTime();
  //long unix_timestamp = date2unix(formattedDate);
  //Serial.println(unix_timestamp);

  HTTPClient http;
  Serial.print("[HTTP] begin...\n");
  Serial.print(unix_);
  
  sprintf(buffer, "https://jantung.masgendut.com/emit-pulse?deviceId=%d&pulse=%d&timestamp=%i000", deviceId, random(75,85), unix_);
  //http.begin("https://jantung.masgendut.com/emit-pulse?deviceId=1&pulse=78&timestamp=1561732852"); //HTTP
  http.begin(buffer);
  Serial.print(buffer);
  int httpCode = http.GET();
  if (httpCode > 0) {
    // HTTP header has been send and Server response header has been handled
    Serial.printf("[HTTP] GET... code: %d\n", httpCode);

    // file found at server
    if (httpCode == HTTP_CODE_OK) {
      String payload = http.getString();
      Serial.println(payload);
    }
  } else {
    Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
  }

  http.end();
  delay(3000);
}
