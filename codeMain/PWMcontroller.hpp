//              Copyright Joram van Leeuwen 2019
// Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)


#ifndef PWMCONTROLLER_HPP
#define PWMCONTROLLER_HPP

#include "hwlib.hpp"
#include <stdint.h>
#include <cmath>


/// @file

/// \brief
/// PWM controller class
/// \details
/// A reusable class for general PWM controllers which use I2C to communicate.
/// It is assumed the controller has an oscillator, though this can be changed.

class PWMcontroller
{
    private:
        const uint8_t prescaleAddress = 0xFE;
        const int bits;
        const int channels;
        const bool oscillator = false;
    protected:
        const uint8_t slaveAddress;
        hwlib::i2c_bus &i2cBus;
        const int oscillatorClock = 0;
        int frequency;
    public:

/// \brief
/// Constructor for a PWM controller without an oscillator
/// \details
/// This is a constructor for a PWM controller without an oscillator built in.
/// It just sets the number of bits and channels the chip has.
        PWMcontroller(int bits, int channels, uint8_t slaveAddress, hwlib::i2c_bus &i2cBus, int frequency):
            bits(bits),
            channels(channels),
            slaveAddress(slaveAddress),
            i2cBus(i2cBus),
            frequency(frequency)
            {setFrequency(frequency);}

/// \brief
/// Constructor for a PWM controller with an oscillator
/// \details
/// This is a constructor for a PWM controller with an oscillator built in.
/// It sets the bits, channels, whether an oscillator is present or not, and the oscillator's clock frequency in Hz.
/// The program assumes the oscillator's clock frequency is a constant value.
/// This constructor can be used to build upon an oscillator further if need be.

        PWMcontroller(int bits, int channels, bool oscillator, uint8_t slaveAddress, hwlib::i2c_bus &i2cBus, int oscillatorClock, int frequency):
            bits(bits),
            channels(channels),
            oscillator(oscillator),
            slaveAddress(slaveAddress),
            i2cBus(i2cBus),
            oscillatorClock(oscillatorClock),
            frequency(frequency)
            {setFrequency(frequency);}

/// \brief
/// Sends a signal to a channel
/// \details
/// This function sends a given signal to a given channel.
/// It is checked if the given channel is within the range of channels corresponding to the chip.
/// If the channel isn't within that range, it'll do nothing and skip the function entirely.
        void writeChannel(uint8_t message);

/// \brief
/// Reads a channel
/// \details
/// This function is used to read what is currently stored in any given register.
        uint8_t readChannel(uint8_t channel);

/// \brief
/// Sets a PWM controller's frequency
/// \details
/// This function is based on the formula for PCA9685 - my only point of reference.
/// With that chip it works as in this function, other chips may need doublechecking or an overriden function in a specific class.
/// Using this function will override the PWM's current frequency.
        void setFrequency(uint8_t frequency);

/// \brief
/// Gets the number of bits
/// \details
/// This function returns the number of bits in a PWM controller.
/// This function thus allows number of bits to be read in other, non-derived, classes.
        int getBits();

/// \brief
/// Gets the PWMcontroller's frequency
/// \details
/// This function returns the onboard frequency of the PWM controller.

        int getFrequency();

/// \brief
/// Gets the PWMcontroller's number of channels
/// \details
/// This function returns the number of channels the PWM controller has.
        int getChannels();
};

/// \brief
/// PCA9685 class
/// \details
/// A PWMcontroller class specified for the PCA9685 chip.

class PCA9685 : public PWMcontroller
{
    private:
        const uint8_t LED0_on_L = 0x06;
        const uint8_t mode1 = 0x00;
        void initialize();

    public:

/// \brief
/// PCA9685 constructor
/// \details
/// The oscillator is not set and is thus assumed by PWMcontroller to be true - which it is.
/// The PCA9685 has 16 channels, which is set in the constructor.
/// The PCA9685 has 12 bits and this is set in the constructor.
        PCA9685(hwlib::i2c_bus_bit_banged_scl_sda i2cBus, int frequency):
            PWMcontroller(12, 16, 1, 0x40, i2cBus, 25'000'000, frequency)         // 12 bits and 16 channels are the PCA9685's values.
            {initialize();}                                                 // There is an oscillator and its clock is 25MHz.
       
/// \brief
/// Send signal to PCA9685
/// \details
/// This function sends a signal to the PCA9685 using I2C.
        void movePWM(uint8_t pwmOutput, uint16_t onMoment, uint16_t offMoment);
};

#endif //PWMCONTROLLER_HPP