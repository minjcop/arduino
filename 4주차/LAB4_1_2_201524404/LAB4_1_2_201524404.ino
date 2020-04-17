void setup() {
  Serial.begin(9600);
}

void loop() {
  // 정렬할 문자열 배열
  String str[5] = {"abc", "ABC", "!@#", "라라라", "123"};

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

  while(true);
}
