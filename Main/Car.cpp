#include "Car.h"
#include "Arduino.h"

void Car::setupFrontWheels(int fl1, int fl2, int fr3, int fr4, int flSpeed, int frSpeed) {
  frontLeftIn1 = fl1;
  frontLeftIn2 = fl2;
  frontRightIn3 = fr3;
  frontRightIn4 = fr4;
  frontLeftSpeed = flSpeed;
  frontRightSpeed = frSpeed;

  pinMode(frontLeftIn1, OUTPUT);
  pinMode(frontLeftIn2, OUTPUT);
  pinMode(frontRightIn3, OUTPUT);
  pinMode(frontRightIn4, OUTPUT);

  pinMode(frontLeftSpeed, OUTPUT);
  pinMode(frontRightSpeed, OUTPUT);
}

void Car::setupBackWheels(int bl1, int bl2, int br3, int br4, int blSpeed, int brSpeed) {
  backLeftIn1 = bl1;
  backLeftIn2 = bl2;
  backRightIn3 = br3;
  backRightIn4 = br4;
  backLeftSpeed = blSpeed;
  backRightSpeed = brSpeed;

  pinMode(backLeftSpeed, OUTPUT);
  pinMode(backRightSpeed, OUTPUT);
  pinMode(backLeftIn1, OUTPUT);
  pinMode(backLeftIn2, OUTPUT);
  pinMode(backRightIn3, OUTPUT);
  pinMode(backRightIn4, OUTPUT);
}

void Car::goForward(int flSpeed, int frSpeed, int blSpeed, int brSpeed) {
  stopCar();
  digitalWrite(frontLeftIn1, LOW);
  digitalWrite(frontLeftIn2, HIGH);

  digitalWrite(frontRightIn3, HIGH);
  digitalWrite(frontRightIn4, LOW);

  analogWrite(frontLeftSpeed, flSpeed);
  analogWrite(frontRightSpeed, frSpeed);

  digitalWrite(backLeftIn1, LOW);
  digitalWrite(backLeftIn2, HIGH);

  digitalWrite(backRightIn3, HIGH);
  digitalWrite(backRightIn4, LOW);

  analogWrite(backRightSpeed, brSpeed);
  analogWrite(backLeftSpeed, blSpeed);
}

void Car::goBackward(int flSpeed, int frSpeed, int blSpeed, int brSpeed)
{
  stopCar();
  digitalWrite(frontLeftIn1, HIGH);
  digitalWrite(frontLeftIn2, LOW);

  digitalWrite(frontRightIn3, LOW);
  digitalWrite(frontRightIn4, HIGH);

  analogWrite(frontLeftSpeed, flSpeed);
  analogWrite(frontRightSpeed, frSpeed);

  digitalWrite(backLeftIn1, HIGH);
  digitalWrite(backLeftIn2, LOW);

  digitalWrite(backRightIn3, LOW);
  digitalWrite(backRightIn4, HIGH);

  analogWrite(backRightSpeed, brSpeed);
  analogWrite(backLeftSpeed, blSpeed);
}

void Car::forward() {
  goForward(115, 115, 115, 115);
}

void Car::backward() {
  goBackward(115, 115, 115, 115);
}

void Car::push() {
  goForward(255, 255, 255, 255);
}

void Car::turnLeft() {
  goForward(0, 115, 0, 115);
}

void Car::turnRight()
{
  goForward(115, 0, 115, 0);
}

void Car::backLeft() {
  goBackward(115, 255, 115, 255);
}

void Car::backRight() {
  goBackward(255, 115, 255, 115);
}


void Car::stopCar() {
  digitalWrite(frontLeftIn1, LOW);
  digitalWrite(frontLeftIn2, LOW);

  digitalWrite(frontRightIn3, LOW);
  digitalWrite(frontRightIn4, LOW);
  analogWrite(frontLeftSpeed, 0);
  analogWrite(frontRightSpeed, 0);


  digitalWrite(backLeftIn1, LOW);
  digitalWrite(backLeftIn2, LOW);

  digitalWrite(backRightIn3, LOW);
  digitalWrite(backRightIn4, LOW);

  analogWrite(backLeftSpeed, 0);
  analogWrite(backRightSpeed, 0);
}

void Car::moveCar(char direc) {

  switch (tolower(direc)) {
    case 'f':  // Move forward
      forward();
      break;
    case 'b':  // Move backward
      backward();
      break;
    case 'p':  // Turn left
      push();
      break;
    case 'l':  // Turn left
      turnLeft();
      break;
    case 'r':  // Turn right
      turnRight();
      break;
    case 's':  // Stop
      stopCar();
      break;
    case 'z':  // Stop
      backLeft();
      break;
    case 'x':  // Stop
      backRight();
      break;
    default:
      break;
      Serial.println("Invalid command.");
  }
}
