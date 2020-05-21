#include <Servo.h>
Servo myServo;
int servoPin = 11;
bool process_it; //
String buff = ""; //
void setup(){
  Serial.begin(9600);
  myServo.attach(servoPin); // 서보 모터 연결
}

void loop(){
  while(Serial.available()){
    char data = Serial.read();
    if(data == '\n'){
      process_it = true;
      break;
    }
    buff += data;
  }
  if(process_it){
    process_it = false;
    int angle = buff.toInt();
    Serial.print(String(">> ") + buff);
    if(angle < 0 || angle > 180){
      Serial.println(" ... invalid angle.");
    }else{
      Serial.println();
      myServo.write(angle);
      delay(3);
    }
    buff = "";
  }
}
