#include <Servo.h>
Servo myServo;
int servoPin = 11;
unsigned long time_previous, time_current;
int angle;
int angle_step = 1;
void setup(){
  Serial.begin(9600);
  myServo.attach(servoPin); // 서보 모터 연결
}

void loop(){
  int reading = analogRead(A0);
  int interval = map(reading, 0, 1023, 5, 20);
  time_current = millis();
  
  if(time_current - time_previous >= interval){
    time_previous = time_current;
    angle += angle_step;
    if(angle > 180){
      angle = 180;
      angle_step *= -1;
    }else if(angle < 0){
      angle = 0;
      angle_step *= -1;
    }
    myServo.write(angle);
  }
  
  
  int new_interval = map(reading, 0, 1023, 5, 20);
  if(new_interval != interval){
    interval = new_interval;
    Serial.print("Current Interval : ");
    Serial.println(interval);
  }
}
