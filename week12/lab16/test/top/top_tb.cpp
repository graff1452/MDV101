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
    top->run = 1; // Enable the run signal

    bool flag = true; // Flag to control the first test

    for (int test = 0; test < NUM_TESTS; test++) {
        // Toggle clock
        for (int j = 0; j < 4; j++) {
            if (test == 0 && flag) {
                flag = false;
                continue;
            }
            top->clk = 0; // Set clock to 0
            top->eval();
            top->clk = 1; // Set clock to 1
            top->eval();
        }

        if (top->done != 1) {
            std::cerr << "Error: Done signal not asserted as expected at test " << test << std::endl;
        }
    }

    std::cout << "Top Testbench completed." << std::endl;
    delete top;
    return 0;
}