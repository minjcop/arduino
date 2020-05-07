int pin_LED[] = {2, 3};
boolean LED_state1 = false; // LED 상태
boolean LED_state2 = false;
unsigned long time_previous1, time_previous2, time_current1, time_current2;
unsigned long interval[] = {1000, 1000};

void setup() {
  pinMode(A0, INPUT);
  for (int i = 0; i < 2; ++i){
    pinMode(pin_LED[i], OUTPUT);
    digitalWrite(pin_LED[i], LED_state1);
  }
  Serial.begin(9600);
  time_previous1 = millis();
  time_previous2 = millis();
}

void loop() {
  time_current1 = millis();
  time_current2 = millis();
  int adc = analogRead(A0);
  if (time_current1 - time_previous1 >= interval[0]){
    time_previous1 = time_current1;
    LED_state1 = !LED_state1;
    digitalWrite(pin_LED[0], LED_state1);
  }
  interval[0] = map(adc, 0, 1023, 1500, 500); //0.5 ~ 1.5초

  if (time_current2 - time_previous2 >= interval[1]){
    time_previous2 = time_current2;
    LED_state2 = !LED_state2;
    digitalWrite(pin_LED[1], LED_state2);
  }
  interval[1] = map(adc, 0, 1023, 500, 1500);
}
  
