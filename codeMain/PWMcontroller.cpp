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

int PWMcontroller::getFrequency()
{
    return PWMcontroller::frequency;
}

int PWMcontroller::getChannels()
{
    return PWMcontroller::channels;
}

void PCA9685::initialize()
{
    hwlib::i2c_write_transaction writeTransaction = PCA9685::i2cBus.write(slaveAddress);
    writeTransaction.write(PCA9685::mode1);
    writeTransaction.write(0x21);       // 00100001
}

void PCA9685::movePWM(uint8_t pwmOutput, uint16_t onMoment, uint16_t offMoment)
{
    uint8_t lowbyteOn = uint8_t(onMoment & 0xff);
    uint8_t highbyteOn = uint8_t(onMoment >> 8);
    uint8_t lowbyteOff = uint8_t(offMoment & 0xff);
    uint8_t highbyteOff = uint8_t(offMoment >> 8);

    hwlib::i2c_write_transaction writeTransaction = PCA9685::i2cBus.write(slaveAddress);

    writeTransaction.write(PCA9685::LED0_on_L + 4*pwmOutput);
    writeTransaction.write(lowbyteOn);
    writeTransaction.write(highbyteOn);
    writeTransaction.write(lowbyteOff);
    writeTransaction.write(highbyteOff);
}