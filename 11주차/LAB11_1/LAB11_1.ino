// 초음파 센서
int trigPin = 3;
int echoPin = 2;
int motionPin = 8; // 적외선
int led1Pin = 12;
int led2Pin = 11;
int led1Bright;
void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motionPin, INPUT);
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
}

void loop() {
  int motion = digitalRead(motionPin);
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);
  float duration = pulseIn(echoPin, HIGH);
  float distance = duration * 340 / 10000 / 2;
  Serial.println(String("Distance(cm): ") + distance);
  
  if(distance > 100){
    led1Bright = 0;
  }else{
    led1Bright = map(distance, 100, 0, 0, 255);
  }
  Serial.println(led1Bright);
  analogWrite(led1Pin, led1Bright);

  if(motion == 1){
    Serial.println("Motion detected");
    digitalWrite(led2Pin, HIGH);
  }else{
    digitalWrite(led2Pin, LOW);
  }
  // led1Pin, led1Bright, led2Pin 이 없으며, trigPin, echoPin이 있다.
  delay(500);

}
