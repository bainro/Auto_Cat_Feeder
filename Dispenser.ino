#include <TimeAlarms.h>
#include <Time.h>
#include <Servo.h>
#define BUTTON A1

Servo servo1;
int btn = 0;

void setup(){
 setTime(21,16,55,22,12,17); //hr,min,sec,day,month,yr
 Alarm.timerRepeat(3,24,0,Food); 
 servo1.attach(A0); //analog pin 0
 servo1.write(25); //set servo to position 25
}

void loop(){
  btn = digitalRead(BUTTON); //read state of override button  
  if (btn == HIGH){
    Food();
  }
  Alarm.delay(0); 
}

void Food() {
    servo1.write(88);
    Alarm.delay(1500);
    servo1.write(25);
}
