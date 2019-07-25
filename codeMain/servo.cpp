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

void setOnOff()
{

}

void servo::moveDegrees(uint8_t degrees)
{
    servo::degrees = degrees;
    servo::convertDegreesMessage();

    for(int i = 0; i < 100; i++)
    {
        for(offMoment = 2; offMoment < 2000; offMoment++)
        {
            for(pwmOutput = 0; pwmOutput < servo::kaas.getChannels(); pwmOutput++)
            {
                servo::kaas.movePWM(pwmOutput, onMoment, offMoment);
            }
        }
    }
}