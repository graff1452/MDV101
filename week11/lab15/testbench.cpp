#include <verilated.h>
#include "Vcounter.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

#define NUM_TESTS 5

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);
    Vcounter* counter = new Vcounter;  // Instantiate the counter module

    std::srand(std::time(nullptr));  // Seed for random values

    for (int test = 0; test < NUM_TESTS; test++) 
    {
        counter->reset = 1;  // Assert reset
        counter->eval();  // Evaluate the design
        counter->reset = 0;  // Deassert reset
        counter->eval();  // Evaluate the design
        int clock_cycles = 9;  // Random number of clock cycles

        for (int i = 0; i < clock_cycles; i++) 
        {
            counter->clk = 0;
            counter->eval();
            counter->clk = 1;
            counter->eval();
        }
    }

    std::cout << "Counter Testbench completed." << std::endl;
    delete counter;
    return 0;
}