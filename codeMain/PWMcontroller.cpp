//              Copyright Joram van Leeuwen 2019
// Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)


#include "PWMcontroller.hpp"

void PWMcontroller::writeChannel(uint8_t message)
{
    PWMcontroller::i2cBus.write(PWMcontroller::slaveAddress).write(message);
}

uint8_t PWMcontroller::readChannel(uint8_t channel)
{
    if(channel <= PWMcontroller::channels && channel > 0)
    {
        return PWMcontroller::i2cBus.read(PWMcontroller::slaveAddress).read(channel);
    }
    return 0x0;
}

void PWMcontroller::setFrequency(uint8_t frequency)
{
    if(PWMcontroller::oscillator == true)
    {
        PWMcontroller::i2cBus.write(PWMcontroller::slaveAddress).write(((PWMcontroller::oscillatorClock / (pow(2,PWMcontroller::bits) * frequency)) - 1));
    }
}

int PWMcontroller::getBits()
{
    return PWMcontroller::bits;
}