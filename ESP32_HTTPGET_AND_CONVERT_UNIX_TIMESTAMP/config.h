//PREPROCESSOR
#include <WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

/*
 * START ALL CONFIGURATION
 * */
// Define NTP Client to get time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);
//Define SSID AND PASSWORD AP
const char* ssid     = "Naway-Tech";
const char* password = "00000001";
/*
 * END ALL CONFIGURATION
 * */
//ALL GLOBAL VARIABLE
String formattedDate;
String dayStamp;
String timeStamp;
