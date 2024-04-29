
#include "Car.h"
#include "Arduino.h"

int trigPin = A8; // TRIG pin
int echoPin = 45; // ECHO pin

float duration_us, distance;

// infrared to detect obstacle
int obs_front = 41;
int obs_back = 42;
int obs_right = 40;
int obs_left = 43;

Car myCar;
char autonomos = 'm';
char input;

void setup()
{
  myCar.setupFrontWheels(2, 3, 4, 5, 9, 10);
  myCar.setupBackWheels(7, 8, 12, 13, 6, 11);
  Serial.begin(9600);

  pinMode(obs_front, INPUT);
  pinMode(obs_back, INPUT);
  pinMode(obs_right, INPUT);
  pinMode(obs_left, INPUT);

  // configure the trigger pin to output mode
  pinMode(trigPin, OUTPUT);
  // configure the echo pin to input mode
  pinMode(echoPin, INPUT);
}

void setDistance()
{
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(20);
  digitalWrite(trigPin, LOW);

  // measure duration of pulse from ECHO pin
  duration_us = pulseIn(echoPin, HIGH);

  // calculate the distance
  distance = 0.017 * duration_us;

  // print the value to Serial Monitor
  Serial.print("distance: ");
  Serial.print(distance);
  Serial.println(" cm");
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
    moveCar();
  }
  delay(500);
}

void loop()
{
  int IR1 = digitalRead(obs_front);
  int IR2 = digitalRead(obs_back);
  int IR3 = digitalRead(obs_right);
  int IR4 = digitalRead(obs_left);
  setDistance();
  delay(200);

  if (distance > 150)
  {
    myCar.turnLeft();
    setDistance();
    delay(200);
  }
  else if (distance <= 90 && distance > 30)
  {
    myCar.forward();
    setDistance();
    delay(200);
  }
  else if (distance <= 30 && distance > 20)
  {
    myCar.forward();
    setDistance();
    delay(200);
  }
  IR1 = digitalRead(obs_front);

  while (distance <= 20)
  {
    delay(500);

    myCar.push();
    setDistance();

    IR1 = digitalRead(obs_front);
    IR2 = digitalRead(obs_back);
    IR3 = digitalRead(obs_right);
    IR4 = digitalRead(obs_left);

  }
}
