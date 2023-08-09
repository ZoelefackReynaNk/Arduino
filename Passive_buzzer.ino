int mynum;
int potpin=A1;
int potval;
int Vpot;
int buzzpin=8;

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzpin, OUTPUT);
}

void loop() {
  // passive buzzers work based on a continiuos on and off state for its tone:
  digitalWrite(buzzpin, HIGH);
  delay(2);
  digitalWrite(buzzpin, LOW);
  delay(2);
}
