#include <iostream>
#include "verilated.h"
#include "Vbitty_core.h"
#include <cstdlib>
#include <ctime>
#include <bitset>


#define NUM_TESTS 10

int main(int argc, char** argv)
{
    Verilated::commandArgs(argc, argv);
    Vbitty_core* bitty_core = new Vbitty_core; // Instantiate bitty_core

    std::srand(std::time(nullptr));  // Seed for random values

    // Initialize signals
    std::cout << "Starting bitty_core Test with " << NUM_TESTS << " iterations.\n";

    for (int test = 0; test < NUM_TESTS; test++)
    {
        bitty_core->instruction = rand() & 0xFFFF; // Generate a random 16-bit instruction
        uint16_t Rx = ((bitty_core->instruction) >> 13) & 0b111;
        uint16_t Ry = ((bitty_core->instruction << 3) >> 13) & 0b111;
        uint16_t ALU_sel = (((bitty_core->instruction) << 11) >> 13) & 0b111;
        
        bitty_core->reset = 1;
        bitty_core->clk = 0;
        bitty_core->eval();
        bitty_core->clk = 1;
        bitty_core->eval();

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
    }

    delete bitty_core;
    return 0;
}