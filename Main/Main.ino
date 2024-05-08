
#include "Car.h"
#include "Arduino.h"

int trigPin = A8; // TRIG pin
int echoPin = 45; // ECHO pin

float duration_us, distance;

// infrared to detect obstacle
int obs_front_left = 22;
int obs_front_right = 23;
int obs_back_left = 24;
int obs_back_right = 25;

// line tracker
int lnFrontLeft = A0;
int lnFrontLeftD = 30;
int lnFrontLeftValue;
int isLnFrontLeft;

int lnFrontRight = A1;
int lnFrontRightD = 31;
int lnFrontRightValue;
int isLnFrontRight;

int lnBackLeft = A2;
int lnBackLeftD = 32;
int lnBackLeftValue;
int isLnBackLeft;

int lnBackRight = A3;
int lnBackRightD = 33;
int lnBackRightValue;
int isLnBackRight;

Car myCar;
char autonomos = 'm';
char input;

void setup()
{
  myCar.setupFrontWheels(2, 3, 4, 5, 9, 10);
  myCar.setupBackWheels(7, 8, 12, 13, 6, 11);
  Serial.begin(9600);

  pinMode(obs_front_left, INPUT);
  pinMode(obs_front_right, INPUT);
  pinMode(obs_back_left, INPUT);
  pinMode(obs_back_right, INPUT);

  // line tracker analog values
  pinMode(lnFrontLeft, INPUT);
  pinMode(lnFrontRight, INPUT);
  pinMode(lnBackLeft, INPUT);
  pinMode(lnBackRight, INPUT);

  //  line tracker digital values
  pinMode(lnFrontLeftD, INPUT);
  pinMode(lnFrontRightD, INPUT);
  pinMode(lnBackLeftD, INPUT);
  pinMode(lnBackRightD, INPUT);

  // configure the trigger pin to output mode
  pinMode(trigPin, OUTPUT);
  // configure the echo pin to input mode
  pinMode(echoPin, INPUT);
}

void readDistance()
{
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // measure duration of pulse from ECHO pin
  duration_us = pulseIn(echoPin, HIGH);

  // calculate the distance
  distance = 0.017 * duration_us;

  // // print the value to Serial Monitor
  Serial.print("distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(100);
}

void stop()
{
  myCar.stopCar();
  delay(100);
}

void bluetooth()
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
    // moveCar();
  }
  delay(500);
}

void readLineTrackerSensors()
{

  //  line tracker analog values
  lnFrontLeftValue = analogRead(lnFrontLeft);
  lnFrontRightValue = analogRead(lnFrontRight);
  lnBackLeftValue = analogRead(lnBackLeft);
  lnBackRightValue = analogRead(lnBackRight);

  //  line tracker digital values
  isLnFrontLeft = digitalRead(lnFrontLeftD) == LOW && lnFrontLeftValue < 150;
  isLnFrontRight = digitalRead(lnFrontRightD) == LOW && lnFrontRightValue < 150;
  isLnBackLeft = digitalRead(lnBackLeftD) == LOW && lnBackLeftValue < 150;
  isLnBackRight = digitalRead(lnBackRightD) == LOW && lnBackRightValue < 150;
}

void loop()
{
  readDistance();
  readLineTrackerSensors();

  if (isLnBackLeft && isLnBackRight)
  {
    myCar.forward();
  }
  else if (isLnFrontLeft && isLnFrontRight)
  {
    myCar.backward();
  }
  else if (isLnBackLeft)
  {
    myCar.turnRight();
  }
  else if (isLnBackRight)
  {
    myCar.turnLeft();
  }
  else if (isLnFrontLeft)
  {
    myCar.backRight();
  }
  else if (isLnFrontRight)
  {
    myCar.backLeft();
  }
  else if (distance <= 50)
  {
    if (distance >= 30)
      myCar.forward();
    else
      myCar.push();
  }
  else
  {
    myCar.rotateLeft(100);
  }
}
