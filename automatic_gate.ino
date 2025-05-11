#include <Servo.h>

const int trigPin = 9;    // Trigger pin of ultrasonic sensor
const int echoPin = 10;    // Echo pin of ultrasonic sensor
const int servoPin = 6;     // Servo control pin
const int redLEDPin = 4;    // Red LED pin
const int blueLEDPin = 5;   // Blue LED pin
const int buzzerPin = 3;     // Buzzer pin

Servo gateServo;            // Create Servo object

void setup() {
  Serial.begin(9600);       // Start serial communication
  pinMode(trigPin, OUTPUT); // Set trigger pin as output
  pinMode(echoPin, INPUT);  // Set echo pin as input
  pinMode(redLEDPin, OUTPUT); // Set Red LED pin as output
  pinMode(blueLEDPin, OUTPUT); // Set Blue LED pin as output
  pinMode(buzzerPin, OUTPUT); // Set Buzzer pin as output
  gateServo.attach(servoPin); // Attach the servo to the control pin
  gateServo.write(0);        // Start with the gate closed
  digitalWrite(redLEDPin, HIGH); // Red LED on when gate is closed
}

void loop() {
  long duration, distance;
  
  // Trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read the echo pin
  duration = pulseIn(echoPin, HIGH);
  distance = (duration * 0.034) / 2; // Calculate distance in cm

  // Check if an object is within the threshold (e.g., 20 cm)
  if (distance < 20) {
    openGate();
  } else {
    closeGate();
  }
}

void openGate() {
  gateServo.write(90);       // Open the gate
  digitalWrite(blueLEDPin, HIGH); // Blue LED on when gate is open
  digitalWrite(redLEDPin, LOW);   // Red LED off when gate is open
  tone(buzzerPin, 1000);     // Start buzzer sound
  delay(5000);               // Keep the gate open for 5 seconds
  closeGate();               // Close the gate after 5 seconds
}

void closeGate() {
  gateServo.write(0);        // Close the gate
  digitalWrite(blueLEDPin, LOW); // Blue LED off when gate is closed
  digitalWrite(redLEDPin, HIGH); // Red LED on when gate is closed
  noTone(buzzerPin);         // Stop buzzer sound
}
