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
        const int bits;
        const int channels;
        const bool oscillator = false;
    protected:
        const int oscillatorClock = 0;
    public:

/// \brief
/// Constructor for a PWM controller without an oscillator
/// \details
/// This is a constructor for a PWM controller without an oscillator built in.
/// It just sets the number of bits and channels the chip has.
        PWMcontroller(int bits = 0, int channels = 0):
            bits(bits),
            channels(channels)
            {}

/// \brief
/// Constructor for a PWM controller with an oscillator
/// \details
/// This is a constructor for a PWM controller with an oscillator built in.
/// It sets the bits, channels, whether an oscillator is present or not, and the oscillator's clock frequency in Hz.
/// The program assumes the oscillator's clock frequency is a constant value.        
        PWMcontroller(int bits, int channels, bool oscillator, int oscillatorClock):
            bits(bits),
            channels(channels),
            oscillator(oscillator),
            oscillatorClock(oscillatorClock)
            {}

/// \brief
/// Sends a signal to a channel
/// \details
/// This function sends a given signal to a given channel.
/// It is checked if the given channel is within the range of channels corresponding to the chip.
/// If the channel isn't within that range, it'll do nothing and skip the function entirely.
        void writeChannel(const int &channel, int message [6]);

/// \brief
/// Reads a channel
/// \details
/// This function is used to read what is currently stored in any given register.
        uint8_t readChannel(const int &channel);

/// \brief
/// Sets a PWM controller's frequency
/// \details
/// This function is based on the formula for PCA9685 - my only point of reference.
/// With that chip it works as in this function, other chips may need doublechecking or an overriden function in a specific class.
        void setFrequency(const int &frequency);
};

/// \brief
/// PCA9685 class
/// \details
/// A PWMcontroller class specified for the PCA9685 chip.

class PCA9685 : public PWMcontroller
{
    private:

    public:

/// \brief
/// PCA9685 constructor
/// \details
/// The oscillator is not set and is thus assumed by PWMcontroller to be true - which it is.
/// The PCA9685 has 16 channels, which is set in the constructor.
/// The PCA9685 has 12 bits and this is set in the constructor.
        PCA9685():
            PWMcontroller(12, 16, true, 25'000'000)     // 12 bits and 16 channels are the PCA9685's values.
            {}                                          // There is an oscillator and its clock is 25MHz.
       
};

#endif //PWMCONTROLLER_HPP