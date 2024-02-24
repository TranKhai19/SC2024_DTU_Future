#include <Servo.h>

#define THRESHOLD 500 // Điều chỉnh ngưỡng theo tín hiệu EMG của EMG A10-09
#define EMGPIN A0 // Pin analog kết nối với EMG A10-09
#define LITTLEPIN  3 // Digital pin sử dụng cho servo ngón tay nhỏ
#define RINGPIN    5 // Digital pin sử dụng cho servo ngón tay áp út
#define MIDDLEPIN  6 // Digital pin sử dụng cho servo ngón tay giữa
#define INDEXPIN   9 // Digital pin sử dụng cho servo ngón tay trỏ
#define THUMBPIN  10 // Digital pin sử dụng cho servo ngón tay cái

#define LITTLE 1
#define RING   2
#define MIDDLE 3
#define INDEX  4
#define THUMB  5

Servo servoLittleFinger;
Servo servoRingFinger;
Servo servoMiddleFinger;
Servo servoIndexFinger;
Servo servoThumbFinger;

int finger;

void openhand(){for(finger = 1; finger < 6; finger++){openFinger(finger);}}
void closehand(){for(finger = 1; finger < 6 ; finger++){closeFinger(finger);}}



void openFinger(int finger){
  if(finger==LITTLE){servoLittleFinger.write(0);} // Ngón tay nhỏ
  else if(finger==RING){servoRingFinger.write(170);}// Ngón tay áp út
  else if(finger==MIDDLE){servoMiddleFinger.write(170);}// Ngón tay giữa
  else if(finger==INDEX){servoIndexFinger.write(170);}// Ngón tay trỏ
  else if(finger==THUMB){servoThumbFinger.write(0);}// Ngón tay cái
}

void closeFinger(int finger){
  if(finger==LITTLE){servoLittleFinger.write(170);} // Ngón tay nhỏ
  else if(finger==RING){servoRingFinger.write(0);}// Ngón tay áp út
  else if(finger==MIDDLE){servoMiddleFinger.write(0);}// Ngón tay giữa
  else if(finger==INDEX){servoIndexFinger.write(0);}// Ngón tay trỏ
  else if(finger==THUMB){servoThumbFinger.write(170);}// Ngón tay cái
}

void setup(){
  
  Serial.begin(115200);

  servoLittleFinger.attach(LITTLEPIN);
  servoRingFinger.attach(RINGPIN);
  servoMiddleFinger.attach(MIDDLEPIN);
  servoIndexFinger.attach(INDEXPIN);
  servoThumbFinger.attach(THUMBPIN);

}

void loop() {

  int value = analogRead(EMGPIN);
  if(value > THRESHOLD)
  {closehand();}
  else
  {openhand();}
  Serial.println(value);
}