void setup() {
  Serial.begin(9600);
}

void loop() {
  int state = 1, len = 0;
  char buffer[128];

  while(true){
    if(state == 1){
      Serial.print("Enter a String --> " );
      state = 2;
    }
    while(Serial.available()){
      char data = Serial.read();
      if(data == '\n'){
        buffer[len] = '\0';
        String in_str = buffer;
        Serial.println(in_str + " [" + in_str.length() + "]");
        state = 1;
        len = 0;
        break;
      }
      buffer[len++] = data;
    }
  }

  // 문자열 정렬
  for(int i = 0; i < 4; ++i){
    for(int j = i+1; j < 5; ++j){
      int compare = str[i].compareTo(str[j]);
      if(compare > 0){ // 오름차순으로 정렬
        String temp = str[i];
        str[i] = str[j];
        str[j] = temp;
      }
    }
  }

  // 정렬된 문자열 출력3
  for(int i = 0; i < 5; ++i){
    Serial.println(String(i) + " : " + str[i]);
  }
}
