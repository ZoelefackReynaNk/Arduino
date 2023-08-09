int redpin=8;
int greenpin=10;
int bluepin=12;
int redscale;
int greenscale;
int bluescale;
String mycolor;
String msg="what color do you want? {red, green, blue, off all, mixture]: ";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redpin,OUTPUT);
  pinMode(greenpin,OUTPUT);
  pinMode(bluepin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(msg);
  while (Serial.available()==0){
    
  }
  mycolor=Serial.readString();
  if (mycolor=="red"){
    digitalWrite(redpin, HIGH);
    digitalWrite(greenpin, LOW);
    digitalWrite(bluepin, LOW);
  }
  if (mycolor=="green"){
    digitalWrite(redpin, LOW);
    digitalWrite(greenpin, HIGH);
    digitalWrite(bluepin, LOW);
  }
  if (mycolor=="blue"){
    digitalWrite(redpin, LOW);
    digitalWrite(greenpin, LOW);
    digitalWrite(bluepin, HIGH);
  }
  if (mycolor=="all"){
    digitalWrite(redpin, HIGH);
    digitalWrite(greenpin, HIGH);
    digitalWrite(bluepin, HIGH);
  }
  if (mycolor=="off"){
    digitalWrite(redpin, LOW);
    digitalWrite(greenpin, LOW);
    digitalWrite(bluepin, LOW);
  }
  if (mycolor=="mixture"){
    Serial.println("enter a scale value for red (0-255): ");
    while (Serial.available()==0){
      
    }
    redscale=Serial.parseInt();
    Serial.println("enter a scale value for green (0-255): ");
    while (Serial.available()==0){
      
    }
    greenscale=Serial.parseInt();
    Serial.println("enter a scale value for blue (0-255): ");
    while (Serial.available()==0){
      
    }
    bluescale=Serial.parseInt();
    analogWrite(redpin, redscale);
    analogWrite(greenpin, greenscale);
    analogWrite(bluepin, bluescale);
  }
}
