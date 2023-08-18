int LEDPin=8;
int buttonPin=12;
int buttonread;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LEDPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonread = digitalRead(buttonPin);
  Serial.println(buttonread);
  delay(100);
  if (buttonread==1){
      while (buttonread==1){
        digitalWrite(LEDPin,LOW);
        buttonread = digitalRead(buttonPin);
        if (buttonread==0){
          break;
      }
    }
  }
  if (buttonread==0){
    while (buttonread==0){
      digitalWrite(LEDPin,LOW);
      buttonread = digitalRead(buttonPin);
      if (buttonread==1){
        break;
      }
    }
  }
//  while (buttonread==0){
//    digitalWrite(LEDPin, HIGH);
//    buttonread = digitalRead(buttonPin);
//  }
}
