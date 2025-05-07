#include <iostream>
#include "verilated.h"
#include "Vbitty_core.h"
#include <cstdlib>
#include <ctime>
#include <bitset>

#define NUM_TESTS 5

int main(int argc, char** argv)
{
    Verilated::commandArgs(argc, argv);
    Vbitty_core* bitty_core = new Vbitty_core; // Instantiate bitty_core

    bitty_core->reset = 1;
    bitty_core->clk = 0;
    bitty_core->eval();
    bitty_core->clk = 1;
    bitty_core->eval();
    bitty_core->reset = 0;
    bitty_core->run = 1;
    bitty_core->eval();

    // Initialize signals
    std::cout << "Starting bitty_core Test with " << NUM_TESTS << " iterations.\n";

    for (int test = 0; test < NUM_TESTS; test++)
    {
        bitty_core->instruction = rand() & 0xFFFF; // Random instruction
        for (int i = 0; i < 3; i++)
        {
            bitty_core->clk = 0;
            bitty_core->eval();
            bitty_core->clk = 1;
            bitty_core->eval();
            std::cout << "Test " << test + 1 << ": " << std::bitset<1>(bitty_core->done) << "\n";
        }
    }
    delete bitty_core;
    return 0;
}