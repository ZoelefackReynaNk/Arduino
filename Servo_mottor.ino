#include <Servo.h>

int servopin=9;
int servopos=0;
int dt=1000;
Servo myServo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myServo.attach(servopin);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (servopos <= 180){
    myServo.write(servopos);
    delay(dt);
    servopos = servopos + 15;
  }
  servopos = 0;
  delay(dt);
}
