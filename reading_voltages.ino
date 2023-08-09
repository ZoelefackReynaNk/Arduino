int readpin=A3;
int readval;
int v2=0;
int dt=500;
void setup() {
  // put your setup code here, to run once:
  pinMode(readpin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  readval=analogRead(readpin);
  //analogread reads a number in range 0 to 1023 and not a voltage.
  v2=(5./10223.)*readval;
  Serial.println(v2);
  delay(dt);
  
}
