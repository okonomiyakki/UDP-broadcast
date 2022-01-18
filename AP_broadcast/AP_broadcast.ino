//wemos d1 : AP_broadcast(mega_1,mega_2)
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <SoftwareSerial.h>
#define TX_1 16
#define RX_1 5
#define TX_2 4
#define RX_2 14
SoftwareSerial lens_1(RX_1, TX_1); //첫번째 mega보드....시리얼통신을 위한 송&수신 포트 설정(mega 에서 wemos로 수신만 할 것이므로, 보드에서는 RX만 사용하고, TX는 아무값이나 넣음)
SoftwareSerial lens_2(RX_2, TX_2); //두번째 mega보드...."

const char *ssid = "UDP_TEST"; //local wifi 이름 선언
const char *pass = "password"; //local wifi 비밀번호 선언

IPAddress broadcastIP(192,168,4,255); //local wifi ip주소 선언
unsigned int localPort = 8266; //포트번호 선언
                                                      
WiFiUDP udp; //wifi udp통신 시작

void setup() {

  lens_1.begin(9600); 
  lens_2.begin(9600);
  
  Serial.begin(9600);
  Serial.println();
  WiFi.softAP(ssid, pass); //AP(핫스팟)모드로 선언하여 다른 보드들로부터의 접근을 허용
  
  udp.begin(localPort); //선언된 포트로 통신시작
  
}
void loop() {
  
  int mega_1 = lens_1.read(); //mega_1보드의 출력값을 정수형태로 받음
  int mega_2 = lens_2.read(); //mega_2보드의 출력값을 정수형태로 받음
  
  udp.beginPacket(broadcastIP, 8266); 
  if(mega_1 == 0 || mega_2 == 0){ 
      udp.write(8); //1번 보드와 2번 보드의 출력 값인 '0'이 wemos 보드에 수신되면 어플이나 wifi수신단으로 '8'이라는 값을 전송(8은 임의의 설정값)
      Serial.println(mega_1); //1번 보드로부터 wifi로 전송된 값을 시리얼모니터에서 0.1초마다 확인
      Serial.print("     ");
      Serial.println(mega_2); //1번 보드로부터 wifi로 전송된 값을 시리얼모니터에서 0.1초마다 확인
  }                           //(예시로 mega_1의 값만이 mega보드로부터 수신 될 경우, mega_2의 값은 값이 없다는 형태인 '-1' 이 됨)
  udp.endPacket();
  delay(100);
  
}

//Serial.println(WiFi.RSSI());     
  //delay(500);
