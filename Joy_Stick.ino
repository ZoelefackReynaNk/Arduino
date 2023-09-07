int xpin=A2;
int ypin=A3;
int switchpin=2;
int xval;
int yval;
int switchval;
int dt=200;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(xpin, INPUT);
  pinMode(ypin, INPUT);
  pinMode(switchpin, INPUT);
  digitalWrite(switchpin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  xval = analogRead(xpin);
  yval = analogRead(ypin);
  switchval = digitalRead(switchpin);
  delay(dt);
  Serial.print("x value = ");
  Serial.print(xval);
  Serial.print(", y value = ");
  Serial.print(yval);
  Serial.print(", switch value = ");
  Serial.println(switchval);
}
