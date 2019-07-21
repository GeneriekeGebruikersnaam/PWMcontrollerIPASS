#ifndef SERVO_HPP
#define SERVO_HPP

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
        const uint8_t maxRotation;
        const int id;
        PWMcontroller kaas;
        const uint8_t constante = pow(2, kaas.bits) / maxRotation;;

        uint8_t checkDegrees(uint8_t degrees);
        uint8_t convertDegreesMessage(uint8_t degrees);

    public:

/// \brief
/// Constructor for class servo
/// \details
/// This constructor asks for the maximum amount of degrees the servo can rotate for.
        servo(uint8_t maxRotation, int id, PWMcontroller kaas):
            maxRotation(maxRotation),
            id(id),
            kaas(kaas)
            {}

/// \brief
/// Move servo for degrees
/// \details
/// This function moves a servo for a given amount of degrees.
        void moveDegrees(uint8_t degrees);
};

#endif //SERVO_HPP