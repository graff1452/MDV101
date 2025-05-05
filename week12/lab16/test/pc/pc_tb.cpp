#include <iostream>
#include "verilated.h"
#include "Vpc.h"
#include <cstdlib>
#include <bitset>

#define NUM_TESTS 256 // Number of tests

int main(int argc, char** argv)
{
    Verilated::commandArgs(argc, argv);
    Vpc* myPc = new Vpc; // Creating PC

    myPc->clk = 0; // Initialize clock
    myPc->reset = 1; // Assert reset
    myPc->eval(); // Evaluate the design
    myPc->reset = 0; // Deassert reset
    myPc->en_pc = 1; // Enable the PC
    myPc->eval(); // Evaluate the design again

    if (myPc->d_out != 0)
    {
        std::cerr << "Error: PC should be 0 after reset, but got " << myPc->d_out << std::endl;
        return 1;
    }

    for (int test = 0; test < NUM_TESTS; test++)
    {
        myPc->clk = 0;
        myPc->d_in = test;
        myPc->eval(); // Evaluate the design
        myPc->clk = 1; // Toggle clock
        myPc->eval(); // Evaluate the design

        if (myPc->d_out != test)
        {
            std::cerr << "Error: PC should be " << std::bitset<8>(test) << ", but got " << std::bitset<8>(myPc->d_out) << std::endl;
            return 1;
        }
        else
        {
            std::cout << "Test " << test << " passed!" << std::endl;
        }
    }
    delete myPc; // Clean up
    std::cout << "All tests passed!" << std::endl;
    return 0;
}