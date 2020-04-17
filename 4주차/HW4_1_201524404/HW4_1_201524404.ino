void setup() {
  Serial.begin(9600);
}

void loop() {
  int state = 1, len = 0;
  char buffer[128];
  String str[7];
  int index = 1;
  
  while(true){
    if(state == 1){
      if(index > 5)
        break;
      Serial.print("Enter the " + String(index) + "th Word -->");
      state = 2;
    }
    
    while(Serial.available()){
      char data = Serial.read();
      if(data == '\n'){
        buffer[len] = '\0';
        str[index] = buffer;
        if(index < 6){
          Serial.println(str[index++]);
        }else{
          break;
        }
        state = 1;
        len = 0;
        break;
      }
      buffer[len++] = data;
    }
  }

  Serial.println("After Sorting");
  for(int i = 1; i <= 4; ++i){
    for(int j = i+1; j <= 5; ++j){
      int compare = str[i].compareTo(str[j]);
      if(compare > 0){ // 오름차순으로 정렬
        String temp = str[i];
        str[i] = str[j];
        str[j] = temp;
      }
    }
  }

  // 정렬된 문자열 출력3
  for(int i = 1; i <= 5; ++i){
    Serial.println(str[i]);
  }
}
