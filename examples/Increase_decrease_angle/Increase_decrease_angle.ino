// this example will do a complete rotation for the stepper increasing by 45 degrees each time
// when a rotation is complete it will do the opposite

#include <Step_lib.h>

#define PUL 0       //PUL pin
#define DIR 1       //DIR pin
#define STEP_PER_REVOLUTE 200   //use 360/resolution, in this case 360/1.8 = 200
#define TAU 1       //gear ratio

STEPPER stepper(PUL, DIR, STEP_PER_REVOLUTE, TAU);

// STEPPER stepper(PUL, DIR, STEP_PER_REVOLUTE); //this will also work, it assume TAU = 1

int i = 0;

void setup() {

  //set speed at 50 step/sec
  stepper.setSpeed(50);
  Serial.begin(9600);
}

void loop() {
  for (i = 0; i <= 7; i++) {
    stepper.increaseAngle(45);
    delay(500);
    Serial.println("i++");
  }
  for (i = 0; i <= 7; i++) {
    stepper.reduceAngle(45);
    delay(500);
    Serial.println("i--");
  }
  i = 0;
}
