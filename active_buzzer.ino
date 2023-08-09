int mynum;
int potpin=A1;
int potval;
int Vpot;
int buzzpin=8;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzzpin, OUTPUT);
  pinMode(potpin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  potval=analogRead(potpin);
  Serial.println(potval);
//  Serial.println("enter a number: ");
//  while (Serial.available()==0){
//    
//  }
//  mynum=Serial.parseInt();
  if (potval>512){
    digitalWrite(buzzpin, LOW);
//    delay(2000);
//    digitalWrite(buzzpin, LOW);
  }
  else{
    digitalWrite(buzzpin, HIGH);
  }
}
