int pins[] = {2, 3, 4, 5};
int index = 0;
int pattern = 1, shift;
void setup() {
  Serial.begin(9600);
  for(int i = 0; i < 4; ++i){
    pinMode(pins[i], OUTPUT);
    digitalWrite(pins[i], LOW);
  }
} 

void loop() {
  if(index < 4) shift = index;
  else shift = 6 - index;
  
  for(int i = 0; i <= shift; ++i){ //shift = 0 1 2 3 2 1
    if(i <= pattern/pow(2, i)){
      Serial.print("O ");
      digitalWrite(pins[i], HIGH);
      delay(100);
    }
    pattern = (pattern << 1) | 0x01;
  }
  index++;
  if(index == 6){
    index = 0;
    pattern = 1;
  }
  for(int i = 0; i < 3; ++i){
    digitalWrite(pins[i], LOW);
  }
  Serial.println();
  delay(1000);

}
