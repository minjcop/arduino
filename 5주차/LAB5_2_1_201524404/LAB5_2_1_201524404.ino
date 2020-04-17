int RGB_LED[] = {6, 7, 8};

void setup() {
  Serial.begin(9600);
  for(int i = 0; i < 3; ++i){
    pinMode(RGB_LED[i], OUTPUT);
  }

}

void loop() {
  //Blue
  digitalWrite(RGB_LED[1], HIGH);
  digitalWrite(RGB_LED[2], HIGH);
  for(int i = 255; i >= 0; i--){
    analogWrite(RGB_LED[0], i);
    delay(10);
  }
  //Green
  digitalWrite(RGB_LED[0], HIGH);
  digitalWrite(RGB_LED[2], HIGH);
  for(int i = 255; i >= 0; i--){
    analogWrite(RGB_LED[1], i);
    delay(10);
  }
  //Red
  digitalWrite(RGB_LED[0], HIGH);
  digitalWrite(RGB_LED[1], HIGH);
  for(int i = 255; i >= 0; i--){
    analogWrite(RGB_LED[2], i);
    delay(10);
  }

  

}
