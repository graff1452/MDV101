#include <iostream>
#include "verilated.h"
#include "Vbranch_logic.h"
#include <bitset>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>

#define NUM_TESTS 1000000

int main(int argc, char **argv) 
{
    Verilated::commandArgs(argc, argv);
    Vbranch_logic* branch_logic = new Vbranch_logic;

    std::srand(static_cast<unsigned int>(std::time(0))); // Seed for random number generation
    // Generate random test cases
    for (int test = 0; test < 1; test++) 
    {
        branch_logic->pc_address = 0b00000011;
        branch_logic->instruction = 0b1000010100101110; 
        branch_logic-> register_c = 0; 
        branch_logic->bitty_core_done1 = 1;

        branch_logic->clk = 0;
        branch_logic->eval();
        branch_logic->clk = 1;
        branch_logic->eval();

        std::cout << std::bitset<8>(branch_logic->new_pc) << "(DEC: " << (int)branch_logic->new_pc << ") " << std::endl;

        branch_logic->reset = 1;
        branch_logic->clk = 0;
        branch_logic->eval();
        branch_logic->clk = 1;
        branch_logic->eval();
        branch_logic->reset = 0; // Deassert reset
        if (branch_logic->new_pc != 0) 
        {
            std::cerr << "Error: new_pc should be 0 after reset, but got " << std::bitset<8>(branch_logic->new_pc) << std::endl;
            return 1;
        }
    }

    std::cout << "All tests passed!" << std::endl;

    delete branch_logic;
    return 0;
}