# Automatic Gate Demo Kit

## Overview
This project demonstrates how an Arduino Uno can control a gate mechanism using an ultrasonic sensor, servo motor, LEDs, and a buzzer. The gate opens when an object is detected within a certain distance and closes after 5 seconds.

## Components Used
- Arduino Uno
- Ultrasonic Sensor (HC-SR04)
- Servo Motor
- Red LED
- Blue LED
- Buzzer
- Resistors (as needed)
- Breadboard and jumper wires

## Functionality
- The ultrasonic sensor measures the distance to nearby objects.
- If an object is detected within 20 cm, the gate opens (servo rotates to 90°).
- The gate remains open for 5 seconds before closing (servo returns to 0°).
- A red LED lights up when the gate is closed, and a blue LED lights up when the gate is open.
- A buzzer sounds continuously while the gate is open.

## Instructions
1. Connect the components as per the circuit diagram.
2. Upload the `automatic_gate.ino` code to the Arduino Uno.
3. Power the Arduino and observe the behavior of the gate.

## License
This project is open-source. Feel free to modify and use it as per your needs.
