//wemos d1 : AP_broadcast_LED
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

const char *ssid = "UDP_TEST";
const char *pass = "password"; 

IPAddress broadcastIP(192,168,4,255);
unsigned int localPort = 8266;
                                                      
WiFiUDP udp;

void setup() {

  pinMode(0, INPUT); // D8
  
  Serial.begin(9600);
  Serial.println();
  WiFi.softAP(ssid, pass);
  
  udp.begin(localPort);
}

void loop() {
  int buttonState = digitalRead(0);
  
  udp.beginPacket(broadcastIP, 8266);
  udp.write(buttonState); 
  udp.endPacket();
  delay(100);
  
  Serial.println(WiFi.RSSI());     
  delay(500);
  
}
