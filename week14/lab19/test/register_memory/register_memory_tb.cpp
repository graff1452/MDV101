#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "verilated.h"
#include "Vregister_memory.h"
#include <cstdlib>
#include <cstdint>
#include <ctime>
#include <bitset>

#define NUM_TESTS 256 // Number of tests

int main(int argc, char** argv)
{
    Verilated::commandArgs(argc, argv);
    Vregister_memory* myMemory = new Vregister_memory; // Creating memory
    std::srand(std::time(nullptr));


    


    myMemory->run = 1;
    myMemory->instruction = std::rand() & 0xFFFF;
    myMemory->Reg_0 = std::rand() & 0xFFFF;
    myMemory->Reg_1 = std::rand() & 0xFFFF;
    myMemory->Reg_2 = std::rand() & 0xFFFF;
    myMemory->Reg_3 = std::rand() & 0xFFFF;
    myMemory->Reg_4 = std::rand() & 0xFFFF;
    myMemory->Reg_5 = std::rand() & 0xFFFF;
    myMemory->Reg_6 = std::rand() & 0xFFFF;
    myMemory->Reg_7 = std::rand() & 0xFFFF;


    for (int test = 0; test < NUM_TESTS; test++)
    {
        while (true) 
        {
            myMemory->instruction = std::rand() & 0xFFFF;
            if (myMemory->instruction & 0b11 == 0b11)
            {
                break;
            }
        }
        myMemory->Reg_0 = std::rand() & 0xFFFF;
        myMemory->Reg_1 = std::rand() & 0xFFFF;
        myMemory->Reg_2 = std::rand() & 0xFFFF;
        myMemory->Reg_3 = std::rand() & 0xFFFF;
        myMemory->Reg_4 = std::rand() & 0xFFFF;
        myMemory->Reg_5 = std::rand() & 0xFFFF;
        myMemory->Reg_6 = std::rand() & 0xFFFF;
        myMemory->Reg_7 = std::rand() & 0xFFFF;
        myMemory->clk = 0;
        myMemory->eval();

        std::cout   << "Test#" << test << std::endl
                    << "########" << std::endl
                    << "#BEFORE#" << std::endl
                    << "########" << std::endl
                    << "instruction: " << std::bitset<16>(myMemory->instruction) << std::endl
                    << "Operation: ";
                    if (((myMemory->instruction >> 2) & 0b1) == 0b0) {std::cout << "LOAD" << std::endl;} else {std::cout << "STORE" << std::endl;}
        std::cout   << "Rx_number = " << std::dec << ((myMemory->instruction >> 13) & 0b111) << std::endl;
        std::cout   << "Ry_number = " << std::dec << ((myMemory->instruction >> 10) & 0b111) << std::endl;
        std::cout   << "Reg_0: " << std::bitset<16>(myMemory->Reg_0) << " (DEC: " << std::dec << myMemory->Reg_0 << ")" <<  std::endl
                    << "Reg_1: " << std::bitset<16>(myMemory->Reg_1) << " (DEC: " << std::dec << myMemory->Reg_1 << ")" <<  std::endl
                    << "Reg_2: " << std::bitset<16>(myMemory->Reg_2) << " (DEC: " << std::dec << myMemory->Reg_2 << ")" <<  std::endl
                    << "Reg_3: " << std::bitset<16>(myMemory->Reg_3) << " (DEC: " << std::dec << myMemory->Reg_3 << ")" <<  std::endl
                    << "Reg_4: " << std::bitset<16>(myMemory->Reg_4) << " (DEC: " << std::dec << myMemory->Reg_4 << ")" <<  std::endl
                    << "Reg_5: " << std::bitset<16>(myMemory->Reg_5) << " (DEC: " << std::dec << myMemory->Reg_5 << ")" <<  std::endl
                    << "Reg_6: " << std::bitset<16>(myMemory->Reg_6) << " (DEC: " << std::dec << myMemory->Reg_6 << ")" <<  std::endl
                    << "Reg_7: " << std::bitset<16>(myMemory->Reg_7) << " (DEC: " << std::dec << myMemory->Reg_7 << ")" <<  std::endl
                    << "Reg_0_Out: " << std::bitset<16>(myMemory->Reg_0_Out) << " (DEC: " << std::dec << myMemory->Reg_0_Out << ")" <<  std::endl
                    << "Reg_1_Out: " << std::bitset<16>(myMemory->Reg_1_Out) << " (DEC: " << std::dec << myMemory->Reg_1_Out << ")" <<  std::endl
                    << "Reg_2_Out: " << std::bitset<16>(myMemory->Reg_2_Out) << " (DEC: " << std::dec << myMemory->Reg_2_Out << ")" <<  std::endl
                    << "Reg_3_Out: " << std::bitset<16>(myMemory->Reg_3_Out) << " (DEC: " << std::dec << myMemory->Reg_3_Out << ")" <<  std::endl
                    << "Reg_4_Out: " << std::bitset<16>(myMemory->Reg_4_Out) << " (DEC: " << std::dec << myMemory->Reg_4_Out << ")" <<  std::endl
                    << "Reg_5_Out: " << std::bitset<16>(myMemory->Reg_5_Out) << " (DEC: " << std::dec << myMemory->Reg_5_Out << ")" <<  std::endl
                    << "Reg_6_Out: " << std::bitset<16>(myMemory->Reg_6_Out) << " (DEC: " << std::dec << myMemory->Reg_6_Out << ")" <<  std::endl
                    << "Reg_7_Out: " << std::bitset<16>(myMemory->Reg_7_Out) << " (DEC: " << std::dec << myMemory->Reg_7_Out << ")" <<  std::endl
                    << "out: " << std::bitset<16>(myMemory->out) << " (DEC: " << std::dec << myMemory->out << ")" <<  std::endl;
        myMemory->clk = 1;
        myMemory->eval();
        std::cout   << "Test#" << test << std::endl
                    << "#######" << std::endl
                    << "#AFTER#" << std::endl
                    << "#######" << std::endl
                    << "Reg_0: " << std::bitset<16>(myMemory->Reg_0) << " (DEC: " << std::dec << myMemory->Reg_0 << ")" <<  std::endl
                    << "Reg_1: " << std::bitset<16>(myMemory->Reg_1) << " (DEC: " << std::dec << myMemory->Reg_1 << ")" <<  std::endl
                    << "Reg_2: " << std::bitset<16>(myMemory->Reg_2) << " (DEC: " << std::dec << myMemory->Reg_2 << ")" <<  std::endl
                    << "Reg_3: " << std::bitset<16>(myMemory->Reg_3) << " (DEC: " << std::dec << myMemory->Reg_3 << ")" <<  std::endl
                    << "Reg_4: " << std::bitset<16>(myMemory->Reg_4) << " (DEC: " << std::dec << myMemory->Reg_4 << ")" <<  std::endl
                    << "Reg_5: " << std::bitset<16>(myMemory->Reg_5) << " (DEC: " << std::dec << myMemory->Reg_5 << ")" <<  std::endl
                    << "Reg_6: " << std::bitset<16>(myMemory->Reg_6) << " (DEC: " << std::dec << myMemory->Reg_6 << ")" <<  std::endl
                    << "Reg_7: " << std::bitset<16>(myMemory->Reg_7) << " (DEC: " << std::dec << myMemory->Reg_7 << ")" <<  std::endl
                    << "Reg_0_Out: " << std::bitset<16>(myMemory->Reg_0_Out) << " (DEC: " << std::dec << myMemory->Reg_0_Out << ")" <<  std::endl
                    << "Reg_1_Out: " << std::bitset<16>(myMemory->Reg_1_Out) << " (DEC: " << std::dec << myMemory->Reg_1_Out << ")" <<  std::endl
                    << "Reg_2_Out: " << std::bitset<16>(myMemory->Reg_2_Out) << " (DEC: " << std::dec << myMemory->Reg_2_Out << ")" <<  std::endl
                    << "Reg_3_Out: " << std::bitset<16>(myMemory->Reg_3_Out) << " (DEC: " << std::dec << myMemory->Reg_3_Out << ")" <<  std::endl
                    << "Reg_4_Out: " << std::bitset<16>(myMemory->Reg_4_Out) << " (DEC: " << std::dec << myMemory->Reg_4_Out << ")" <<  std::endl
                    << "Reg_5_Out: " << std::bitset<16>(myMemory->Reg_5_Out) << " (DEC: " << std::dec << myMemory->Reg_5_Out << ")" <<  std::endl
                    << "Reg_6_Out: " << std::bitset<16>(myMemory->Reg_6_Out) << " (DEC: " << std::dec << myMemory->Reg_6_Out << ")" <<  std::endl
                    << "Reg_7_Out: " << std::bitset<16>(myMemory->Reg_7_Out) << " (DEC: " << std::dec << myMemory->Reg_7_Out << ")" <<  std::endl
                    << "out: " << std::bitset<16>(myMemory->out) << " (DEC: " << std::dec << myMemory->out << ")" <<  std::endl;
    }       

    std::cout << "Register Memory Testbench completed." << std::endl;
    delete myMemory;
    return 0;
}