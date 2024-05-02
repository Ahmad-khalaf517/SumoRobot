
#include "Car.h"
#include "Arduino.h"

int trigPin = A8; // TRIG pin
int echoPin = 45; // ECHO pin

float duration_us, distance;

// infrared to detect obstacle
int obs_front_left = 22;
int obs_front_right = 23;
int obs_back_left = 24;

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
  distance = 0.017 * duration_us / 2;
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

void loop()
{
  int ir_front_left = digitalRead(obs_front_left);
  int ir_front_right = digitalRead(obs_front_right);
  int ir_back_left = digitalRead(obs_back_left);

  readDistance();

  if (distance > 150 && (ir_front_left == HIGH && ir_front_right == HIGH))
  {
    myCar.turnLeft();
    readDistance();
  }
  else if (distance <= 50 && distance > 20)
  {
    myCar.forward();
    readDistance();
  }

  if (ir_front_left == LOW && ir_front_right == HIGH)
    myCar.turnLeft();

  if (ir_front_left == HIGH && ir_front_right == LOW)
    myCar.turnRight();

  if (distance <= 20)
  {
    myCar.push();
    delay(1000);
    readDistance();

    ir_front_left = digitalRead(obs_front_left);
    ir_front_right = digitalRead(obs_front_right);
    ir_back_left = digitalRead(obs_back_left);
  }
  delay(100);
}
