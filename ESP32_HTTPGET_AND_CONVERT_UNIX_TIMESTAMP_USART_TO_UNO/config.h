//PREPROCESSOR
#include <WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <Arduino.h>
//#include <WiFiMulti.h>
#include <HTTPClient.h>
/*
 * START ALL CONFIGURATION
 * */
// Define NTP Client to get time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);
//Define SSID AND PASSWORD AP
//const char* ssid     = "Mokhamad Mustaqim";
//const char* password = "taqimlemu20-";
const char* ssid     = "WismaDH_01";
const char* password = "wismaDH01";
/*
 * END ALL CONFIGURATION
 * */
//ALL GLOBAL VARIABLE
String formattedDate;
String dayStamp;
String timeStamp;
char buffer[100];
int deviceId;
int pulse;
//WiFiMulti wifiMulti;
