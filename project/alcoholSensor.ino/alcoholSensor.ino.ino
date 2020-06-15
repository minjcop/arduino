#include <pitches.h>

const int alcoholSensor = A5; // 알코올 센서 A5.
const int deviceLED = 13; // 전원 LED (전원)
const int deviceButton = 7; // 전원키는 버튼
// 시간 경과 계산 위한 변수.
const long int interval = 10000; // 10초

const int buzzer = 2;

void setup() {  
  Serial.begin(9600);
  pinMode(deviceLED, OUTPUT); // 전원 여부 LED
  pinMode(deviceButton, INPUT); // 전원이 꺼져 있을 시에 버튼을 누르면 전원이 꺼짐.
  pinMode(alcoholSensor, INPUT);
  pinMode(buzzer, OUTPUT);
}
boolean onButton(int last, int current);
boolean checkAlcohol();
void alcoholError();

void loop(){
  int val; // 알코올 값.
  boolean buttonCurrent = LOW;
  boolean buttonLast = LOW;
  
  boolean onLED = false;
  buttonCurrent = digitalRead(deviceButton); // 현재 버튼이 눌려진 것에 대한 여부.
  onLED = onButton(buttonLast, buttonCurrent);
  buttonLast = buttonCurrent;
  digitalWrite(deviceLED, onLED); // onLED 에 따라 전원 여부 보여주는 LED가 켜진다.(전원)

  // 전원 켜진 후  
  // 1) 검사 X인 채 일정 시간 경과되어도 계속 mq3Pin 이 44~46이면.(대기상태가 원래 45정도 나오면) -> 부저0, 스위치 OFF
  if(onLED){
    
    if(checkAlcohol()){
      // 블루투스 통신 코드
    } else {
      onLED = false;
    }
  }
}

boolean onButton(int last, int current){
  boolean result = false;
  if(last = LOW && current = HIGH) // 전원버튼을 눌러서 원래의 꺼진 상태에서 켜진 상태가 되었을 경우
    result = true;
  else if(last = HIGH && current = LOW) // 위의 것과 반대.
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
      if(alcoholValue > 100){
        alcoholError();
        return false;
      }else if(alcoholValue < 43 || alcoholValue > 47){
        pass = true;
      }
    }
  }
  return true;
}

void alcoholError(){} // 부저
