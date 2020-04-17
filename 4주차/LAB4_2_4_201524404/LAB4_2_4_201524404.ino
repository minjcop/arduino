int pins_LED[] = {2, 3}; // LED 연결핀
//버튼 연결 핀(15 : 풀다운 저항, 16 : 풀업 저항)
int pins_button[] = {15, 16};

boolean on_off_pattern[2][2] = { // 점멸 패턴
  {false, true}, // pull-down 저항 사용
  {true, false} // pull-up 저항 사용
};

void setup() {
  Serial.begin(9600);
  for(int i = 0; i < 2; ++i){
    pinMode(pins_button[i], INPUT);
    pinMode(pins_LED[i], OUTPUT);
  }

}

void loop() {
  for(int i = 0; i < 2; ++i){
    boolean state = digitalRead(pins_button[i]);
    digitalWrite(pins_LED[i], on_off_pattern[i][state]);
    Serial.print(on_off_pattern[i][state]);
    Serial.print(" ");
  }
  Serial.println();
  delay(1000);

}
