#include <iostream>
#include "/home/zhan/Desktop/MDV101/week12/lab16/emulator/bitty_emu.h"
#include <bitset>
#define NUM_INTS 256

int main()
{
    BittyEmulator emulator;
    emulator.LoadMemoryFromFile("/home/zhan/Desktop/MDV101/week12/lab16/generator/instructions.txt", 0);
    for (int i = 0; i < NUM_INTS; i++)
    {
        std::cout << "Memory[" << i << "]: " << std::hex << emulator.GetMemoryValue(i) << std::endl;
    }
    std::cout << "Loaded instructions from file." << std::endl;
    std::cout << "Starting execution..." << std::endl;
    for (int i = 0; i < NUM_INTS; i++)
    {
        std::cout << "PC: " << emulator.GetPCValue() << std::endl;
        emulator.Step();
        std::cout << "Format: ";
        switch ((emulator.GetMemoryValue(i)) & 0b11)
        {
            case 0b01: std::cout << "I-type"; break;
            default: std::cout << "R-type"; break;
        }
        std::cout << std::endl;
        std::cout << "Operation: ";
        switch ((emulator.GetMemoryValue(i)) >> 2 & 0x07)
        {
            case 0x00: std::cout << "ADD"; break;
            case 0x01: std::cout << "SUB"; break;
            case 0x02: std::cout << "AND"; break;
            case 0x03: std::cout << "OR"; break;
            case 0x04: std::cout << "XOR"; break;
            case 0x05: std::cout << "SHL"; break;
            case 0x06: std::cout << "SHR"; break;
            case 0x07: std::cout << "CONDITION"; break;
            default: std::cout << "Unknown operation"; break;
        }
        std::cout << std::endl;
        std::cout << "Rx = " << ((emulator.GetMemoryValue(i) >> 13) & 0b111) << std::endl;
        std::cout << "Ry = " << ((emulator.GetMemoryValue(i) >> 10) & 0b111) << std::endl;
        std::cout << "Immediate value = " << std::bitset<8>((emulator.GetMemoryValue(i) >> 5) & 0xFF) << std::endl;
        std::cout << "Register 0: " << std::hex << std::bitset<16>(emulator.GetRegisterValue(0)) << std::endl;
        std::cout << "Register 1: " << std::hex << std::bitset<16>(emulator.GetRegisterValue(1)) << std::endl;
        std::cout << "Register 2: " << std::hex << std::bitset<16>(emulator.GetRegisterValue(2)) << std::endl;
        std::cout << "Register 3: " << std::hex << std::bitset<16>(emulator.GetRegisterValue(3)) << std::endl;
        std::cout << "Register 4: " << std::hex << std::bitset<16>(emulator.GetRegisterValue(4)) << std::endl;
        std::cout << "Register 5: " << std::hex << std::bitset<16>(emulator.GetRegisterValue(5)) << std::endl;
        std::cout << "Register 6: " << std::hex << std::bitset<16>(emulator.GetRegisterValue(6)) << std::endl; 
        std::cout << "Register 7: " << std::hex << std::bitset<16>(emulator.GetRegisterValue(7)) << std::endl << std::endl;
    }
    std::cout << "Execution completed." << std::endl;
    return 0;
}