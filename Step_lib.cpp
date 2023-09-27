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

  if(accel == false){
    for (i = 0; i < step; i++) {
      doStep();
    }
  }

  if(accel == true){
    uint8_t accelstep = (step/4 < 100) ?  step/4 : 100;

    Serial.print("Numero di passi in accelerazione");
    Serial.println(accelstep);

    while(i < accelstep){
      doAcceleration(3*delms - round(2.0/accelstep)*i);   // linear acceleration from 3*delms to delms
      Serial.print("Delay: ");
      Serial.println((accelstep - i));
      i++;
    }
    Serial.println("Fuori dal loop di accelerazione");
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

void STEPPER::Acceleration(bool condition){
  if (condition == true) accel = true;
  else accel = false;
}

void STEPPER::doAcceleration(uint16_t del){
  
  digitalWrite(stepPIN, HIGH);
  delayMicroseconds(del);
  digitalWrite(stepPIN, LOW);
}