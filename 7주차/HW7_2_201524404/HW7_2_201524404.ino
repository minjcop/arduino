#include <pitches.h>
int melody[] = { 0, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5};
int speakerPin = 55; // A1 (디지털 55번 핀)
int noteDuration = 4; // 4분 음표
void setup(){
  Serial.begin(9600);
  pinMode(A2, INPUT);
}

void loop(){
  int adc = analogRead(A2); // 가변 저항 A2(디지털 56번 핀)
  int res = map(adc, 0, 1023, 0, 8); // 0 ~ 1023 가변저항을 나눔.
  int noteLength = 1000 / noteDuration;
  for(int i = 0; i < 9; ++i){ // 0 : 무음 ~ 8 : 시
    if(i == res)
      tone(speakerPin, melody[i], noteLength);
  }
}
