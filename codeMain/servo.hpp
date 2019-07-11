#ifndef SERVO_HPP
#define SEVOHPP

#include "PWMcontroller.hpp"


/// @file

/// \brief
/// A universal servo class
/// \details
/// This class can be used for a variation of servos which all work the same according to convention.
/// The convention is roughly like this:
/// A duty cycle of ~5% is equal to 0% of its rotation;
/// A duty cycle of ~7.5% is equal to 50% of its rotation;
/// A duty cycle of ~10% is equal to 100% of its rotation.

class servo
{
    private:
        const int maxRotation;
        const int frequency;

        void setFrequency();
        int checkDegrees(int &degrees);

    public:

/// \brief
/// Constructor for class servo
/// \details
/// This constructor asks for the maximum amount of degrees the servo can rotate for.
        servo(int &maxRotation, int &frequency):
            maxRotation(maxRotation),
            frequency(frequency)
            {setFrequency();}

/// \brief
/// Move servo for degrees
/// \details
/// This function moves a servo for a given amount of degrees.
        void moveDegrees(int &degrees);
};

#endif //SERVO_HPP