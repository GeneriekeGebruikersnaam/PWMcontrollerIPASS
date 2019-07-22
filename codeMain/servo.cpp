//              Copyright Joram van Leeuwen 2019
// Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)


#include "servo.hpp"

void servo::checkDegrees()
{
    if(servo::degrees < 0 || servo::degrees > servo::maxRotation){servo::degrees = maxRotation / 2;}
}

void servo::convertDegreesMessage()
{
    servo::checkDegrees();
    servo::degrees = servo::constante * servo::degrees;
}

void servo::moveDegrees(uint8_t degrees)
{
    servo::degrees = degrees;
    servo::convertDegreesMessage();
    servo::kaas.writeChannel(servo::degrees);
}