#include <iostream>
#include "/home/zhan/Desktop/MDV101/week14/lab19/emulator/bitty_emu.h"
#include <bitset>
#include <fstream>
#include <vector>
#include <cstdint>

#define NUM_INTS 256

int main()
{
    BittyEmulator emulator;
    bool j_type = false;
    emulator.LoadInstructionMemoryFromFile("/home/zhan/Desktop/MDV101/week14/lab19/generator/instructions.txt", 0);
    // for (int i = 0; i < NUM_INTS; i++)
    // {
    //     std::cout << "Memory[" << std::dec << i << "]: " << std::hex << emulator.GetInstructionMemoryValue(i) << std::endl;
    // }
    std::cout << "Loaded instructions from file." << std::endl;
    std::cout << "Starting execution..." << std::endl;

    // Open a file to save register_c values
    std::ofstream registerCFile("/home/zhan/Desktop/MDV101/week14/lab19/emulator/txt/register_c_values.txt");
    if (!registerCFile.is_open()) {
        std::cerr << "Error: Could not open file register_c_values.txt for writing." << std::endl;
        return 1;
    }

    // Create and open the instruction fetch unit output file
    std::ofstream instructionFetchFile("/home/zhan/Desktop/MDV101/week14/lab19/emulator/txt/instruction_fetch_unit_out.txt");
    if (!instructionFetchFile.is_open()) {
        std::cerr << "Error: Could not open file instruction_fetch_unit_out.txt for writing." << std::endl;
        return 1;
    }

    // Create and open the pc output file
    std::ofstream pcOutFile("/home/zhan/Desktop/MDV101/week14/lab19/emulator/txt/pc_out.txt");
    if (!pcOutFile.is_open()) {
        std::cerr << "Error: Could not open file pc_out.txt for writing." << std::endl;
        return 1;
    }

    for (int i = 0; i < NUM_INTS; i++)
    {
        // Save register_c value to the file
        registerCFile << emulator.GetRegisterCValue() << std::endl;
        instructionFetchFile << std::hex <<emulator.GetInstructionMemoryValue(emulator.GetPCValue()) << std::endl;
        pcOutFile << std::dec << emulator.GetPCValue() << std::endl;
        j_type = false;
        std::cout << "Cycle: " << std::dec << i << std::endl;
        std::cout << "PC: " << std::bitset<8>(emulator.GetPCValue()) << " (DEC: " << std::dec << (emulator.GetPCValue()) << ")" << " (HEX: " << std::hex << emulator.GetPCValue() << ")" << std::endl;
        std::cout << "Instruction: " << std::bitset<16>(emulator.GetInstructionMemoryValue(emulator.GetPCValue())) << " (DEC: " << std::dec << (emulator.GetInstructionMemoryValue(emulator.GetPCValue())) << ")" << " (HEX: " << std::hex << emulator.GetInstructionMemoryValue(emulator.GetPCValue()) << ")" << std::endl;
        std::cout << "Format: ";
        switch ((emulator.GetInstructionMemoryValue(emulator.GetPCValue())) & 0b11)
        {
            case 0b00: std::cout << "R-type"; break;
            case 0b01: std::cout << "I-type"; break;
            case 0b10: std::cout << "J-type"; break;
            case 0b11: std::cout << "LOAD/STORE-type"; break;
        }
        std::cout << std::endl;
        std::cout << "Operation: ";
        if (((emulator.GetInstructionMemoryValue(emulator.GetPCValue())) & 0b11) == 0b10) // J-type
        {
            switch(((emulator.GetInstructionMemoryValue(emulator.GetPCValue())) >> 2) & 0b11)
            {
                case 0b00: std::cout << "BEZ"; break;
                case 0b01: std::cout << "BE (1)"; break;
                case 0b10: std::cout << "BE (2)"; break;
                default: std::cout << "BEZ"; break;
            }
            j_type = true;
        }
        else if (((emulator.GetInstructionMemoryValue(emulator.GetPCValue())) & 0b11) == 0b11)  // LOAD STORE -type
        {
            switch(((emulator.GetInstructionMemoryValue(emulator.GetPCValue())) >> 2) & 0b1)
            {
                case 0b0: std::cout << "LOAD"; break;
                case 0b1: std::cout << "STORE"; break;
            }
        }
        else // R and I type (gets the same operations)
        {
            switch ((emulator.GetInstructionMemoryValue(emulator.GetPCValue())) >> 2 & 0x07) 
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
        std::cout << "Rx = " << std::bitset<16>((emulator.GetInstructionMemoryValue(emulator.GetPCValue()) >> 13) & 0b111) << " (DEC: " << std::dec << ((emulator.GetInstructionMemoryValue(emulator.GetPCValue()) >> 13) & 0b111) << ")" << " (HEX: " << std::hex << ((emulator.GetInstructionMemoryValue(emulator.GetPCValue()) >> 13) & 0b111) << ")" << std::endl;
        std::cout << "Ry = " << std::bitset<16>((emulator.GetInstructionMemoryValue(emulator.GetPCValue()) >> 10) & 0b111) << " (DEC: " << std::dec << ((emulator.GetInstructionMemoryValue(emulator.GetPCValue()) >> 10) & 0b111) << ")" << " (HEX: " << std::hex << ((emulator.GetInstructionMemoryValue(emulator.GetPCValue()) >> 10) & 0b111) << ")" << std::endl;
        if (j_type)
        {
            std::cout << "Immediate value = " << std::bitset<12>((emulator.GetInstructionMemoryValue(emulator.GetPCValue()) >> 4) & 0xFFF) << " (DEC: " << std::dec << ((emulator.GetInstructionMemoryValue(emulator.GetPCValue()) >> 4) & 0xFFF) << ")" << " (HEX: " << std::hex << ((emulator.GetInstructionMemoryValue(emulator.GetPCValue()) >> 4) & 0xFFF) << ")" << std::endl;
        }
        else 
        {
            std::cout << "Immediate value = " << std::bitset<8>((emulator.GetInstructionMemoryValue(emulator.GetPCValue()) >> 5) & 0xFF) << " (DEC: " << std::dec << ((emulator.GetInstructionMemoryValue(emulator.GetPCValue()) >> 5) & 0xFF) << ")" << " (HEX: " << std::hex << ((emulator.GetInstructionMemoryValue(emulator.GetPCValue()) >> 5) & 0xFF) << ")" << std::endl;
        }
        std::cout << "Memory[0] = " << std::bitset<16>(emulator.GetRegisterMemoryValue(0)) << " (DEC: " << std::dec << emulator.GetRegisterMemoryValue(0) << ") (HEX: " << std::hex << emulator.GetRegisterMemoryValue(0) << ")" << std::endl;
        std::cout << "Memory[1] = " << std::bitset<16>(emulator.GetRegisterMemoryValue(1)) << " (DEC: " << std::dec << emulator.GetRegisterMemoryValue(1) << ") (HEX: " << std::hex << emulator.GetRegisterMemoryValue(1) << ")" << std::endl;
        std::cout << "Memory[2] = " << std::bitset<16>(emulator.GetRegisterMemoryValue(2)) << " (DEC: " << std::dec << emulator.GetRegisterMemoryValue(2) << ") (HEX: " << std::hex << emulator.GetRegisterMemoryValue(2) << ")" << std::endl;
        std::cout << "Memory[3] = " << std::bitset<16>(emulator.GetRegisterMemoryValue(3)) << " (DEC: " << std::dec << emulator.GetRegisterMemoryValue(3) << ") (HEX: " << std::hex << emulator.GetRegisterMemoryValue(3) << ")" << std::endl;
        std::cout << "Memory[4] = " << std::bitset<16>(emulator.GetRegisterMemoryValue(4)) << " (DEC: " << std::dec << emulator.GetRegisterMemoryValue(4) << ") (HEX: " << std::hex << emulator.GetRegisterMemoryValue(4) << ")" << std::endl;
        std::cout << "Memory[5] = " << std::bitset<16>(emulator.GetRegisterMemoryValue(5)) << " (DEC: " << std::dec << emulator.GetRegisterMemoryValue(5) << ") (HEX: " << std::hex << emulator.GetRegisterMemoryValue(5) << ")" << std::endl;
        std::cout << "Memory[6] = " << std::bitset<16>(emulator.GetRegisterMemoryValue(6)) << " (DEC: " << std::dec << emulator.GetRegisterMemoryValue(6) << ") (HEX: " << std::hex << emulator.GetRegisterMemoryValue(6) << ")" << std::endl;
        std::cout << "Memory[7] = " << std::bitset<16>(emulator.GetRegisterMemoryValue(7)) << " (DEC: " << std::dec << emulator.GetRegisterMemoryValue(7) << ") (HEX: " << std::hex << emulator.GetRegisterMemoryValue(7) << ")" << std::endl;
        std::cout << "Register 0: " << std::hex << std::bitset<16>(emulator.GetRegisterValue(0)) << " (DEC: " << std::dec << emulator.GetRegisterValue(0) << ") (HEX: " << std::hex << emulator.GetRegisterValue(0) << ")" << std::endl;
        std::cout << "Register 1: " << std::hex << std::bitset<16>(emulator.GetRegisterValue(1)) << " (DEC: " << std::dec << emulator.GetRegisterValue(1) << ") (HEX: " << std::hex << emulator.GetRegisterValue(1) << ")" << std::endl;
        std::cout << "Register 2: " << std::hex << std::bitset<16>(emulator.GetRegisterValue(2)) << " (DEC: " << std::dec << emulator.GetRegisterValue(2) << ") (HEX: " << std::hex << emulator.GetRegisterValue(2) << ")" << std::endl;
        std::cout << "Register 3: " << std::hex << std::bitset<16>(emulator.GetRegisterValue(3)) << " (DEC: " << std::dec << emulator.GetRegisterValue(3) << ") (HEX: " << std::hex << emulator.GetRegisterValue(3) << ")" << std::endl;
        std::cout << "Register 4: " << std::hex << std::bitset<16>(emulator.GetRegisterValue(4)) << " (DEC: " << std::dec << emulator.GetRegisterValue(4) << ") (HEX: " << std::hex << emulator.GetRegisterValue(4) << ")" << std::endl;
        std::cout << "Register 5: " << std::hex << std::bitset<16>(emulator.GetRegisterValue(5)) << " (DEC: " << std::dec << emulator.GetRegisterValue(5) << ") (HEX: " << std::hex << emulator.GetRegisterValue(5) << ")" << std::endl;
        std::cout << "Register 6: " << std::hex << std::bitset<16>(emulator.GetRegisterValue(6)) << " (DEC: " << std::dec << emulator.GetRegisterValue(6) << ") (HEX: " << std::hex << emulator.GetRegisterValue(6) << ")" << std::endl; 
        std::cout << "Register 7: " << std::hex << std::bitset<16>(emulator.GetRegisterValue(7)) << " (DEC: " << std::dec << emulator.GetRegisterValue(7) << ") (HEX: " << std::hex << emulator.GetRegisterValue(7) << ")" << std::endl << std::endl;

        emulator.Step();
    }
    // Close the file
    registerCFile.close();
    instructionFetchFile.close();
    pcOutFile.close();
    std::cout << "Execution completed." << std::endl;
    return 0;
}