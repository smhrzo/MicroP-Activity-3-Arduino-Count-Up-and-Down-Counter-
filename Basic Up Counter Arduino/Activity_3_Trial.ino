
void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < 10; i++) {
    decToBitTens(i);
    for (int j = 0; j < 10; j++) {
      decToBitOnes(j);
      delay(500);
    }
  }
}

void decToBitOnes(int number) {
  for (int i = 0; i < 4; i++) {
    digitalWrite(i, bitRead(number, i));
  }
}

void decToBitTens(int number) {
  for (int i = 4; i < 8; i++) {
    digitalWrite(i, bitRead(number, i - 4));
  }
}
