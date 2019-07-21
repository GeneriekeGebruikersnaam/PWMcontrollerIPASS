#include "hwlib.hpp"
#include <stdint.h>

void writeToH(uint_fast8_t address, uint8_t hRegister, uint8_t data, hwlib::i2c_bus i2cBus)
{
    i2cBus.write(address).write(hRegister);
    i2cBus.write(address).write(data);
}

class Test
{
    private:
        hwlib::i2c_bus &i2cBus;
    public:
        Test(hwlib::i2c_bus &i2cBus):
            i2cBus(i2cBus)
            {}
        void writeChannel(uint8_t address, uint8_t message)
        {
            i2cBus.write(address).write(message);
        }
};

int main()
{
    auto scl = hwlib::target::pin_oc(hwlib::target::pins::scl);
    auto sda = hwlib::target::pin_oc(hwlib::target::pins::sda);
    auto i2cBus = hwlib::i2c_bus_bit_banged_scl_sda(scl, sda);

    Test test1(i2cBus);
    test1.writeChannel(0x3, 0x55);
}