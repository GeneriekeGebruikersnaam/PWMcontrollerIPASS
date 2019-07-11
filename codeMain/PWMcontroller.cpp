#include "PWMcontroller.hpp"

void PWMcontroller::writeChannel(const int &channel, int message [6])
{
    if(channel <= PWMcontroller::channels && channel > 0)
    {
        int toWrite [8];
        toWrite [0] = 1;
        toWrite [7] = 0;
        for(int i = 1; i < 7; i++)
        {
            toWrite [i] = message [i-1];
        }
    }

    // Write int[8] toWrite to PWM controller on channel

}

uint8_t PWMcontroller::readChannel(const int &channel)
{
    if(channel <= PWMcontroller::channels && channel > 0)
    {
        // return channel's value
    }
    return 0;
}

void PWMcontroller::setFrequency(const int &frequency)
{
    ((PWMcontroller::oscillatorClock / (pow(2,PWMcontroller::bits) * frequency)) - 1);
    /// Write this to PWM controller's prescale register 
}