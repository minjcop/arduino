#include <Wire.h>
#include <ADXL345.h>
ADXL345 adxl; // variable adxl is an instance of the ADXL345 library
bool state = false;
int count = 0; // toggle 수 count하기 위한 변수
int ledPin = 2; // LED
void setup(){
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, false);
  adxl.powerOn();
  
  //set activity/ inactivity thresholds (0-255)
  adxl.setActivityThreshold(75); //62.5mg per increment
  adxl.setInactivityThreshold(75); //62.5mg per increment
  adxl.setTimeInactivity(10); // how many seconds of no activity is inactive?
  
  //look of activity movement on this axes - 1 == on; 0 == off 
  adxl.setActivityX(1);
  adxl.setActivityY(1);
  adxl.setActivityZ(1);
  
  //look of inactivity movement on this axes - 1 == on; 0 == off
  adxl.setInactivityX(1);
  adxl.setInactivityY(1);
  adxl.setInactivityZ(1);
  
  //look of tap movement on this axes - 1 == on; 0 == off
  adxl.setTapDetectionOnX(0);
  adxl.setTapDetectionOnY(0);
  adxl.setTapDetectionOnZ(1);
  
  //set values for what is a tap, and what is a double tap (0-255)
  adxl.setTapThreshold(50); //62.5mg per increment
  adxl.setTapDuration(15); //625μs per increment
  adxl.setDoubleTapLatency(80); //1.25ms per increment
  adxl.setDoubleTapWindow(200); //1.25ms per increment
  
  //set values for what is considered freefall (0-255)
  adxl.setFreeFallThreshold(7); //(5 - 9) recommended - 62.5mg per increment
  adxl.setFreeFallDuration(45); //(20 - 70) recommended - 5ms per increment
  
  //setting all interupts to take place on int pin 1
  //I had issues with int pin 2, was unable to reset it
  adxl.setInterruptMapping( ADXL345_INT_SINGLE_TAP_BIT,  ADXL345_INT1_PIN );
  adxl.setInterruptMapping( ADXL345_INT_DOUBLE_TAP_BIT,  ADXL345_INT1_PIN );
  adxl.setInterruptMapping( ADXL345_INT_FREE_FALL_BIT,  ADXL345_INT1_PIN );
  adxl.setInterruptMapping( ADXL345_INT_ACTIVITY_BIT,   ADXL345_INT1_PIN );
  adxl.setInterruptMapping( ADXL345_INT_INACTIVITY_BIT,  ADXL345_INT1_PIN );
  
  //register interupt actions - 1 == on; 0 == off 
  adxl.setInterrupt( ADXL345_INT_SINGLE_TAP_BIT, 1);
  adxl.setInterrupt( ADXL345_INT_DOUBLE_TAP_BIT, 1);
  adxl.setInterrupt( ADXL345_INT_FREE_FALL_BIT, 1);
  adxl.setInterrupt( ADXL345_INT_ACTIVITY_BIT,  1);
  adxl.setInterrupt( ADXL345_INT_INACTIVITY_BIT, 1);
}

void loop(){
  //Boring accelerometer stuff  
  int x, y, z;
  int accelVal; 
  adxl.readXYZ(&x, &y, &z); //read the accelerometer values and store them in variables x,y,z
  if(x > 0){ // x -> toggle shake
    accelVal = x;
  }else{
    accelVal = -x;
  }
  
  // Output x,y,z values - Commented out
  Serial.print("x: " + String(x) + ' ');
  Serial.print("y: " + String(y) + ' ');
  Serial.println("z: " + String(z));
   
  //Fun Stuff!  
  //read interrupts source and look for triggerd actions
  
  //getInterruptSource clears all triggered actions after returning value
  //so do not call again until you need to recheck for triggered actions
  byte interrupts = adxl.getInterruptSource();
 
  // freefall
  /*
  if(adxl.triggered(interrupts, ADXL345_FREE_FALL)){
    Serial.println("freefall");
  } 
  */
  //inactivity
  if(adxl.triggered(interrupts, ADXL345_INACTIVITY)){
    Serial.println("inactivity");
  }
  //activity
  if(adxl.triggered(interrupts, ADXL345_ACTIVITY)){
    Serial.print("activity : "); 
  }
  //double tap and tap
  if(adxl.triggered(interrupts, ADXL345_DOUBLE_TAP))
    Serial.println("double tap");
  else if(adxl.triggered(interrupts, ADXL345_SINGLE_TAP)){
    Serial.println("tap");
    state = !state;
    count += 1;
    Serial.print("toggle : ");
    Serial.println(String(count));
    digitalWrite(ledPin, state);
  }

  if(accelVal > 100) {
    Serial.println("activity : Shaked");
    state = !state;
    count += 1;
    Serial.print("toggle : ");
    Serial.println(String(count));
    digitalWrite(ledPin, state);
  }

  delay(500);
}
