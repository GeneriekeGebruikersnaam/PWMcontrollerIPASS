#include "PWMcontroller.hpp"

void PWMcontroller::writeChannel(const int &channel, int[6] message)
{
    if(channel <= PWMcontroller::channels && channel > 0)
    {
        int[8] toWrite;
        toWrite[0] = 1;
        toWrite[7] = 0;
        for(int i = 1; i < 7)
        {
            toWrite[i] = message[i-1];
        }
    }

    // Write int[8] toWrite to PWM controller

}

uint8_t PWMcontroller::readChannel(const int &channel)
{
    if(channel <= PWMcontroller::channels && channel > 0)
    {

    }
}

void PCA9685::setFrequency(int frequency)
{
    (PWMcontroller::oscillatorClock / (4096 * frequency)) - 1;
    // send to PRE_SCALE
}