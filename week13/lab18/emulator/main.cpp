#include <iostream>
#include "/home/zhan/Desktop/MDV101/week13/lab18/emulator/bitty_emu.h"
#include <bitset>
#include <fstream>
#include <vector>
#include <cstdint>

#define NUM_INTS 256

int main()
{
    BittyEmulator emulator;
    bool j_type = false;
    emulator.LoadMemoryFromFile("/home/zhan/Desktop/MDV101/week13/lab18/generator/instructions.txt", 0);
    // for (int i = 0; i < NUM_INTS; i++)
    // {
    //     std::cout << "Memory[" << std::dec << i << "]: " << std::hex << emulator.GetMemoryValue(i) << std::endl;
    // }
    std::cout << "Loaded instructions from file." << std::endl;
    std::cout << "Starting execution..." << std::endl;

    // Open a file to save register_c values
    std::ofstream registerCFile("txt/register_c_values.txt");
    if (!registerCFile.is_open()) {
        std::cerr << "Error: Could not open file register_c_values.txt for writing." << std::endl;
        return 1;
    }

    // Create and open the instruction fetch unit output file
    std::ofstream instructionFetchFile("txt/instruction_fetch_unit_out.txt");
    if (!instructionFetchFile.is_open()) {
        std::cerr << "Error: Could not open file instruction_fetch_unit_out.txt for writing." << std::endl;
        return 1;
    }

    // Create and open the pc output file
    std::ofstream pcOutFile("txt/pc_out.txt");
    if (!pcOutFile.is_open()) {
        std::cerr << "Error: Could not open file pc_out.txt for writing." << std::endl;
        return 1;
    }

    for (int i = 0; i < NUM_INTS; i++)
    {
        // Save register_c value to the file
        registerCFile << emulator.GetRegisterCValue() << std::endl;
        instructionFetchFile << std::hex <<emulator.GetMemoryValue(emulator.GetPCValue()) << std::endl;
        pcOutFile << std::dec << emulator.GetPCValue() << std::endl;
        j_type = false;
        std::cout << "Cycle: " << std::dec << i << std::endl;
        std::cout << "PC: " << std::bitset<8>(emulator.GetPCValue()) << " (DEC: " << std::dec << (emulator.GetPCValue()) << ")" << " (HEX: " << std::hex << emulator.GetPCValue() << ")" << std::endl;
        std::cout << "Instruction: " << std::bitset<16>(emulator.GetMemoryValue(emulator.GetPCValue())) << " (DEC: " << std::dec << (emulator.GetMemoryValue(emulator.GetPCValue())) << ")" << " (HEX: " << std::hex << emulator.GetMemoryValue(emulator.GetPCValue()) << ")" << std::endl;
        std::cout << "Format: ";
        switch ((emulator.GetMemoryValue(emulator.GetPCValue())) & 0b11)
        {
            case 0b00: std::cout << "R-type"; break;
            case 0b01: std::cout << "I-type"; break;
            case 0b10: std::cout << "J-type"; break;
            default: std::cout << "R-type"; break;
        }
        std::cout << std::endl;
        std::cout << "Operation: ";
        if (((emulator.GetMemoryValue(emulator.GetPCValue())) & 0b11) == 0b10)
        {
            switch(((emulator.GetMemoryValue(emulator.GetPCValue())) >> 2) & 0b11)
            {
                case 0b00: std::cout << "BEZ"; break;
                case 0b01: std::cout << "BE (1)"; break;
                case 0b10: std::cout << "BE (2)"; break;
                default: std::cout << "BEZ"; break;
            }
            j_type = true;
        }
        else 
        {
            switch ((emulator.GetMemoryValue(emulator.GetPCValue())) >> 2 & 0x07)
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
        }
        std::cout << std::endl;
        std::cout << "register_c = " << std::dec <<emulator.GetRegisterCValue() << std::endl;
        std::cout << "Rx = " << std::bitset<16>((emulator.GetMemoryValue(emulator.GetPCValue()) >> 13) & 0b111) << " (DEC: " << std::dec << ((emulator.GetMemoryValue(emulator.GetPCValue()) >> 13) & 0b111) << ")" << " (HEX: " << std::hex << ((emulator.GetMemoryValue(emulator.GetPCValue()) >> 13) & 0b111) << ")" << std::endl;
        std::cout << "Ry = " << std::bitset<16>((emulator.GetMemoryValue(emulator.GetPCValue()) >> 10) & 0b111) << " (DEC: " << std::dec << ((emulator.GetMemoryValue(emulator.GetPCValue()) >> 10) & 0b111) << ")" << " (HEX: " << std::hex << ((emulator.GetMemoryValue(emulator.GetPCValue()) >> 10) & 0b111) << ")" << std::endl;
        if (j_type)
        {
            std::cout << "Immediate value = " << std::bitset<12>((emulator.GetMemoryValue(emulator.GetPCValue()) >> 4) & 0xFFF) << " (" << std::dec << ((emulator.GetMemoryValue(emulator.GetPCValue()) >> 4) & 0xFFF) << ")" << " (HEX: " << std::hex << ((emulator.GetMemoryValue(emulator.GetPCValue()) >> 4) & 0xFFF) << ")" << std::endl;
        }
        else 
        {
            std::cout << "Immediate value = " << std::bitset<8>((emulator.GetMemoryValue(emulator.GetPCValue()) >> 5) & 0xFF) << " (" << std::dec << ((emulator.GetMemoryValue(emulator.GetPCValue()) >> 5) & 0xFF) << ")" << " (HEX: " << std::hex << ((emulator.GetMemoryValue(emulator.GetPCValue()) >> 5) & 0xFF) << ")" << std::endl;
        }
        std::cout << "Register 0: " << std::hex << std::bitset<16>(emulator.GetRegisterValue(0)) << std::endl;
        std::cout << "Register 1: " << std::hex << std::bitset<16>(emulator.GetRegisterValue(1)) << std::endl;
        std::cout << "Register 2: " << std::hex << std::bitset<16>(emulator.GetRegisterValue(2)) << std::endl;
        std::cout << "Register 3: " << std::hex << std::bitset<16>(emulator.GetRegisterValue(3)) << std::endl;
        std::cout << "Register 4: " << std::hex << std::bitset<16>(emulator.GetRegisterValue(4)) << std::endl;
        std::cout << "Register 5: " << std::hex << std::bitset<16>(emulator.GetRegisterValue(5)) << std::endl;
        std::cout << "Register 6: " << std::hex << std::bitset<16>(emulator.GetRegisterValue(6)) << std::endl; 
        std::cout << "Register 7: " << std::hex << std::bitset<16>(emulator.GetRegisterValue(7)) << std::endl << std::endl;

        emulator.Step();
    }
    // Close the file
    registerCFile.close();
    instructionFetchFile.close();
    pcOutFile.close();
    std::cout << "Execution completed." << std::endl;
    return 0;
}