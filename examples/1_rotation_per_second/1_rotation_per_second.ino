#include <Step_lib.h>

#define PUL 0       //PUL pin
#define DIR 1       //DIR pin
#define STEP_PER_REVOLUTE 200   //use 360/resolution, in this case 360/1.8 = 200
#define TAU 1       //gear ratio

STEPPER motor(PUL, DIR, STEP_PER_REVOLUTE, TAU);

// STEPPER motor(PUL, DIR, STEP_PER_REVOLUTE); //this will also work, we just assume TAU = 1

int i = 0;

void setup() {
  motor.setSpeed(STEP_PER_REVOLUTE);
}

void loop() {
  motor.doStep();
}
