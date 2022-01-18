//nodemcu_1 : STA
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

const char *ssid = "UDP_TEST";
const char *pass = "password"; 

unsigned int localPort = 2000; 

IPAddress ServerIP(192,168,4,1);
IPAddress ClientIP(192,168,4,2);

WiFiUDP udp;

char packetBuffer[9];   

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
    Serial.print("Local port: ");
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
