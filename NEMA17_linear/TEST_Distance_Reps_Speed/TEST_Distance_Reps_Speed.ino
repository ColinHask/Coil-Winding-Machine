/* Example sketch to control a stepper motor with TB6600 stepper motor driver, 
  AccelStepper library and Arduino: acceleration and deceleration. 
  More info: https://www.makerguides.com */

// Include the AccelStepper library:
#include "AccelStepper.h"

// Define stepper motor connections and motor interface type. 
// Motor interface type must be set to 1 when using a driver:
#define dirPin 2
#define stepPin 3
#define motorInterfaceType 1

// total movement is 100mm
// set movement edge based on movementsize input

// goal movement distance from origin in positive (towards motor) direction
// do not go over 100
float movementMM = 30;

// variable to adjust how many times the motor will oscilate (both directions back and forth)
int reps = 20;

// movement in mm per sec (max 15)
float mmPerSec = 10;

// convert to unit used by library
float speedVal = mmPerSec * 312.5;

// calculate movement amount based on millimeter goal
// 31850 is the edge of motor range of motion
float movementEdge = movementMM * (31800 / 100);

// delay in ms for pauses (pause happend when direction changes)
long delayms = 0;

// Create a new instance of the AccelStepper class:
AccelStepper stepper = AccelStepper(motorInterfaceType, stepPin, dirPin);

void setup() {
  // Set the maximum speed and acceleration:
  stepper.setMaxSpeed(speedVal);
  stepper.setAcceleration(100000);
}

void loop() {

  // had to divide reps by 2 (idk why but it works)
  for (int i = 0; i <= (reps/2); i++) {
    // Set the target position:
    // far edge (motor side)
    stepper.moveTo(movementEdge);
    
    // Run to target position with set speed and acceleration/deceleration:
    stepper.runToPosition();

    delay(delayms);

    // Move back to zero:
    stepper.moveTo(0);
    stepper.runToPosition();

    delay(delayms);
  }
  stepper.setMaxSpeed(0);
}
