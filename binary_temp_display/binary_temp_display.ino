int LED1=7;
int LED2=8;
int LED4=9;
int LED8=10;
int LED16=11;
int LED32=12;
int LED64=13;
int tempPin=A10;
int temp;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED8, OUTPUT);
  pinMode(LED16, OUTPUT);
  pinMode(LED32, OUTPUT);
  pinMode(LED64, OUTPUT);
  pinMode(tempPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  temp = vtof(analogRead(tempPin));
  convertIntToBinary(temp);
  Serial.println(temp);
  delay(1000);
}

float vtof (float volts) {
  return ((volts * 5000.0 / 1024.0 / 10.0) * 9.0 / 5.0) + 32.0;
}

void convertIntToBinary(int number) {
  int divisible;
  divisible = 8;
  
  if (number / 64) {
  number = number - 64;
  digitalWrite(LED64, HIGH);
  } else {
  digitalWrite(LED64, LOW);
  }
  
  if (number / 32) {
  number = number - 32;
  digitalWrite(LED32, HIGH);
  } else {
  digitalWrite(LED32, LOW);
  }
  
  if (number / 16) {
  number = number - 16;
  digitalWrite(LED16, HIGH);
  } else {
  digitalWrite(LED16, LOW);
  }
  
  if (number / 8) {
  number = number - 8;
  digitalWrite(LED8, HIGH);
  } else {
  digitalWrite(LED8, LOW);
  }
  
  if (number / 4) {
  number = number - 4 ;
  digitalWrite(LED4, HIGH);
  } else {
  digitalWrite(LED4, LOW);
  }
  
  if (number / 2) {
  number = number - 2 ;
  digitalWrite(LED2, HIGH);
  } else {
  digitalWrite(LED2, LOW);
  }
  
  if (number / 1) {
  number = number - 1 ;
  digitalWrite(LED1, HIGH);
  } else {
  digitalWrite(LED1, LOW);
  }
  
}
