// --- Motor Control for Image Persistence Project ---

// --- Pin Definitions ---
const int motorEnablePin = 9;  // PWM pin for speed control (connect to EN pin of motor driver)
const int motorDirectionPinA = 8; // Digital pin for direction control (IN1 or IN3 of motor driver)
const int motorDirectionPinB = 7; // Digital pin for direction control (IN2 or IN4 of motor driver)

// --- Motor Control Parameters ---
int motorSpeed = 0;          // Current motor speed (0-255 for PWM)
bool motorDirectionForward = true; // Current motor direction

// --- Setup Function ---
void setup() {
  // Initialize motor control pins as outputs
  pinMode(motorEnablePin, OUTPUT);
  pinMode(motorDirectionPinA, OUTPUT);
  pinMode(motorDirectionPinB, OUTPUT);

  // Initialize motor driver (optional, depends on your driver)
  digitalWrite(motorEnablePin, 0); // Start with motor disabled (speed 0)
  setMotorDirection(motorDirectionForward); // Set initial direction
}

// --- Function to Set Motor Speed ---
// Takes a speed value from 0 (stopped) to 255 (maximum speed).
void setMotorSpeed(int speed) {
  if (speed >= 0 && speed <= 255) {
    motorSpeed = speed;
    analogWrite(motorEnablePin, motorSpeed); // Send PWM signal to control speed
  } else {
    Serial.println("Error: Motor speed out of range (0-255)");
  }
}

// --- Function to Set Motor Direction ---
// Takes a boolean: true for forward, false for backward.
void setMotorDirection(bool forward) {
  motorDirectionForward = forward;
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

// --- Example Usage within your Main Loop ---
// You would integrate these functions into your image display logic.

// Example: Slowly ramp up the motor speed
void rampUpSpeed() {
  for (int i = 0; i <= 255; i += 5) {
    setMotorSpeed(i);
    delay(50); // Adjust delay for ramp speed
  }
}

// Example: Spin at a constant speed
void runAtConstantSpeed(int speed, int duration) {
  setMotorSpeed(speed);
  delay(duration);
  stopMotor();
}

// Example: Change direction
void reverseDirection(int duration) {
  setMotorDirection(!motorDirectionForward); // Toggle direction
  delay(duration);
}



// --- Notes and Considerations for your Project ---

// 1. Microcontroller and Pin Mapping:
//    - Adjust the pin definitions (motorEnablePin, motorDirectionPinA, motorDirectionPinB)
//      to match the actual wiring to your microcontroller.

// 2. Motor Driver:
//    - This code assumes a basic H-bridge driver like the L298N. The control logic (HIGH/LOW for direction)
//      might differ for other drivers. Consult your motor driver's datasheet.
//    - Some drivers have an enable pin that needs to be HIGH for the motor to run. You might need to adjust
//      the initialization in the `setup()` function accordingly.

// 3. Power Supply:
//    - Ensure your motor and motor driver have an adequate and separate power supply from your microcontroller.
//      Motors can draw significant current and cause issues if powered directly from the microcontroller.

// 4. Speed Control (PWM):
//    - The `analogWrite()` function on Arduino (and similar functions on other platforms) generates a PWM signal
//      on a specific pin, effectively controlling the average voltage supplied to the motor and thus its speed.
//    - The range of PWM (0-255) might need adjustment depending on your microcontroller's PWM resolution.

// 5. Synchronization with Image Display:
//    - The most crucial part of your project will be synchronizing the rotation speed of the motor with the
//      timing of your LED array updates to create a stable image.
//    - You'll likely need precise timing and potentially feedback mechanisms (like an encoder on the motor)
//      for accurate synchronization. This basic file doesn't include encoder handling.

// 6. Starting and Stopping:
//    - Consider how you want the motor to start and stop. Sudden starts/stops might cause vibrations or mechanical stress.
//    - Implementing smooth acceleration and deceleration (like the `rampUpSpeed()` example) can be beneficial.

// 7. Direction Control:
//    - Decide if you need to control the direction of rotation. For a simple persistence of vision display,
//      you might only need one direction.

// 8. Libraries:
//    - Depending on your microcontroller and motor driver, you might need to include specific libraries.

// --- Integration into your Main Project ---
// In your main Arduino sketch (or equivalent), you would:
// - Include this motor control logic.
// - Call `setup()` to initialize the motor pins.
// - Use `setMotorSpeed()`, `setMotorDirection()`, and `stopMotor()` within your main loop
//   to control the motor's movement in coordination with your LED display updates.
