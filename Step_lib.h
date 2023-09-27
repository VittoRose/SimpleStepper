#ifndef STEP_LIB_H
#define STEP_LIB_H

#include <Arduino.h>

#define CW 1
#define CCW 0

class STEPPER {
private:

  bool speed_set;
  uint8_t speed;
  uint8_t stepPIN;
  uint8_t dirPIN;
  uint8_t N_STEP;
  float tau;
  long position;
  uint16_t delms;
  bool start_accel;
  bool end_accel;

  void doAcceleration(uint16_t del);

public:

  uint8_t startAcceleration = 2;
  uint16_t startAccelerationEnd = 100;

  uint8_t endAcceleration = 3;
  uint16_t endAccelerationEnd = 100;

  STEPPER(uint8_t STEP, uint8_t DIR, uint8_t NSTEP) {
    stepPIN = STEP;
    dirPIN = DIR;
    N_STEP = NSTEP;
    speed_set = 0;
    tau = 1;

    pinMode(stepPIN, OUTPUT);
    pinMode(dirPIN, OUTPUT);

    setZero();
  }

  STEPPER(uint8_t STEP, uint8_t DIR, uint8_t NSTEP, float TAU) {
    stepPIN = STEP;
    dirPIN = DIR;
    N_STEP = NSTEP;
    speed_set = 0;
    tau = TAU;

    pinMode(stepPIN, OUTPUT);
    pinMode(dirPIN, OUTPUT);

    setZero();
  }

  void setSpeed(int SPEED);

  int getSpeed();

  void doStep();

  void setZero();

  void rotateTo(int target);

  void increaseAngle(int _angle);

  void reduceAngle(int _angle);

  int getPosition();

  void Acceleration(bool START_ACCEL, bool END_ACCEL);
};

#endif