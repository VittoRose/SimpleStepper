#include "Step_lib.h"

void STEPPER::setSpeed(int SPEED) {
  // use step/sec
  
  delms = 1000000 / SPEED;
  speed = SPEED;
  speed_set = 1;
}

int STEPPER::getSpeed() {
  return speed;
}

void STEPPER::doStep() {

  if (speed_set == 1) {
    
      digitalWrite(stepPIN, HIGH);
      delayMicroseconds(delms);
      digitalWrite(stepPIN, LOW);
  }
}

void STEPPER::setZero() {
  position = 0;
}

void STEPPER::rotateTo(int target) {
  float angle = 0;
  float step = 0;
  int i = 0;

  if (target > position) {

    digitalWrite(dirPIN, CCW);

    angle = target - position;
    step = round(tau * N_STEP * angle / 360);

  } else if (target < position) {

    digitalWrite(dirPIN, CW);

    angle = position - target;
    step = round(tau * N_STEP * angle / 360);

  } else if (target == position) {
    step = 0;
  }

  if(start_accel == false){
    for (i = 0; i < step; i++) {
      doStep();
    }
  }

  if(start_accel == true){
    uint8_t accelstep = (step/4 < startAccelerationEnd) ?  step/4 : startAccelerationEnd;

    while(i < accelstep){
      doAcceleration(startAcceleration*delms - round((startAcceleration - 1) / accelstep)*i);   // linear acceleration from 3*delms to delms
      i++;
    }
    while(i <= step){
      doStep();
      i++;
    }
  }


  position = target;
}

int STEPPER::getPosition() {
  return position;
}

void STEPPER::increaseAngle(int _angle) {
  rotateTo(getPosition() + _angle);
}

void STEPPER::reduceAngle(int _angle) {
  rotateTo(getPosition() - _angle);
}

void STEPPER::Acceleration(bool START_ACCEL, bool END_ACCEL){
  start_accel = (START_ACCEL == true) ? true : false;
  end_accel = (END_ACCEL == true) ? true : false;
}

void STEPPER::doAcceleration(uint16_t del){
  
  digitalWrite(stepPIN, HIGH);
  delayMicroseconds(del);
  digitalWrite(stepPIN, LOW);
}