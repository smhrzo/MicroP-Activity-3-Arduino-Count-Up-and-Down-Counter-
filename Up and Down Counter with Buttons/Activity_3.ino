
int btnCountDown = 1;
int btnCountUp = 2;
int btnReset = 3;
volatile bool isButton1Pressed;
volatile bool isButton2Pressed;

int timeInterval = 500;

void setup() {
  for (int i = 4; i < 12; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(btnReset), reset, RISING);
}

void loop() {
  displayZero();
  
  if (digitalRead(btnCountDown) == LOW) {
    isButton1Pressed = false;
    countDown(timeInterval);
  }

  if (digitalRead(btnCountUp) == LOW) {
    isButton2Pressed = false;
    countUp(timeInterval);
  }
}

void reset() {
  displayZero();
  isButton1Pressed = true;
  isButton2Pressed = true;
}

void displayZero() {
  decToBitTens(0);
  decToBitOnes(0);
}

void countUp(int time) {
  while (true) {
    for (int i = 0; i < 10; i++) {
      decToBitTens(i);  
      for (int j = 0; j < 10; j++) {
        if (isButton2Pressed == true) {
          return;
        }
        decToBitOnes(j);
        delay(time);
      }
    }
  }
} 

void countDown(int time) {
  while (true) {
    for (int i = 9; i >= 0; i--) {
      decToBitTens(i);
      for (int j = 9; j >= 0; j--) {
        if (isButton1Pressed == true) {
          return;
        }
        decToBitOnes(j);
        delay(time);
      }
    }
  }
}

void decToBitOnes(int number) {
  for (int i = 4; i < 8; i++) {
    digitalWrite(i, bitRead(number, i - 4)); 
  }
}

void decToBitTens(int number) {
  for (int i = 8; i < 12; i++) {
    digitalWrite(i, bitRead(number, i - 8));
  }
}
