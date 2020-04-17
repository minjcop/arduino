int button = 21; // 버튼 연결 핀
void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT_PULLUP); 

}

void loop() {
  Serial.println(digitalRead(button));
  delay(1000);

}
