#include "servo.hpp"

uint8_t servo::checkDegrees(uint8_t degrees)
{
    if(degrees < 0 || degrees > servo::maxRotation){return maxRotation / 2;}
    return degrees;
}

uint8_t servo::convertDegreesMessage(uint8_t degrees)
{
    degrees = servo::checkDegrees(degrees);
    //servo::constante * degrees;
    return /*Convert the degrees to the right message for a channel on the PWMcontroller*/ 0;
}

void servo::moveDegrees(uint8_t degrees)
{
    degrees = servo::convertDegreesMessage(degrees);
    servo::kaas.writeChannel(servo::id, degrees);
}