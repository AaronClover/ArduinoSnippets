int led = 13;
int button = 2;
int buttonState = 0;

void setup () {
pinMode(led, OUTPUT);
pinMode(button, INPUT);

Serial.begin(9600);
}

void loop () {
  if (checkButton(button, buttonState) == 1) {
    float temp = vtof(analogRead(A0));
    Serial.println(temp);
  }
  delay(1);
}

//Volts to Ferenheight
float vtof (float volts) {
  return volts*(5000/1024)/10*(9/5)+32;
}



// 0 - Unpressed
// 1 - Pressed
// 2 - Held
int checkButton (int button, int &buttonState) {
  int actualState = digitalRead(button);
  if (actualState == 1) {
    if (buttonState == 0) {
      buttonState = 1;
      return 1;
    }
    else {
    return 2;
    }
  }
  else {
  buttonState = 0;
  return 0;
  }
  
}
