#include <LiquidCrystal.h>
LiquidCrystal lcd(44, 45, 46, 47, 48, 49);
byte user1[8] = {
  B00000, B10000, B00111, B01000, B01000, B01000, B00111, B00000
};
void setup(){
  Serial.begin(9600);
}

void readTemperature() {
  int reading = analogRead(55); // A1
  
  float voltage = reading * 5.0 / 1024.0; 
  
  // 전압 * 100하면 섭씨온도 얻을 수 있다.
  float temperatureC = voltage * 100; 
  
  lcd.begin(16, 2);
  lcd.print("Temp :");
  lcd.setCursor(6, 0);
  lcd.print(temperatureC);
  lcd.createChar(0, user1);
  lcd.setCursor(12, 0);
  lcd.write(byte(0));
}
void readIlluminance() {
  int reading = analogRead(56); // A2
  // ADC 반환 값을 전압으로 변환
  float voltage = reading * 5.0 / 1024.0;
  
  lcd.setCursor(0, 1);
  lcd.print("Light : ");
  lcd.setCursor(7, 1);
  lcd.print(voltage);
}

void loop() {
  readTemperature();
  readIlluminance();
  delay(1000);
}
