#include <SoftwareSerial.h>
#include <pitches.h>
#define BT_RX 7
#define BT_TX 8

SoftwareSerial HM10(BT_RX,BT_TX);  

const int alcoholSensor = A5; // 알코올 센서 A5 // 수정됨.
const int deviceLED = 13; // 전원 LED (전원)
const int deviceButton = 7; // 전원키는 버튼
// 시간 경과 계산 위한 변수.
const long int interval = 1000; // 10초로 이후 수정
const int buttonCenter = 14;
const int buttonLeft = 15;
const int buttonRight = 16;
const int buzzer = 2;

void setup() {  
  Serial.begin(9600);
  pinMode(deviceLED, OUTPUT); // 전원 여부 LED
  pinMode(deviceButton, INPUT_PULLUP); // 전원이 꺼져 있을 시에 버튼을 누르면 전원이 꺼짐.
  pinMode(alcoholSensor, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(buttonCenter, OUTPUT);
  pinMode(buttonLeft, OUTPUT);
  pinMode(buttonRight, OUTPUT);
  HM10.begin(9600);
}
boolean onButton(int last, int current);
boolean checkAlcohol();
void dirLED();
void alcoholError();

void loop(){
  int val; // 알코올 값.
  boolean buttonCurrent = false;
  boolean buttonLast = false;
  boolean onLED = false;
  buttonCurrent = digitalRead(deviceButton); // 현재 버튼이 눌려진 것에 대한 여부.
  onLED = onButton(buttonLast, buttonCurrent);
  buttonLast = buttonCurrent;
  digitalWrite(deviceLED, onLED); // onLED 에 따라 전원 여부 보여주는 LED가 켜진다.(전원)

  // 전원 켜진 후  
  // 1) 검사 X인 채 일정 시간 경과되어도 계속 mq3Pin 이 44~46이면.(대기상태가 원래 45정도 나오면) -> 부저0, 스위치 OFF
  if(onLED){
    Serial.println(analogRead(alcoholSensor));
    if(checkAlcohol()){
      // 블루투스 통신 코드
      while(true){ // 이후 수정필요
        dirLED();
        delay(100);
      }
      
    } else {
      onLED = false;
    }
  }
}

boolean onButton(int last, int current){
  boolean result = false;
  if(last == LOW && current == HIGH) // 전원버튼을 눌러서 원래의 꺼진 상태에서 켜진 상태가 되었을 경우
    result = true;
  else if(last == HIGH && current== LOW) // 위의 것과 반대.
    result = false;
    
  return result;
}
boolean checkAlcohol(){
  unsigned long alcoholInitTime = millis();
  boolean pass = false;
  while(true){
    int alcoholValue = analogRead(alcoholSensor);
    if(alcoholInitTime + interval < millis()){
      if(pass)
        return true;
      else
        return false;
    }else{
      if(alcoholValue > 400){
        alcoholError();
        return false;
      }else
        pass = true;
      
    }
  }
  return true;
}

void alcoholError(){
  tone(buzzer, 500, interval); // 부저 10초
} // 부저

void dirLED(){
  boolean center = digitalRead(buttonCenter);
  boolean left = digitalRead(buttonLeft);
  boolean right = digitalRead(buttonRight);
  if(center){
    //HM10.write("center");
    Serial.println("center");
    noTone(buzzer);
    tone(buzzer, 500, interval); 
  }
  if(left){
    //HM10.write("left");
    Serial.println("left");
  }
  if(right){
    //HM10.write("right");
    Serial.println("right");
  }
}
