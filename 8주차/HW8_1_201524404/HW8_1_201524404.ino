// 공통 음극 방식( Common Cathode Type )
byte patterns[] = { 0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE4, 0xFE, 0xE6 };
int digit_select_pin[] = {66, 67, 68, 69}; // 자릿수 선택 핀
// a, b, c, d, e, f, g, dp 순서
int segment_pin[] = {58, 59, 60, 61, 62, 63, 64, 65};
int button = 14;
unsigned long time_previous;
unsigned long time_current;
boolean state = false;
boolean state_previous = false;
boolean state_current = false;
int SEGMENT_DELAY = 5;
int count = 0;

void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT);
  
  for(int i = 0; i < 4; ++i){
    pinMode(digit_select_pin[i], OUTPUT);
  }
  for (int i = 0; i < 8; ++i){
    pinMode(segment_pin[i], OUTPUT);
  }
  time_previous = millis();
}

void show_digit(int pos, int num){ // 해당 자리에 숫자 하나를 표시하는 함수
  for (int i = 0; i < 4; ++i){
    if(i + 1 == pos){
      digitalWrite(digit_select_pin[i], LOW);
    }else{
      digitalWrite(digit_select_pin[i], HIGH);
    }
  }
  for (int i = 0; i < 8; ++i){
    boolean on_off = bitRead(patterns[num], 7 - i);
    digitalWrite(segment_pin[i], on_off);
  }
}

void show_3_digit(int number){ // 3자리만 출력
  number = number % 1000;
  int hundreds = number / 100;
  number = number % 100;
  int tens = number / 10;
  int ones = number % 10;
  show_digit(2, hundreds);
  delay(SEGMENT_DELAY);
  show_digit(3, tens);
  delay(SEGMENT_DELAY);
  show_digit(4, ones);
  delay(SEGMENT_DELAY);
}

void loop() {
  state_current = digitalRead(14); // 버튼으로 상태 받아서 그에 따른 방향 진행
  if(state_current){
    if(state_previous == false){
      state = !state;
      state_previous = true;
    }
  }else{
    state_previous = false;
  }
  if(state == 1){
     time_current = millis();
     if(time_current - time_previous >= 1000){
       time_previous = time_current;
       count--;
       if(count < 0){
         count = 999;
       }
     }
     show_3_digit(count);
  }else if(state == 0){
    time_current = millis();
    if(time_current - time_previous >= 1000){
      time_previous = time_current;
      count++;
      if(count > 999){
        count = 0;
      }
    }
    show_3_digit(count);
  }
}
