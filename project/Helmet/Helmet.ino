#include <SoftwareSerial.h>
#define BT_RX 7
#define BT_TX 8
SoftwareSerial HM10(BT_RX,BT_TX);
const int lightSensor = A0;
const int pressureSensor = 7;
const int pressureStandard = 400;

// 좌우 조명.
void setup() {
  Serial.begin(9600);
  HM10.begin(9600);
  pinMode(lightSensor, INPUT);
  pinMode(pressureSensor, INPUT);
}

void loop() {
  int lightValue = analogRead(lightSensor);
  if(lightValue < 100){ // 값이 낮을수록 어두운 것.
    // 조명 켜짐
  }

  if(HM10.available()){// 블루투스 통신 수신시
    if(isWeared())
      HM10.write("weared");
    else{
      HM10.write("unweared");
    }
  }
}

bool isWeared() {
  if (analogRead(pressureSensor) > 400)
      return true;
  else
      return false;
}
