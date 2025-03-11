#include <Arduino.h>

// put function declarations here:

int redLED = D0;
int greenLED = D1;
int yellowLED = D2;

void setup() {
  // put your setup code here, to run once:
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(redLED, HIGH);
  delay(5000);
  digitalWrite(redLED, LOW);
  digitalWrite(greenLED, HIGH);
  delay(2000);
  digitalWrite(greenLED, LOW);
  digitalWrite(yellowLED, HIGH);
  delay(5000);
  digitalWrite(yellowLED, LOW);
}

// put function definitions here: