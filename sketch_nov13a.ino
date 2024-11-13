#include <Servo.h>

// Create Servo objects for each motor (2 motors for duocopter)
Servo motor1;
Servo motor2;

// Define the pin numbers where the signal wires of the ESCs (motors) are connected
const int motor1Pin = 9;
const int motor2Pin = 10;

// Define the PWM range for this setup (1000 to 1050 for your ESC)
const int minThrottle = 1000;  // Minimum throttle (usually 1000)
const int maxThrottle = 1200;  // Maximum throttle (adjusted for your case)

// Define the control sensitivity (change these to tune control responsiveness)
const int pitchSensitivity = 10;  // Change in motor speed for pitch control
const int rollSensitivity = 10;   // Change in motor speed for roll control
const int yawSensitivity = 10;    // Change in motor speed for yaw control

// Initialize Bluetooth serial communication
char receivedChar;  // Variable to store received character from Bluetooth

void setup() {
  // Initialize serial communication for Bluetooth (default baud rate: 9600 for HC-05/HC-06)
  Serial.begin(9600);
  
  // Attach each motor (ESC) to the corresponding pin
  motor1.attach(motor1Pin);
  motor2.attach(motor2Pin);

  // Initialize motors to idle (0 throttle)
  motor1.writeMicroseconds(minThrottle);
  motor2.writeMicroseconds(minThrottle);

  delay(2000); // Wait for ESCs to initialize (typically 2 seconds)
}

void loop() {
  // Read data from Bluetooth (through Serial)
  if (Serial.available() > 0) {
    receivedChar = Serial.read();  // Read one byte from Bluetooth

    // Handle different commands sent via Bluetooth
    if (receivedChar == 'F') {  // Forward command
      moveForward();
    } 
    else if (receivedChar == 'B') {  // Backward command
      moveBackward();
    } 
    else if (receivedChar == 'S') {  // Stay still (idle)
      stayStill();
    }
    else if (receivedChar == 'O') {  // Turn off (stop motors)
      turnOff();
    }
  }
}

// Function to move forward (increase motor 1, decrease motor 2)
void moveForward() {
  int motor1Speed = minThrottle + pitchSensitivity;
  int motor2Speed = minThrottle - pitchSensitivity;
  motor1Speed = checkPWM(motor1Speed);
  motor2Speed = checkPWM(motor2Speed);
  
  motor1.writeMicroseconds(motor1Speed);
  motor2.writeMicroseconds(motor2Speed);
}

// Function to move backward (decrease motor 1, increase motor 2)
void moveBackward() {
  int motor1Speed = minThrottle - pitchSensitivity;
  int motor2Speed = minThrottle + pitchSensitivity;
  motor1Speed = checkPWM(motor1Speed);
  motor2Speed = checkPWM(motor2Speed);
  
  motor1.writeMicroseconds(motor1Speed);
  motor2.writeMicroseconds(motor2Speed);
}

// Function to stay still (idle the motors)
void stayStill() {
  motor1.writeMicroseconds(minThrottle);
  motor2.writeMicroseconds(minThrottle);
}

// Function to turn off motors completely (safety)
void turnOff() {
  motor1.writeMicroseconds(0);  // Turn off motor 1
  motor2.writeMicroseconds(0);  // Turn off motor 2
}

// Function to check if a PWM value is within the valid range
int checkPWM(int pwmValue) {
  if (pwmValue < minThrottle) {
    pwmValue = minThrottle;  // Clamp to min throttle
  } else if (pwmValue > maxThrottle) {
    pwmValue = maxThrottle;  // Clamp to max throttle
  }
  return pwmValue;
}
