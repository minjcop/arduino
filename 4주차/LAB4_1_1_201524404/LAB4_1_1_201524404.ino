void setup() {
  Serial.begin(9600);
}

void loop() {
  String str1 = "One string", str2 = "Another string";
  int n = 1234;
  float f = 3.14;
  char c = 'A';

  Serial.println(str1);
  Serial.println(str1 + " " + str2);
  Serial.println(String(n));
  Serial.println(String(n, BIN));
  Serial.println(String(n, HEX));
  
  // Serial.println(String(f))
  Serial.println(f);

  // 다른 타입의 데이터를 연결하여 새로운 String 객체를 생성한다.
  Serial.println("String + integer : " + String(n));
  String str3 = "String + character : ";
  str3 += n;
  Serial.println(str3);

  while(true);
}
