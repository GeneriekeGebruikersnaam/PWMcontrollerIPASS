#include "servo.hpp"

void servo::setFrequency()
{
    PCA9685 controller;
    controller.setFrequency(servo::frequency);
}

int servo::checkDegrees(int &degrees)
{
    if(degrees < 0 || degrees > servo::maxRotation){return maxRotation / 2;}
    return degrees;
}

void servo::moveDegrees(int &degrees)
{
    degrees = servo::checkDegrees(degrees);
    PCA9685 controller;
    controller.writeChannel(/* Put degrees in here */);
}