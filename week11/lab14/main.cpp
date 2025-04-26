#include <iostream>
#include "bitty_emu.h"

int main()
{
    // Test 1
    BittyEmulator   emulator;
    uint16_t        testinstruction = 0b0000010000000000;
    emulator.SetRegisterValue(0, 0b0000000000000000);
    emulator.SetRegisterValue(1, 0b0000000000000001);
    emulator.Evaluate(testinstruction);
    uint16_t        regValue = emulator.GetRegisterValue(0);
    uint16_t        expected_value = 0b0000000000000001;
    if (regValue == expected_value)
    {
        std::cout << "Test passed!" << std::endl;
    }
    else
    {
        std::cout << "Test failed! Expected: " << expected_value << ", Got: " << regValue << std::endl;
    }

    // Test 2
    testinstruction = 0b0000100000000001; // 0000000001000000
    emulator.ResetRegisters();
    emulator.SetRegisterValue(0, 0b0000000000010000);
    emulator.Evaluate(testinstruction);
    regValue = emulator.GetRegisterValue(0);
    expected_value = 0b0000000001010000;
    if (regValue == expected_value)
    {
        std::cout << "Test passed!" << std::endl;
    }
    else
    {
        std::cout << "Test failed! Expected: " << expected_value << ", Got: " << regValue << std::endl;
    }
    return 0;
}