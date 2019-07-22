#include "servo.hpp"

int main()
{
    auto sda = hwlib::target::pin_oc(hwlib::target::pins::sda);
    auto scl = hwlib::target::pin_oc(hwlib::target::pins::scl);
    auto i2cBus = hwlib::i2c_bus_bit_banged_scl_sda(scl, sda);

    PCA9685 controller(i2cBus, 50);         // Give i2c_bus + start frequency
    servo servo0(180, 0, controller);       // Servo maxDegrees = 180; id = 0; PWMcontroller controller
    servo0.moveDegrees(90);                 // Move servo for degrees
    //controller.readChannel();             // Read a given channel
    //controller.writeChannel();            // Write to a given channel
    controller.setFrequency(70);            // Change frequency
}  