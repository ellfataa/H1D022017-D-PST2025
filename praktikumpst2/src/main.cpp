#include <Arduino.h>

// Deklarasi dalam variabel
int echoPin = D0;
int trigPin = D1;
int ledPin = D2;

// Deklarasi variabel untuk menghitung jarak
long duration;
int distance;

void setup() {
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);
  Serial.println(" cm");

  // Set kondisi if else untuk menghidupkan led
  if (distance < 10) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(1000);
}