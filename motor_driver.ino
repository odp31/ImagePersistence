// This file provides a basic interface for controlling a DC motor
// using an H-bridge driver (like the L298N).

#ifndef MOTOR_DRIVER_H
#define MOTOR_DRIVER_H

// --- Pin Definitions (Adapt these to wiring) 
const int motorEnablePin = 9;  // PWM pin for speed control
const int motorDirectionPinA = 8; // Direction control pin A
const int motorDirectionPinB = 7; // Direction control pin B

// --- Function Prototypes ---
void motorDriverSetup();
void setMotorSpeed(int speed);
void setMotorDirection(bool forward);
void stopMotor();

#endif // MOTOR_DRIVER_H

// --- Implementation ---

void motorDriverSetup() {
  // Initialize motor control pins as outputs
  pinMode(motorEnablePin, OUTPUT);
  pinMode(motorDirectionPinA, OUTPUT);
  pinMode(motorDirectionPinB, OUTPUT);

  // Initialize motor driver (optional- depends on your driver)
  digitalWrite(motorEnablePin, 0); // Start with motor disabled (speed 0)
  setMotorDirection(true);      // Set an initial direction (e.g., forward)
}

// --- Function to Set Motor Speed ---
// Takes a speed value from 0 (stopped) to 255 (maximum speed for 8-bit PWM).
void setMotorSpeed(int speed) {
  if (speed >= 0 && speed <= 255) {
    analogWrite(motorEnablePin, speed); // Send PWM signal to control speed
  } else {
    Serial.println("Error: Motor speed out of range (0-255)");
  }
}

// --- Function to Set Motor Direction ---
// Takes a boolean: true for one direction, false for the other.
// Adjust the HIGH/LOW logic based on your motor driver's datasheet.
void setMotorDirection(bool forward) {
  if (forward) {
    digitalWrite(motorDirectionPinA, HIGH);
    digitalWrite(motorDirectionPinB, LOW);
  } else {
    digitalWrite(motorDirectionPinA, LOW);
    digitalWrite(motorDirectionPinB, HIGH);
  }
}

// --- Function to Stop the Motor ---
void stopMotor() {
  setMotorSpeed(0);
}
