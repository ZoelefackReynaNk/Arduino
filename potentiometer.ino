int voltpin=A2;
int ledpin=10;
int readval;
float pinvolt;
float v2;
int t=1000;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(voltpin, INPUT);
  pinMode(ledpin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  readval=analogRead(voltpin);
  v2=(5./1023.)*readval;
  pinvolt=((255./1023.)*readval);
  Serial.print(v2);
  Serial.print(" ");
  Serial.println(pinvolt);
  analogWrite(ledpin, pinvolt);
  delay(t);
}
