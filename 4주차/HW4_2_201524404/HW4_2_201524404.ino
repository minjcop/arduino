int pins[] = {2,3,4,5};
int button = 14;
int state;

boolean state_current;
void setup() {
  Serial.begin(9600);
  for(int i = 0; i < 4; i++) {
    pinMode(pins[i], OUTPUT);
    digitalWrite(pins[i], LOW);
  }
  pinMode(button, INPUT);
}

void loop() {
  state_current = digitalRead(button);
  for(int j = 0; j < 4; j++){
    if(state_current==1){
      state = 3-j;
      for (int i = 0; i < 4; i++){
        if (i==state) {
          Serial.print("0 ");
          digitalWrite(pins[i], HIGH);
        }
        else{
          Serial.print("X ");
          digitalWrite(pins[i], LOW);
        }
      } 
    }else{
      state = j;
      for (int i = 0; i < 4; i++){
        if (i==state) {
          Serial.print("0 ");
          digitalWrite(pins[i], HIGH);
        }else{
          Serial.print("X ");
          digitalWrite(pins[i], LOW);
        }
      }
    }
    Serial.println();
    delay(500);
  }
}
