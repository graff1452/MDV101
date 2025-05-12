#include <iostream>
#include "verilated.h"
#include "Vregister_8.h"
#include <cstdlib>
#include <ctime>

#define NUM_TESTS 1000000 // Number of tests

int main(int argc, char** argv)
{
    Verilated::commandArgs(argc, argv);
    Vregister* myRegister = new Vregister; // Creating register

    std::srand(std::time(nullptr));  // Seed for random values

    uint16_t d_in;
    int reset;
    int clk;
    int en;
    uint16_t d_out;
    for (int test = 0; test < NUM_TESTS; test++)
    {
        d_in = std::rand() & 0xFF;
        reset = std::rand() % 2;
        en = std::rand() % 2;

        myRegister->d_in = d_in; // Ensuring tests only in rising edge of the cloak
        myRegister->reset = reset;
        myRegister->en = en;
        myRegister->clk = 0;
        myRegister->eval();
        myRegister->clk = 1;
        myRegister->eval();
        
        if (reset) {d_out = 0x00;}
        else if (en) {d_out = d_in;}

        if (d_out != myRegister->d_out) // Finding Mismatches
        {
            std::cout << "testN" << test
            <<" Mismatch "
            << " d_in=" << d_in 
            << " reset=" << reset 
            << " clk=" << clk 
            << " en=" << en 
            << " Expected=" << d_out
            << " Got=" << myRegister->d_out
            << std::endl;
        }
    }

    std::cout << "register Testbench completed." << std::endl;
    delete myRegister;
    return 0;
}