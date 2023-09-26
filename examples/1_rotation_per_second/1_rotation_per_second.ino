#include "Step_lib.h"

#define NSTEP 200

STEPPER rot(0, 1, NSTEP);

void setup() {
  rot.setSpeed(NSTEP);
}


void loop() {
  rot.doStep();
}
