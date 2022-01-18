#include <SoftwareSerial.h>
#define TX 14
#define RX 15
SoftwareSerial lens(RX, TX); //시리얼통신을 위한 송&수신 포트 설정(mega 에서 wemos로 전송만 할 것 이므로 보드에서는 TX만 사용....RX는 아무값이나 넣음) 

void setup(){
  
  Serial.begin(9600);
  
  lens.begin(9600); 

  pinMode(13, INPUT); //허스키렌즈의 입력값을 대신 할 버튼 선언
  
}

void loop(){
  
  int buttonState = digitalRead(13); //버튼의 상태를 정수형태로 선언
  if(buttonState == 0){
      lens.write(buttonState);  //시리얼 통신을 통해 wemos보드로 버튼의 상태값 전송....버튼이 눌렸을 때 0을 전송
      Serial.print(buttonState); //시리얼 모니터로 입력값을 0.1초마다 확인
  }
  delay(100);
}
