int lux = 56; // 조도
int pins_LED[] = {2, 3, 4, 5};
void setup() {
  Serial.begin(9600);
  for(int i = 0; i < 4; ++i){
    pinMode(pins_LED[i], OUTPUT);
  }
}

void loop() {
  int led;
  int reading = analogRead(lux);
  led = map(reading, 950, 1023, 0, 5); // 0 ~ 5 유의미한 결과를 나타내기 위해 값을 조정했습니다.

  for (int i = 0; i < 4; ++i){
    if (i < led)
      digitalWrite(pins_LED[i], HIGH);
    else
      digitalWrite(pins_LED[i], LOW);
  }
}
