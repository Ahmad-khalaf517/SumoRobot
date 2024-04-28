#include "Car.h"
#include "Arduino.h"

Car myCar;
char autonomos = 'm';
char input;

void setup()
{
  myCar.setupFrontWheels(2, 3, 4, 5, 9, 10);
  myCar.setupBackWheels(7, 8, 12, 13, 6, 11);
  Serial.begin(9600);
}

void stop()
{
  myCar.stopCar();
  delay(500);
}

void moveCar()
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

void loop()
{
  if (Serial.available())
  {
    input = Serial.read();

    if (input == 'a' || input == 'm')
    {
      autonomos = input;
    }
    else
    {
      Serial.println(input);
      myCar.moveCar(input);
      delay(500);
    }
  }

  if (autonomos == 'a')
  {
    moveCar();
  }
  delay(500);
}
