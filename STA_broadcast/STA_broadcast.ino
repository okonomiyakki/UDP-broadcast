//nodemcu : STA_broadcast
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#define HIGH 0 
#define LOW 1

const char *ssid = "UDP_TEST"; //local wifi 이름 선언
const char *pass = "password"; //local wifi 비밀번호 선언

IPAddress broadcastIP(192,168,4,255); //local wifi ip주소 선언           
unsigned int localPort = 8266; //포트번호 선언
                          
WiFiUDP udp; //wifi udp통신 시작

void setup(){
    pinMode(16, OUTPUT); //내장 led선언
    
    Serial.begin(9600);
    Serial.println();
    WiFi.begin(ssid, pass); //STAION(단말기)모드로 선언하여 해당 핫스팟에 접속  
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
void loop(){
  
    udp.parsePacket();
    int packetBuffer = udp.read(); //wifi로 수신된 값을 변수에 저장
    int data = packetBuffer;
    if(data == 8) 
       digitalWrite(16, HIGH); //수신된 값이 송신한 값과 일치한다면 'ON'
    else
       digitalWrite(16, LOW); //수신이 안된 상황 혹은 송신중 발생한 에러값을 받으면 'OFF'
    Serial.print(data); 
    delay(100); 
   
}
