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
        const uint8_t slaveAddress;
    public:
        Test(hwlib::i2c_bus &i2cBus, uint8_t slaveAddress):
            i2cBus(i2cBus),
            slaveAddress(slaveAddress)
            {}
        void writeChannel(uint8_t message)
        {
            i2cBus.write(slaveAddress).write(message);
        }
};

int main()
{
    auto scl = hwlib::target::pin_oc(hwlib::target::pins::scl);
    auto sda = hwlib::target::pin_oc(hwlib::target::pins::sda);
    auto i2cBus = hwlib::i2c_bus_bit_banged_scl_sda(scl, sda);

    Test test1(i2cBus, 0x80);
    test1.writeChannel(0x6);
    test1.writeChannel(0x7);
}