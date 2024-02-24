#include <Servo.h>

#define THRESHOLD_LOW 100 
#define THRESHOLD_HIGH 100 
#define EMGPIN A0 
#define SERVOPIN 9 

Servo servoHand;

void setup() {
  servoHand.attach(SERVOPIN);
  Serial.begin(9600);
}

void loop() {
  int a = analogRead(EMGPIN);
  int servoPosition = map(a, 0, 1023, 0, 180);

  if (a < THRESHOLD_LOW) {
    servoHand.write(0); // Mở bàn tay hoàn toàn
    Serial.println("Open hand");
  } else if (a > THRESHOLD_HIGH) {
    servoHand.write(180); // Đóng bàn tay hoàn toàn
    Serial.println("Close hand");
  }

  delay(100); // Đợi một chút trước khi đọc lại cảm biến
}