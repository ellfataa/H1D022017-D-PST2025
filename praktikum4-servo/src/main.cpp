#include <Arduino.h>
#include <servo.h>

// put function declarations here:
Servo myservo;

void setup() {
  // put your setup code here, to run once:
  myservo.attach(D0); // Attaches the servo on pin 9 to the servo object
  Serial.begin(9600); // Start the serial communication at 9600 baud rate
}

void loop() {
  // // put your main code here, to run repeatedly:
  // for(int pos = 0; pos <= 180; pos ++) { // goes from 0 degrees to 180 degrees
  //   myservo.write(pos); // tell servo to go to position in variable 'pos'
  //   delay(10); // waits 15ms for the servo to reach the position
  // }

  // for(int pos = 180; pos >= 0; pos --) { // goes from 180 degrees to 0 degrees
  //   myservo.write(pos); // tell servo to go to position in variable 'pos'
  //   delay(10); // waits 15ms for the servo to reach the position
  // }

  myservo.write(90); // tell servo to go to position in variable 'pos'
  delay(2000); // waits 15ms for the servo to reach the position
  myservo.write(0); // tell servo to go to position in variable 'pos'
  delay(2000); // waits 15ms for the servo to reach the position
  myservo.write(90); // tell servo to go to position in variable 'pos'
  delay(2000); // waits 15ms for the servo to reach the position
}