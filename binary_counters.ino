int p1=10;
int p2=8;
int p3=6;
int p4=4;

void setup() {
  // put your setup code here, to run once:
  pinMode(p1, OUTPUT);
  pinMode(p2, OUTPUT);
  pinMode(p3, OUTPUT);
  pinMode(p4, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i=0; i<16; i++) {
      if (i%2 == 1){
        digitalWrite(p4, HIGH);
      }
      else{
        digitalWrite(p4, LOW);
      }
      if ((i/2)%2 == 1){
        digitalWrite(p3, HIGH);
      }
      else{
        digitalWrite(p3, LOW);
      }
      if (((i/2)/2)%2 == 1){
        digitalWrite(p2, HIGH);
      }
      else{
        digitalWrite(p2, LOW);
      }
      if ((((i/2)/2)/2)%2 == 1){
        digitalWrite(p1, HIGH);
      }
      else{
        digitalWrite(p1, LOW);
      }
      delay(2000);
    }

}
