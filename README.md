# STEPPER Library Documentation

## Overview

The `STEPPER` library is a simple Arduino library for controlling a stepper motor using a stepper driver. It provides a set of functions to control the stepper motor's rotation, speed, and position. This library is suitable for basic stepper motor control applications.

## Installation

To use this library in your Arduino project, follow these steps:

1. Download the `Step_lib.h` and `Step_lib.cpp` files from this repository.
2. Place both files in the same directory as your Arduino sketch.
3. Include the library in your Arduino sketch by adding `#include "Step_lib.h"` at the beginning of your code.

## Usage

### Initializing the Stepper Motor

Before using the `STEPPER` library, you need to initialize your stepper motor by creating an instance of the `STEPPER` class. You can do this by calling one of the following constructors:

```cpp
STEPPER(uint8_t STEP, uint8_t DIR, uint8_t NSTEP);
STEPPER(uint8_t STEP, uint8_t DIR, uint8_t NSTEP, float TAU);
```

- `STEP`: The Arduino pin connected to the stepper motor's step input.
- `DIR`: The Arduino pin connected to the stepper motor's direction input.
- `NSTEP`: The number of steps per revolution for your stepper motor.
- `TAU` (optional): The factor used to calculate the number of steps needed to rotate a specific angle. Default is 1. You can adjust this value for microstepping.

Example:

```cpp
#include "Step_lib.h"

// Create a stepper motor instance with default TAU value (1)
STEPPER myStepper(8, 9, 200);

// OR

// Create a stepper motor instance with a custom TAU value
STEPPER myStepper(8, 9, 200, 0.9);
```

### Setting the Speed

You can set the speed of the stepper motor using the `setSpeed` method. The speed is specified in steps per second.

```cpp
void setSpeed(int SPEED);
```

Example:

```cpp
myStepper.setSpeed(100); // Set the speed to 100 steps per second
```

### Getting the Current Speed

You can retrieve the current speed of the stepper motor using the `getSpeed` method.

```cpp
int getSpeed();
```

Example:

```cpp
int currentSpeed = myStepper.getSpeed();
```

### Rotating the Stepper Motor

You can rotate the stepper motor to a specific position (in steps) using the `rotateTo` method. This method will move the stepper motor to the specified position.

```cpp
void rotateTo(int target);
```

Example:

```cpp
myStepper.rotateTo(1000); // Rotate to position 1000 steps
```

### Increasing and Reducing the Angle

You can increase and reduce the angle of the stepper motor by a specified number of steps using the `increaseAngle` and `reduceAngle` methods.

```cpp
void increaseAngle(int _angle);
void reduceAngle(int _angle);
```

Example:

```cpp
myStepper.increaseAngle(45); // Increase the angle by 45 degrees
myStepper.reduceAngle(30);   // Reduce the angle by 30 degrees
```

### Getting the Current Position

You can retrieve the current position of the stepper motor in steps using the `getPosition` method.

```cpp
int getPosition();
```

Example:

```cpp
int currentPosition = myStepper.getPosition();
```

### Performing a Single Step

You can manually perform a single step using the `doStep` method. This can be useful for fine-grained control.

```cpp
void doStep();
```

Example:

```cpp
myStepper.doStep(); // Perform a single step
```

## Example Sketch

Here's a simple example sketch that demonstrates the basic usage of the `STEPPER` library:

```cpp
#include "Step_lib.h"

STEPPER myStepper(8, 9, 200);

void setup() {
  myStepper.setSpeed(100);
}

void loop() {
  myStepper.rotateTo(1000);
  delay(1000);
  myStepper.rotateTo(0);
  delay(1000);
}
```

This sketch initializes a stepper motor, sets its speed to 100 steps per second, and then repeatedly rotates it back and forth between positions 0 and 1000 steps.

## Support and Feedback

For questions, bug reports, or feature requests, please create an issue in the [GitHub repository](https://github.com/VittoRose/SimpleStepper).

## License

This library is released under the MIT License. See the [LICENSE](LICENSE) file for details.