//nodemcu_1 : STA_broadcast
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

const char *ssid = "UDP_TEST";
const char *pass = "password"; 

IPAddress broadcastIP(192,168,4,255);
             
unsigned int localPort = 8266;
                          
char packetBuffer[9];                                  

WiFiUDP udp;

void setup()
{
    Serial.begin(9600);
    Serial.println();
    WiFi.begin(ssid, pass);   
  
    Serial.println("");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
    
    Serial.println("Starting UDP");
    udp.begin(localPort);
    Serial.print("port: ");
    Serial.println(udp.localPort());
}

void loop()
{
    int r = udp.parsePacket();
    if (r) 
    {
      udp.read(packetBuffer, 1); 
      Serial.print(packetBuffer);
      delay(20);
    }
}
