#include "Car.h"
#include "Arduino.h"

Car myCar;
void setup()
{
  myCar.setupFrontWheels(2, 3, 4, 5, 9, 10);
  myCar.setupBackWheels(7, 8, 12, 13, 6, 11);
  Serial.begin(9600);
}

void stop(){
  myCar.stopCar();
  delay(500);
}

void loop()
{
  myCar.push();
  delay(1000);
  stop();
  myCar.backward();
  delay(1000);
  stop();
  myCar.forward();
  delay(1000);
  stop();
  myCar.turnLeft();
  delay(1000);
  stop();
  myCar.turnRight();
  delay(1000);
  stop();
  myCar.backLeft();
  delay(1000);
  stop();
  myCar.backRight();
  delay(1000);
  stop();
}
