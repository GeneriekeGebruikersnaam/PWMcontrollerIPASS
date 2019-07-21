#include "servo.hpp"

int main()
{
    auto sda = hwlib::target::pin_oc(hwlib::target::pins::sda);
    auto scl = hwlib::target::pin_oc(hwlib::target::pins::scl);
    auto i2cBus = hwlib::i2c_bus_bit_banged_scl_sda(scl, sda);

    /*PCA9685 controller(i2cBus, 50);         // int frequency
    servo servo0(180, 0, controller);
    servo0.moveDegrees(90);         // int degrees
    controller.readChannel();
    controller.writeChannel();      // channel + message
    controller.setFrequency();      // int frequency
    */
}  