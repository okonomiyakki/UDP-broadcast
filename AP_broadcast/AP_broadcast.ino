//wemos d1 : AP_broadcast
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

const char *ssid = "UDP_TEST";
const char *pass = "password"; 

IPAddress broadcastIP(192,168,4,255);
           
unsigned int localPort = 8266;
                          
                              

WiFiUDP udp;

void setup() {
  Serial.begin(9600);
  Serial.println();
  WiFi.softAP(ssid, pass);
  
  udp.begin(localPort);
}

void loop() {
  int r = udp.parsePacket();
    if (!r){
        if(Serial.available()>0){
        udp.beginPacket(broadcastIP, 8266);
        
        char a[1];
        a[0]=char(Serial.read()); 
        udp.write(a,1); 
        udp.endPacket();
        
        }
    }
    //Serial.println(WiFi.RSSI());
    
    
    //delay(3000);
}

 
