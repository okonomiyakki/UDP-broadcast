//wemos d1 : AP
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

const char *ssid = "UDP_TEST";
const char *pass = "password"; 

unsigned int localPort = 2000; // 소켓 포트 초기값

IPAddress ServerIP(192,168,4,1);
IPAddress ClientIP(192,168,4,2);
IPAddress ClientIP2(192,168,4,3);

WiFiUDP udp;

void setup()
{
    Serial.begin(9600);
    Serial.println();
    WiFi.softAP(ssid, pass);    // AP 선언
}

void loop()
{
  udp.begin(localPort);
  int r = udp.parsePacket();
    if (!r){
        //시리얼 데이터가 수신될 때 전송
        if(Serial.available()>0){
        udp.beginPacket(ClientIP, 2000);
        
        char a[2];
        a[0]=char(Serial.read()); 
        udp.write(a,1); 
        udp.endPacket();
        
        localPort +=2;
        
        udp.begin(localPort);
        
        udp.beginPacket(ClientIP2, 2002);
        
        a[1]=char(Serial.read()); 
        udp.write(a,1); 
        udp.endPacket();
        
        localPort -=2;
        }
    }
}
