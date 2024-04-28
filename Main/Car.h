#ifndef Car_H  // Guard against multiple inclusions
#define Car_H

class Car {

  private:
    int frontLeftIn1;
    int frontLeftIn2;
    int frontRightIn3;
    int frontRightIn4;

    int frontLeftSpeed;
    int frontRightSpeed;

    int backLeftIn1;
    int backLeftIn2;
    int backRightIn3;
    int backRightIn4;

    int backRightSpeed;
    int backLeftSpeed;

    int frontWheelsSpeed;
    int backWheelsSpeed;

    void goForward(int frontLeftSpeed, int frontRightSpeed, int backLeftSpeed, int backRightSpeed);
    void goBackward(int frontLeftSpeed, int frontRightSpeed, int backLeftSpeed, int backRightSpeed);

  public:
    // Public member functions (methods)
    void setupFrontWheels(int fl1, int fl2, int fr3, int fr4, int flSpeed, int frSpeed);
    void setupBackWheels(int bl1, int bl2, int br3, int br4, int blSpeed, int brSpeed);
    void forward();
    void backward();
    void push();
    void turnLeft();
    void turnRight();
    void backLeft();
    void backRight();
    void moveCar(char direc);
    void stopCar();
};

#endif
