//              Copyright Joram van Leeuwen 2019
// Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)


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
        uint8_t degrees;
        const uint8_t maxRotation;
        const int id;
        PCA9685 kaas;
        const uint8_t constante = pow(2, kaas.getBits()) / maxRotation;;

/// \brief
/// Check degrees function
/// \details
/// This function checks if the given degrees is an allowed number.
/// If it's not allowed (either too small or too large), it'll be set to the servo's middle point.
/// This assumes an active duty cycle of 1-2ms.
        void checkDegrees();

/// \brief
/// Convert degrees to message function
/// \details
/// This function converts the given degrees to a message which can be sent to a slave's register using I2C.
        void convertDegreesMessage();

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