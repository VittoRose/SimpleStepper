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

int i = 0;

void setup() {

  //set speed at 200 step/sec
  stepper.setSpeed(200);

  //enable acceleration at the beginning of the rotation but disable at the end
  stepper.Acceleration(true, false);

  // the acceleration is 2 by default but you can start slower if you increase the value
  stepper.startAcceleration = 2;

  // the acceleration end after 100 steps, if the rotation is less than 100 steps the library use steps/4 
  // if 0 no acceleration occurs, but use stepper.Acceleration(false , bool) instead
  stepper.startAccelerationEnd = 100;  

}

void loop() {
  for (i = 0; i <= 2; i++) {
    stepper.increaseAngle(180);
    delay(500);
  }
  for (i = 0; i <= 2; i++) {
    stepper.reduceAngle(180);
    delay(500);
  }
}