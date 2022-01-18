//wemos d1 : AP_broadcast_LED & lens
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <SoftwareSerial.h>
#define TX 16
#define RX 14 //13
SoftwareSerial lens(RX, TX); 

const char *ssid = "UDP_TEST";
const char *pass = "password"; 

IPAddress broadcastIP(192,168,4,255);
unsigned int localPort = 8266;
                                                      
WiFiUDP udp;

void setup() {

  pinMode(0, INPUT);
  
  lens.begin(9600);
  
  Serial.begin(9600);
  Serial.println();
  WiFi.softAP(ssid, pass);
  
  udp.begin(localPort);
  
}

void loop() {

  int buttonState_1 = lens.read();
  int buttonState_2 = digitalRead(0);
  
  udp.beginPacket(broadcastIP, 8266); 
  if(buttonState_1 == 0 || buttonState_2 == 0){ 
      udp.write(8);
      Serial.println(buttonState_1);
      Serial.print("   ");
      Serial.println(buttonState_2); 
  }
  udp.endPacket();
  
  delay(100);

  //Serial.println(WiFi.RSSI());     
  //delay(500);
 
}
