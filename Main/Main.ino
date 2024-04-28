#include "Car.h"
Car myCar;
void setup() {
  myCar.setupFrontWheels(2, 3, 4, 5, 9, 10);
  myCar.setupBackWheels(7, 8, 12, 13, 6, 11);
  myCar.setCarSpeed(255);
  myCar.begin();
  Serial.begin(9600);
}

void loop() {
//  myCar.push();
//  delay(1000);
//  myCar.stopCar();
//  delay(500);
//  myCar.backward();
//  delay(1000);
//  myCar.stopCar();
//  delay(500);
//  myCar.forward();
//  delay(1000);
//  myCar.stopCar();
//  delay(500);
  myCar.turnLeft();
  delay(1000);
  myCar.stopCar();
  delay(500);
  myCar.turnRight();
  delay(1000);
  myCar.stopCar();
  delay(500);
//  myCar.goForward(115, 255, 255, 255);
//  myCar.backLeft();
//  delay(1000);
//  myCar.stopCar();
//  delay(500);
//  myCar.backRight();
//  delay(1000);
//  myCar.stopCar();
//  delay(500);
}
