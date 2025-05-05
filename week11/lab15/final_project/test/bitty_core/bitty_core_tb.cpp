#include <iostream>
#include "verilated.h"
#include "Vbitty_core.h"
#include <cstdlib>
#include <ctime>
#include <bitset>

#include "/home/zhan/Desktop/MDV101/week11/lab15/emulator/bitty_emu.h"
#include "/home/zhan/Desktop/MDV101/week11/lab15/generator/bitty_generator.h"

#define NUM_TESTS 100

int main(int argc, char** argv)
{
    BittyEmulator emulator = BittyEmulator();
    BittyInstructionGenerator generator = BittyInstructionGenerator();

    Verilated::commandArgs(argc, argv);
    Vbitty_core* bitty_core = new Vbitty_core; // Instantiate bitty_core

    std::srand(std::time(nullptr));  // Seed for random values

    bitty_core->reset = 1;
    bitty_core->clk = 0;
    bitty_core->eval();
    bitty_core->clk = 1;
    bitty_core->eval();

    std::cout << "#######\n"
              << "#START#\n"
              << "#######\n";

    // Initialize signals
    std::cout << "Starting bitty_core Test with " << NUM_TESTS << " iterations.\n";

    for (int test = 0; test < NUM_TESTS; test++)
    {
        bitty_core->instruction = std::rand() & 0xFFFF; // Generate a random 16-bit instruction

        // std::cout << "##########\n"
        //           << "#TEST " << test << "#\n"
        //           << "##########\n";

        // std::cout << "########\n"
        //           << "#BEFORE#\n"
        //           << "########\n";
        // std::cout << "BittyCore_Reg_" << 0 << " = " << std::bitset<16>(bitty_core->Reg_0_Out) << std::endl;
        // std::cout << "BittyCore_Reg_" << 1 << " = " << std::bitset<16>(bitty_core->Reg_1_Out) << std::endl;
        // std::cout << "BittyCore_Reg_" << 2 << " = " << std::bitset<16>(bitty_core->Reg_2_Out) << std::endl;
        // std::cout << "BittyCore_Reg_" << 3 << " = " << std::bitset<16>(bitty_core->Reg_3_Out) << std::endl;
        // std::cout << "BittyCore_Reg_" << 4 << " = " << std::bitset<16>(bitty_core->Reg_4_Out) << std::endl;
        // std::cout << "BittyCore_Reg_" << 5 << " = " << std::bitset<16>(bitty_core->Reg_5_Out) << std::endl;
        // std::cout << "BittyCore_Reg_" << 6 << " = " << std::bitset<16>(bitty_core->Reg_6_Out) << std::endl;
        // std::cout << "BittyCore_Reg_" << 7 << " = " << std::bitset<16>(bitty_core->Reg_7_Out) << std::endl << std::endl;
        // std::cout << "Emu_Reg_" << 0 << " = " << std::bitset<16>(emulator.GetRegisterValue(0)) << std::endl;
        // std::cout << "Emu_Reg_" << 1 << " = " << std::bitset<16>(emulator.GetRegisterValue(1)) << std::endl;
        // std::cout << "Emu_Reg_" << 2 << " = " << std::bitset<16>(emulator.GetRegisterValue(2)) << std::endl;
        // std::cout << "Emu_Reg_" << 3 << " = " << std::bitset<16>(emulator.GetRegisterValue(3)) << std::endl;
        // std::cout << "Emu_Reg_" << 4 << " = " << std::bitset<16>(emulator.GetRegisterValue(4)) << std::endl;
        // std::cout << "Emu_Reg_" << 5 << " = " << std::bitset<16>(emulator.GetRegisterValue(5)) << std::endl;
        // std::cout << "Emu_Reg_" << 6 << " = " << std::bitset<16>(emulator.GetRegisterValue(6)) << std::endl;
        // std::cout << "Emu_Reg_" << 7 << " = " << std::bitset<16>(emulator.GetRegisterValue(7)) << std::endl << std::endl;

        emulator.Evaluate(bitty_core->instruction); // For comparison

        uint16_t Rx = ((bitty_core->instruction) >> 13) & 0b111;
        uint16_t Ry = ((bitty_core->instruction << 3) >> 13) & 0b111;
        uint16_t ALU_sel = (((bitty_core->instruction) << 11) >> 13) & 0b111;

        bitty_core->reset = 0;
        bitty_core->run = 1;
        bitty_core->clk = 0;
        bitty_core->eval();
        bitty_core->clk = 1;
        bitty_core->eval();

        if (bitty_core->Reg_Inst_Out != bitty_core->instruction) 
        {
            std::cout << "CicleN1: intsruction = " << std::bitset<16>(bitty_core->instruction) << std::endl
                      << "\tReg_Inst_Out = " << std::bitset<16>(bitty_core->Reg_Inst_Out) << ", should be " <<  std::bitset<16>(bitty_core->instruction) << std::endl;
        }

        bitty_core->clk = 0;
        bitty_core->eval();
        bitty_core->clk = 1;
        bitty_core->eval();

        switch(Rx) 
        {
            case 0b000: if (bitty_core->Reg_S_Out != bitty_core->Reg_0_Out) 
            {
                std::cout << "CicleN2: intsruction = " << std::bitset<16>(bitty_core->instruction) << std::endl
                          << "\tReg_S_Out = " << std::bitset<16>(bitty_core->Reg_S_Out) << ", should be " <<  std::bitset<16>(bitty_core->Reg_0_Out) << std::endl;
            }
            break;

            case 0b001: if (bitty_core->Reg_S_Out != bitty_core->Reg_1_Out) 
            {
                std::cout << "CicleN2: intsruction = " << std::bitset<16>(bitty_core->instruction) << std::endl
                          << "\tReg_S_Out = " << std::bitset<16>(bitty_core->Reg_S_Out) << ", should be " <<  std::bitset<16>(bitty_core->Reg_1_Out) << std::endl;
            }
            break;

            case 0b010: if (bitty_core->Reg_S_Out != bitty_core->Reg_2_Out) 
            {
                std::cout << "CicleN2: intsruction = " << std::bitset<16>(bitty_core->instruction) << std::endl
                          << "\tReg_S_Out = " << std::bitset<16>(bitty_core->Reg_S_Out) << ", should be " <<  std::bitset<16>(bitty_core->Reg_2_Out) << std::endl;
            }
            break;

            case 0b011: if (bitty_core->Reg_S_Out != bitty_core->Reg_3_Out) 
            {
                std::cout << "CicleN2: intsruction = " << std::bitset<16>(bitty_core->instruction) << std::endl
                          << "\tReg_S_Out = " << std::bitset<16>(bitty_core->Reg_S_Out) << ", should be " <<  std::bitset<16>(bitty_core->Reg_3_Out) << std::endl;
            }
            break;

            case 0b100: if (bitty_core->Reg_S_Out != bitty_core->Reg_4_Out) 
            {
                std::cout << "CicleN2: intsruction = " << std::bitset<16>(bitty_core->instruction) << std::endl
                          << "\tReg_S_Out = " << std::bitset<16>(bitty_core->Reg_S_Out) << ", should be " <<  std::bitset<16>(bitty_core->Reg_4_Out) << std::endl;
            }
            break;

            case 0b101: if (bitty_core->Reg_S_Out != bitty_core->Reg_5_Out) 
            {
                std::cout << "CicleN2: intsruction = " << std::bitset<16>(bitty_core->instruction) << std::endl
                          << "\tReg_S_Out = " << std::bitset<16>(bitty_core->Reg_S_Out) << ", should be " <<  std::bitset<16>(bitty_core->Reg_5_Out) << std::endl;
            }
            break;

            case 0b110: if (bitty_core->Reg_S_Out != bitty_core->Reg_6_Out) 
            {
                std::cout << "CicleN2: intsruction = " << std::bitset<16>(bitty_core->instruction) << std::endl
                          << "\tReg_S_Out = " << std::bitset<16>(bitty_core->Reg_S_Out) << ", should be " <<  std::bitset<16>(bitty_core->Reg_6_Out) << std::endl;
            }
            break;

            case 0b111: if (bitty_core->Reg_S_Out != bitty_core->Reg_7_Out) 
            {
                std::cout << "CicleN2: intsruction = " << std::bitset<16>(bitty_core->instruction) << std::endl
                          << "\tReg_S_Out = " << std::bitset<16>(bitty_core->Reg_S_Out) << ", should be " <<  std::bitset<16>(bitty_core->Reg_7_Out) << std::endl;
            }
            break;

            default: 
                std::cout << "Something went off testing cycle 2" << std::endl;
                break;
        }

        bitty_core->clk = 0;
        bitty_core->eval();
        bitty_core->clk = 1;
        bitty_core->eval();
    
        bitty_core->clk = 0;
        bitty_core->eval();
        bitty_core->clk = 1;
        bitty_core->eval();
    
        switch(Rx) 
        {
            case 0b000:
            if (bitty_core->Reg_0_Out != bitty_core->Reg_C_Out) 
            {
                std::cout << test << "CicleN4: intsruction = " << std::bitset<16>(bitty_core->instruction) << std::endl
                << "\tReg_0_Out = " << std::bitset<16>(bitty_core->Reg_0_Out) << ", should be " <<  std::bitset<16>(bitty_core->Reg_C_Out) << std::endl;
            }
            break;
    
            case 0b001:
            if (bitty_core->Reg_1_Out != bitty_core->Reg_C_Out) 
            {
                std::cout << test<< "CicleN4: intsruction = " << std::bitset<16>(bitty_core->instruction) << std::endl
                << "\tReg_1_Out = " << std::bitset<16>(bitty_core->Reg_1_Out) << ", should be " <<  std::bitset<16>(bitty_core->Reg_C_Out) << std::endl;
            }
            break;
    
            case 0b010:
            if (bitty_core->Reg_2_Out != bitty_core->Reg_C_Out) 
            {
                std::cout << test<< "CicleN4: intsruction = " << std::bitset<16>(bitty_core->instruction) << std::endl
                << "\tReg_2_Out = " << std::bitset<16>(bitty_core->Reg_2_Out) << ", should be " <<  std::bitset<16>(bitty_core->Reg_C_Out) << std::endl;
            }
            break;
    
            case 0b011:
            if (bitty_core->Reg_3_Out != bitty_core->Reg_C_Out) 
            {
                std::cout << test<< "CicleN4: intsruction = " << std::bitset<16>(bitty_core->instruction) << std::endl
                << "\tReg_3_Out = " << std::bitset<16>(bitty_core->Reg_3_Out) << ", should be " <<  std::bitset<16>(bitty_core->Reg_C_Out) << std::endl;
            }
            break;
    
            case 0b100:
            if (bitty_core->Reg_4_Out != bitty_core->Reg_C_Out) 
            {
                std::cout << test<< "CicleN4: intsruction = " << std::bitset<16>(bitty_core->instruction) << std::endl
                << "\tReg_4_Out = " << std::bitset<16>(bitty_core->Reg_4_Out) << ", should be " <<  std::bitset<16>(bitty_core->Reg_C_Out) << std::endl;
            }
            break;
    
            case 0b101:
            if (bitty_core->Reg_5_Out != bitty_core->Reg_C_Out) 
            {
                std::cout << test<< "CicleN4: intsruction = " << std::bitset<16>(bitty_core->instruction) << std::endl
                << "\tReg_5_Out = " << std::bitset<16>(bitty_core->Reg_5_Out) << ", should be " <<  std::bitset<16>(bitty_core->Reg_C_Out) << std::endl;
            }
            break;
    
            case 0b110:
            if (bitty_core->Reg_6_Out != bitty_core->Reg_C_Out) 
            {
                std::cout << test<< "CicleN4: intsruction = " << std::bitset<16>(bitty_core->instruction) << std::endl
                << "\tReg_6_Out = " << std::bitset<16>(bitty_core->Reg_6_Out) << ", should be " <<  std::bitset<16>(bitty_core->Reg_C_Out) << std::endl;
            }
            break;
    
            case 0b111:
            if (bitty_core->Reg_7_Out != bitty_core->Reg_C_Out) 
            {
                std::cout << test<< "CicleN4: intsruction = " << std::bitset<16>(bitty_core->instruction) << std::endl
                << "\tReg_7_Out = " << std::bitset<16>(bitty_core->Reg_7_Out) << ", should be " <<  std::bitset<16>(bitty_core->Reg_C_Out) << std::endl;
            }
            break;
    
            default: 
            std::cout << "Something went off testing cycle 4" << std::endl;
            break;
        }

        // std::cout << "########\n"
        //           << "#AFTER#\n"
        //           << "########\n";
        // std::cout << "BittyCore_Reg_" << 0 << " = " << std::bitset<16>(bitty_core->Reg_0_Out) << std::endl;
        // std::cout << "BittyCore_Reg_" << 1 << " = " << std::bitset<16>(bitty_core->Reg_1_Out) << std::endl;
        // std::cout << "BittyCore_Reg_" << 2 << " = " << std::bitset<16>(bitty_core->Reg_2_Out) << std::endl;
        // std::cout << "BittyCore_Reg_" << 3 << " = " << std::bitset<16>(bitty_core->Reg_3_Out) << std::endl;
        // std::cout << "BittyCore_Reg_" << 4 << " = " << std::bitset<16>(bitty_core->Reg_4_Out) << std::endl;
        // std::cout << "BittyCore_Reg_" << 5 << " = " << std::bitset<16>(bitty_core->Reg_5_Out) << std::endl;
        // std::cout << "BittyCore_Reg_" << 6 << " = " << std::bitset<16>(bitty_core->Reg_6_Out) << std::endl;
        // std::cout << "BittyCore_Reg_" << 7 << " = " << std::bitset<16>(bitty_core->Reg_7_Out) << std::endl << std::endl;
        // std::cout << "Emu_Reg_" << 0 << " = " << std::bitset<16>(emulator.GetRegisterValue(0)) << std::endl;
        // std::cout << "Emu_Reg_" << 1 << " = " << std::bitset<16>(emulator.GetRegisterValue(1)) << std::endl;
        // std::cout << "Emu_Reg_" << 2 << " = " << std::bitset<16>(emulator.GetRegisterValue(2)) << std::endl;
        // std::cout << "Emu_Reg_" << 3 << " = " << std::bitset<16>(emulator.GetRegisterValue(3)) << std::endl;
        // std::cout << "Emu_Reg_" << 4 << " = " << std::bitset<16>(emulator.GetRegisterValue(4)) << std::endl;
        // std::cout << "Emu_Reg_" << 5 << " = " << std::bitset<16>(emulator.GetRegisterValue(5)) << std::endl;
        // std::cout << "Emu_Reg_" << 6 << " = " << std::bitset<16>(emulator.GetRegisterValue(6)) << std::endl;
        // std::cout << "Emu_Reg_" << 7 << " = " << std::bitset<16>(emulator.GetRegisterValue(7)) << std::endl << std::endl;

        // std::cout << "intsruction = " << std::bitset<16>(bitty_core->instruction) << std::endl;

        // std::cout << "Format = ";
        // if (((bitty_core->instruction) & 0b11) == 0b01) 
        // {
        //     std::cout << "I-type" << std::endl;
        // } 
        // else 
        // {
        //     std::cout << "R-type" << std::endl;
        // }

        // std::cout << "Operation = ";
        // switch (ALU_sel)
        // {
        //     case 0b000: std::cout << "ADD"; break;
        //     case 0b001: std::cout << "SUB"; break;
        //     case 0b010: std::cout << "AND"; break;
        //     case 0b011: std::cout << "OR"; break;
        //     case 0b100: std::cout << "XOR"; break;
        //     case 0b101: std::cout << "SHL"; break;
        //     case 0b110: std::cout << "SHR"; break;
        //     case 0b111: std::cout << "CONDITION"; break;
        //     default: std::cout << "Unknown operation"; break;
        // }
        // std::cout << std::endl;

        // std::cout << "Rx = ";
        // switch (Rx)
        // {
        //     case 0b000: std::cout << "Reg_0"; break;
        //     case 0b001: std::cout << "Reg_1"; break;
        //     case 0b010: std::cout << "Reg_2"; break;
        //     case 0b011: std::cout << "Reg_3"; break;
        //     case 0b100: std::cout << "Reg_4"; break;
        //     case 0b101: std::cout << "Reg_5"; break;
        //     case 0b110: std::cout << "Reg_6"; break;
        //     case 0b111: std::cout << "Reg_7"; break;
        //     default: std::cout << "Unknown register"; break;
        // }
        // std::cout << std::endl;

        // std::cout << "Ry = ";
        // switch (Ry)
        // {
        //     case 0b000: std::cout << "Reg_0"; break;
        //     case 0b001: std::cout << "Reg_1"; break;
        //     case 0b010: std::cout << "Reg_2"; break;
        //     case 0b011: std::cout << "Reg_3"; break;
        //     case 0b100: std::cout << "Reg_4"; break;
        //     case 0b101: std::cout << "Reg_5"; break;
        //     case 0b110: std::cout << "Reg_6"; break;
        //     case 0b111: std::cout << "Reg_7"; break;
        //     default: std::cout << "Unknown register"; break;
        // }
        // std::cout << std::endl;

        if (bitty_core->Reg_0_Out != emulator.GetRegisterValue(0) ||
            bitty_core->Reg_1_Out != emulator.GetRegisterValue(1) ||
            bitty_core->Reg_2_Out != emulator.GetRegisterValue(2) ||
            bitty_core->Reg_3_Out != emulator.GetRegisterValue(3) ||
            bitty_core->Reg_4_Out != emulator.GetRegisterValue(4) ||
            bitty_core->Reg_5_Out != emulator.GetRegisterValue(5) ||
            bitty_core->Reg_6_Out != emulator.GetRegisterValue(6) ||
            bitty_core->Reg_7_Out != emulator.GetRegisterValue(7))
        {
            std::cout << "Test " << test << " failed!" << std::endl;
        }
        else
        {
            std::cout << "Test " << test << " passed!" << std::endl;
        }
    }

    delete bitty_core;
    return 0;
}