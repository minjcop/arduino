int pins_LED[] = {2, 3, 4, 5};
int pins_button = 14;

void setup() {
  Serial.begin(9600);
  pinMode(pins_button, INPUT); // 버튼 연결 핀을 입력으로
  for(int i = 0; i < 4; ++i){
    pinMode(pins_LED[i], OUTPUT); // LED 연결 핀을 출력으로.
  }
}

void loop() {
  for(int i = 0; i < 4; ++i){
    
    delay(500) // 0.5초.
  }
  

}
