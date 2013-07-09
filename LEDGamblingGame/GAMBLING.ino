byte ledPin[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 2, 3};
int ledDelay;
int direction = 1;
int currentLED = 0;
unsigned long changeTime;
int potPin = 2;
int buttonPin = 47;
int buttonState=0;
boolean pressed=false;

void setup() {
  for (int x = 0; x < 11; x++){
    pinMode(ledPin[x],OUTPUT);
  } 
  pinMode(buttonPin, INPUT);
  changeTime = millis();
  Serial.begin(9600);
}

void loop() {
  while (!pressed){
    buttonState = digitalRead(buttonPin);
    if ( buttonState==1){
      pressed = true;
    }else{
    ledDelay = analogRead(potPin);
    if (( millis() - changeTime) > ledDelay){
      changeLED();
      changeTime = millis();
    }
    }
  }
  if (pressed){
    delay(5000);
    pressed=false;
  }
}

void changeLED(){
  for (int x=0; x < 11; x++){
    digitalWrite(ledPin[x], LOW);
  } 
  digitalWrite(ledPin[currentLED], HIGH);

  currentLED+=direction;
  if (currentLED == 10){ 
    direction = -1; 
  }
  if (currentLED == 0){ 
    direction = 1; 
  }
}

