void setup(){
  Serial.begin(9600);
}

void loop(){
  if(Serial.available()){
    long value1 = Serial.parseInt();
    long value2 = Serial.parseInt();

    Serial.println("Enter 2 Integers to add");
    Serial.print(value1);
    Serial.print(" + ");
    Serial.print(value2);
    Serial.print(" = ");
    Serial.println(value1 + value2);
  }    
}
