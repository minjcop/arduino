void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0){
    byte data = Serial.read();
  
    Serial.print("Echo back : ");
    Serial.write(data); // 문자출력
    Serial.print(" ");
    Serial.println(data); // ASCII값 출력
  }
}
