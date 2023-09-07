#include <Servo.h>

int lightpin=A0;
int lightval;
int sunnypin=8;
int darkpin=4;
int cloudypin=6;
int servopin=9;
int servopos;
int dt=1000;
Servo myServo;

void setup() {
  // put your setup code here, to run once:
  pinMode(lightpin, INPUT);
  pinMode(sunnypin, OUTPUT);
  pinMode(darkpin, OUTPUT);
  pinMode(cloudypin, OUTPUT);
  pinMode(servopin, OUTPUT);
  Serial.begin(9600);
  myServo.attach(servopin);
}

void loop() {
  // put your main code here, to run repeatedly:
    lightval = analogRead(lightpin);
 // servopos = (180./1023.)*lightval;
  servopos = (-16./63.)*lightval + 16.*780./63.;
  Serial.print("lightval is: ");
  Serial.println(lightval);
  Serial.print("servopos is: ");
  Serial.println(servopos);
  if (lightval <= 164){
    digitalWrite(darkpin, HIGH);
    digitalWrite(sunnypin, LOW);
    digitalWrite(cloudypin, LOW);
    //myServo.write(0);
  }
  else if ((lightval > 164) &&(lightval <= 600)){
    digitalWrite(darkpin, LOW);
    digitalWrite(sunnypin, LOW);
    digitalWrite(cloudypin, HIGH);
    //myServo.write(90);
  }
  else {
    digitalWrite(darkpin, LOW);
    digitalWrite(sunnypin, HIGH);
    digitalWrite(cloudypin, LOW);
    
    //myServo.write(180);
  }
  myServo.write(servopos);
  //delay(1000);
  
//  digitalWrite(buzzpin, HIGH);
//  delay(buzzdelay);
//  digitalWrite(buzzpin, LOW);
//  delay(buzzdelay);
//  Serial.println(lightval);
////  delay(250);
  
//  while (servopos <= 180){
//    myServo.write(servopos);
//    delay(dt);
//    servopos = servopos + 15;
//  }
//  servopos = 0;
//  delay(dt);
}
