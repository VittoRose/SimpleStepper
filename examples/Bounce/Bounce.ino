// this example will do a complete rotation for the stepper increasing by 180 degrees each time
// when a rotation is complete it will do the opposite
// the rotation will sart with a linear acceleration

#include <Step_lib.h>

#define PUL 0       //PUL pin
#define DIR 1       //DIR pin
#define STEP_PER_REVOLUTE 200   //use 360/resolution, in this case 360/1.8 = 200
#define TAU 1       //gear ratio

STEPPER stepper(PUL, DIR, STEP_PER_REVOLUTE, TAU);

// STEPPER stepper(PUL, DIR, STEP_PER_REVOLUTE); //this will also work, it assume TAU = 1


void setup() {
  //set speed at 200 step/sec
  stepper.setSpeed(200);

  //enable both acceleration
  stepper.Acceleration(true, true);
}

void loop() {
  stepper.increaseAngle(360);
  stepper.reduceAngle(360);
}