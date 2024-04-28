#include "Car.h"
#include "Arduino.h"

void Car::setupFrontWheels(int fl1, int fl2, int fr3, int fr4, int flSpeed, int frSpeed) {
  frontLeftIn1 = fl1;
  frontLeftIn2 = fl2;
  frontRightIn3 = fr3;
  frontRightIn4 = fr4;
  frontLeftSpeed = flSpeed;
  frontRightSpeed = frSpeed;
}

void Car::setCarSpeed(int sp){
  carSpeed = sp;
}

void Car::setupBackWheels(int bl1, int bl2, int br3, int br4, int blSpeed, int brSpeed) {
  backLeftIn1 = bl1;
  backLeftIn2 = bl2;
  backRightIn3 = br3;
  backRightIn4 = br4;
  backLeftSpeed = blSpeed;
  backRightSpeed = brSpeed;
}

void Car::begin() {
  // Set motor pins as outputs
  pinMode(backLeftSpeed, OUTPUT);
  pinMode(backRightSpeed, OUTPUT);
  pinMode(backLeftIn1, OUTPUT);
  pinMode(backLeftIn2, OUTPUT);
  pinMode(backRightIn3, OUTPUT);
  pinMode(backRightIn4, OUTPUT);

  pinMode(frontLeftIn1, OUTPUT);
  pinMode(frontLeftIn2, OUTPUT);
  pinMode(frontRightIn3, OUTPUT);
  pinMode(frontRightIn4, OUTPUT);

  pinMode(frontLeftSpeed, OUTPUT);
  pinMode(frontRightSpeed, OUTPUT);
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
void Car::goBackward(int frontLeftSpeed, int frontRightSpeed, int backLeftSpeed, int backRightSpeed) {
  stopCar();
  digitalWrite(frontLeftIn1, HIGH);
  digitalWrite(frontLeftIn2, LOW);

  digitalWrite(frontRightIn3, LOW);
  digitalWrite(frontRightIn4, HIGH);

  analogWrite(frontLeftSpeed, frontLeftSpeed);
  analogWrite(frontRightSpeed, frontRightSpeed);

  digitalWrite(backLeftIn1, HIGH);
  digitalWrite(backLeftIn2, LOW);

  digitalWrite(backRightIn3, LOW);
  digitalWrite(backRightIn4, HIGH);

  analogWrite(backRightSpeed, backRightSpeed);
  analogWrite(backLeftSpeed, backLeftSpeed);
}

void Car::forward() {
  stopCar();
  digitalWrite(frontLeftIn1, LOW);
  digitalWrite(frontLeftIn2, HIGH);

  digitalWrite(frontRightIn3, HIGH);
  digitalWrite(frontRightIn4, LOW);

  analogWrite(frontLeftSpeed, carSpeed);
  analogWrite(frontRightSpeed, carSpeed);

  digitalWrite(backLeftIn1, LOW);
  digitalWrite(backLeftIn2, HIGH);

  digitalWrite(backRightIn3, HIGH);
  digitalWrite(backRightIn4, LOW);

  analogWrite(backRightSpeed, carSpeed);
  analogWrite(backLeftSpeed, carSpeed);
}

void Car::backward() {
  stopCar();
  digitalWrite(frontLeftIn1, HIGH);
  digitalWrite(frontLeftIn2, LOW);

  digitalWrite(frontRightIn3, LOW);
  digitalWrite(frontRightIn4, HIGH);

  analogWrite(frontLeftSpeed, carSpeed);
  analogWrite(frontRightSpeed, carSpeed);

  digitalWrite(backLeftIn1, HIGH);
  digitalWrite(backLeftIn2, LOW);

  digitalWrite(backRightIn3, LOW);
  digitalWrite(backRightIn4, HIGH);

  analogWrite(backRightSpeed, carSpeed);
  analogWrite(backLeftSpeed, carSpeed);
}

void Car::push() {
  stopCar();
  digitalWrite(frontLeftIn1, LOW);
  digitalWrite(frontLeftIn2, HIGH);

  digitalWrite(frontRightIn3, HIGH);
  digitalWrite(frontRightIn4, LOW);

  analogWrite(frontLeftSpeed, 255);
  analogWrite(frontRightSpeed, 255);

  digitalWrite(backLeftIn1, LOW);
  digitalWrite(backLeftIn2, HIGH);

  digitalWrite(backRightIn3, HIGH);
  digitalWrite(backRightIn4, LOW);

  analogWrite(backRightSpeed, 255);
  analogWrite(backLeftSpeed, 255);
}

void Car::turnLeft() {
  stopCar();
  digitalWrite(frontLeftIn1, LOW);
  digitalWrite(frontLeftIn2, LOW);

  digitalWrite(frontRightIn3, HIGH);
  digitalWrite(frontRightIn4, LOW);

  analogWrite(frontLeftSpeed, 0);
  analogWrite(frontRightSpeed, carSpeed);

  digitalWrite(backLeftIn1, LOW);
  digitalWrite(backLeftIn2, LOW);

  digitalWrite(backRightIn3, HIGH);
  digitalWrite(backRightIn4, LOW);

  analogWrite(backRightSpeed, carSpeed);
  analogWrite(backLeftSpeed, 0);
}

void Car::backLeft() {
  stopCar();
  Serial.println("back left");
  digitalWrite(frontLeftIn1, HIGH);
  digitalWrite(frontLeftIn2, LOW);

  digitalWrite(frontRightIn3, LOW);
  digitalWrite(frontRightIn4, HIGH);

  analogWrite(frontLeftSpeed, 115);
  analogWrite(frontRightSpeed, 255);

  digitalWrite(backLeftIn1, HIGH);
  digitalWrite(backLeftIn2, LOW);

  digitalWrite(backRightIn3, LOW);
  digitalWrite(backRightIn4, HIGH);

  analogWrite(backRightSpeed, 255);
  analogWrite(backLeftSpeed, 115);
}

void Car::backRight() {
  stopCar();
  Serial.println("back right");
  digitalWrite(frontLeftIn1, HIGH);
  digitalWrite(frontLeftIn2, LOW);

  digitalWrite(frontRightIn3, LOW);
  digitalWrite(frontRightIn4, HIGH);

  analogWrite(frontLeftSpeed, 255);
  analogWrite(frontRightSpeed, 115);

  digitalWrite(backLeftIn1, HIGH);
  digitalWrite(backLeftIn2, LOW);

  digitalWrite(backRightIn3, LOW);
  digitalWrite(backRightIn4, HIGH);

  analogWrite(backRightSpeed, 115);
  analogWrite(backLeftSpeed, 255);
}

void Car::turnRight() {
  stopCar();
  digitalWrite(frontLeftIn1, LOW);
  digitalWrite(frontLeftIn2, HIGH);

  digitalWrite(frontRightIn3, LOW);
  digitalWrite(frontRightIn4, LOW);

  analogWrite(frontLeftSpeed, carSpeed);
  analogWrite(frontRightSpeed, 0);

  digitalWrite(backLeftIn1, LOW);
  digitalWrite(backLeftIn2, HIGH);

  digitalWrite(backRightIn3, LOW);
  digitalWrite(backRightIn4, LOW);

  analogWrite(backRightSpeed, 0);
  analogWrite(backLeftSpeed, carSpeed);
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
