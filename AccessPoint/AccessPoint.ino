#include <ESP8266WiFi.h>

void setup() {
  Serial.begin(9600);
  Serial.println();
  Serial.println("Setting soft-AP ... "); 
  
  boolean result = WiFi.softAP("ESPsoftAP_01", "pass-to-soft-AP");
  if(result == true)
  {
    Serial.println ("Ready"); 
  }
  else
  {
    Serial.println ("Failed!"); 
  }
}

void loop() {
  
  Serial.printf ("Stations connected = %d\n", WiFi.softAPgetStationNum());
  delay(3000);
  
}
