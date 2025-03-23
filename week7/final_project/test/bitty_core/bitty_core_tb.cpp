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
        
    }

    delete bitty_core;
    return 0;
}