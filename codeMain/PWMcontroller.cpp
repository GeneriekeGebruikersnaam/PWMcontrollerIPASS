#include "PWMcontroller.hpp"

void PWMcontroller::writeChannel(const uint8_t &slaveAddress, uint8_t &message)
{
    PWMcontroller::i2cBus.write(slaveAddress).write(message);
}

uint8_t PWMcontroller::readChannel(uint8_t &slaveAddress, uint8_t &channel)
{
    if(channel <= PWMcontroller::channels && channel > 0)
    {
        return PWMcontroller::i2cBus.read(slaveAddress).read(channel);
    }
    return 0x0;
}

void PWMcontroller::setFrequency(uint8_t frequency)
{
    if(PWMcontroller::oscillator == true)
    {
        PWMcontroller::i2cBus.write(PWMcontroller::prescaleAddress).write(((PWMcontroller::oscillatorClock / (pow(2,PWMcontroller::bits) * frequency)) - 1));
        /// Write this to PWM controller's prescale register 
    }
}