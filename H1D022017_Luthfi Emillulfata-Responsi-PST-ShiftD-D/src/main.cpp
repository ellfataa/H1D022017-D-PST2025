#include <Arduino.h>
#include <servo.h>

// Insialisasi untuk sensor dan servo
Servo myServo;
int echoPin = D0;
int trigPin = D1;
int ledPin = D2;
int servoPin = D5;

long duration;
int distance;

// SETUP
void setup() {
  // Inisialisasi pin
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 
  pinMode(ledPin, OUTPUT);
  myServo.attach(servoPin);

  Serial.begin(9600);  
  myServo.write(0);  
}

void loop() {
  // Mengirimkan sinyal ultrasonik
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Menghitung jarak
  duration = pulseIn(echoPin, HIGH);
  distance = (duration * 0.034) / 2;

  // Menampilkan jarak pada Serial Monitor
  Serial.print("Jarak: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Menggerakkan servo berdasarkan jarak 1,5 meter terbuka
  if (distance < 150) {
    myServo.write(90);
    digitalWrite(ledPin, HIGH);
  } else {
    myServo.write(0);
    digitalWrite(ledPin, LOW);
  }

  delay(500); 
}
