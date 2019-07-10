#ifndef PWMCONTROLLER_HPP
#define PWMCONTROLLER_HPP

#include "hwlib.hpp"


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
        const bool oscillator;
    public:

/// \brief
/// Constructor for a PWM controller
/// \details
/// This constructor asks for an oscillator, though no value is needed as it'll automatically assume one is present.
/// If a controller without an oscillator were to be used, the value can simply be set to false in the constructor.
        PWMcontroller(int bits = 0, int channels = 0, bool oscillator = true):
            bits(bits),
            channels(channels),
            oscillator(oscillator)
            {}

/// \brief
/// Sends a signal to a channel
/// \details
/// This function sends a given signal to a given channel.
/// It is checked if the given channel is within the range of channels corresponding to the chip.
/// If the channel isn't within that range, it'll do nothing and skip the function entirely.
        void sendChannel(const int &channel); 

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
            PWMcontroller(12, 16)     // 12 bits and 16 channels are the PCA9685's values.
            {}
        
};

#endif //PWMCONTROLLER_HPP