#include <iostream>
#include "verilated.h"
#include "Vbitty_core.h"
#include <cstdlib>
#include <ctime>
#include <bitset>

#define NUM_TESTS 10000

int main(int argc, char** argv)
{
    Verilated::commandArgs(argc, argv);
    Vbitty_core* bitty_core = new Vbitty_core; // Instantiate bitty_core

    std::srand(std::time(nullptr));  // Seed for random values

    // Initialize signals
    std::cout << "Starting bitty_core Test with " << NUM_TESTS << " iterations.\n";

    for (int test = 0; test < NUM_TESTS; test++)
    {
        bitty_core->instruction = std::rand() & 0xFFFF;
        bitty_core->run = 1;
        bitty_core->clk = 0;
        bitty_core->eval();
        bitty_core->clk = 1;
        bitty_core->eval();

        if (bitty_core->Reg_Inst_Out != bitty_core->instruction) 
        {
            std::cout << "CicleN1: intsruction = " << std::bitset<16>(control_unit->instruction) << std::endl
                      << "\tReg_Inst_Out = " << std::bitset<16>(control_unit->Reg_Inst_Out) << ", should be " <<  std::bitset<16>(control_unit->instruction) << std::endl;
        }

        bitty_core->clk = 0;
        bitty_core->eval();
        bitty_core->clk = 1;
        bitty_core->eval();

        switch(((bitty_core->instruction) >> 13) & 0b111) 
        {
            case 0b000: if (bitty_core->Reg_S_Out != bitty_core->Reg_0_Out) 
            {
                std::cout << "CicleN2: intsruction = " << std::bitset<16>(control_unit->instruction) << std::endl
                          << "\tReg_S_Out = " << std::bitset<16>(control_unit->Reg_S_Out) << ", should be " <<  std::bitset<16>(control_unit->Reg_0_Out) << std::endl;
            }
            break;

            case 0b001: if (bitty_core->Reg_S_Out != bitty_core->Reg_1_Out) 
            {
                std::cout << "CicleN2: intsruction = " << std::bitset<16>(control_unit->instruction) << std::endl
                          << "\tReg_S_Out = " << std::bitset<16>(control_unit->Reg_S_Out) << ", should be " <<  std::bitset<16>(control_unit->Reg_1_Out) << std::endl;
            }
            break;

            case 0b010: if (bitty_core->Reg_S_Out != bitty_core->Reg_2_Out) 
            {
                std::cout << "CicleN2: intsruction = " << std::bitset<16>(control_unit->instruction) << std::endl
                          << "\tReg_S_Out = " << std::bitset<16>(control_unit->Reg_S_Out) << ", should be " <<  std::bitset<16>(control_unit->Reg_2_Out) << std::endl;
            }
            break;

            case 0b011: if (bitty_core->Reg_S_Out != bitty_core->Reg_3_Out) 
            {
                std::cout << "CicleN2: intsruction = " << std::bitset<16>(control_unit->instruction) << std::endl
                          << "\tReg_S_Out = " << std::bitset<16>(control_unit->Reg_S_Out) << ", should be " <<  std::bitset<16>(control_unit->Reg_3_Out) << std::endl;
            }
            break;

            case 0b100: if (bitty_core->Reg_S_Out != bitty_core->Reg_4_Out) 
            {
                std::cout << "CicleN2: intsruction = " << std::bitset<16>(control_unit->instruction) << std::endl
                          << "\tReg_S_Out = " << std::bitset<16>(control_unit->Reg_S_Out) << ", should be " <<  std::bitset<16>(control_unit->Reg_4_Out) << std::endl;
            }
            break;

            case 0b101: if (bitty_core->Reg_S_Out != bitty_core->Reg_5_Out) 
            {
                std::cout << "CicleN2: intsruction = " << std::bitset<16>(control_unit->instruction) << std::endl
                          << "\tReg_S_Out = " << std::bitset<16>(control_unit->Reg_S_Out) << ", should be " <<  std::bitset<16>(control_unit->Reg_5_Out) << std::endl;
            }
            break;

            case 0b110: if (bitty_core->Reg_S_Out != bitty_core->Reg_6_Out) 
            {
                std::cout << "CicleN2: intsruction = " << std::bitset<16>(control_unit->instruction) << std::endl
                          << "\tReg_S_Out = " << std::bitset<16>(control_unit->Reg_S_Out) << ", should be " <<  std::bitset<16>(control_unit->Reg_6_Out) << std::endl;
            }
            break;

            case 0b111: if (bitty_core->Reg_S_Out != bitty_core->Reg_7_Out) 
            {
                std::cout << "CicleN2: intsruction = " << std::bitset<16>(control_unit->instruction) << std::endl
                          << "\tReg_S_Out = " << std::bitset<16>(control_unit->Reg_S_Out) << ", should be " <<  std::bitset<16>(control_unit->Reg_7_Out) << std::endl;
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
        // Testing CicleN3, ALU
        if ((((bitty_core->instruction) << 13) >> 15) & 0b1 == 0) 
        {

        }
    }

    delete bitty_core;
    return 0;
}