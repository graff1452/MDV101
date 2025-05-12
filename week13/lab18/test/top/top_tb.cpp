#include <iostream>
#include "verilated.h"
#include "Vtop.h"
#include <cstdlib>
#include <ctime>
#include <bitset>

#define NUM_TESTS 256 // Number of tests

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);
    Vtop *top = new Vtop; // Creating top module

    // Start the test
    top->reset = 0; // Enable the run signal
    top->eval();
    top->reset = 1;
    top->eval();
    top->reset = 0; // Enable the run signal
    top->eval();

    std::cout << "At reset: " << std::bitset<16>(top->top_out) << std::endl;

    for (int test = 0; test < NUM_TESTS; test++) 
    {
        for (int i = 0; i < 6; i++)
        {
            top->clk = 0;
            top->eval();
            top->clk = 1;
            top->eval();
        }
        std::cout << "Test#" << test << ", instruction: " << std::bitset<16>(top->top_out) << std::endl;
    }

    std::cout << "Top Testbench completed." << std::endl;
    delete top;
    return 0;
}