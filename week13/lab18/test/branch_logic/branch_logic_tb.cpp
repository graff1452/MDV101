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
    branch_logic->run = 1;
    // Generate random test cases
    for (int test = 0; test < 1; test++) 
    {
        branch_logic->pc_address = std::rand() & 0xFF; // Random PC address
        branch_logic->instruction = std::rand() & 0xFFFF; // Random instruction
        branch_logic-> register_c = std::rand() % 4; // Random register value

        uint8_t expected_pc;
        uint16_t immediate_value = ((branch_logic->instruction) >> 4) & 0x0FFF;
        uint8_t format = ((branch_logic->instruction) & 0b11);
        uint8_t condition = ((branch_logic->instruction) >> 2) & 0b11;

        if (format == 0b10) 
        {
            switch (condition)
            {
                case 0b00:
                if (branch_logic->register_c == 0) 
                {
                    expected_pc = branch_logic->pc_address + immediate_value;
                } 
                else 
                {
                    expected_pc = branch_logic->pc_address + 1;
                }
                break;
                case 0b01:
                if (branch_logic->register_c == 1) 
                {
                    expected_pc = branch_logic->pc_address + immediate_value;
                } 
                else 
                {
                    expected_pc = branch_logic->pc_address + 1;
                }
                break;
                case 0b10:
                if (branch_logic->register_c == 2) 
                {
                    expected_pc = branch_logic->pc_address + immediate_value;
                } 
                else 
                {
                    expected_pc = branch_logic->pc_address + 1;
                }
                break;
                default:
                if (branch_logic->register_c == 0) 
                {
                    expected_pc = branch_logic->pc_address + immediate_value;
                } 
                else 
                {
                    expected_pc = branch_logic->pc_address + 1;
                }
                break;
            }
        }
        else 
        {
            expected_pc = branch_logic->pc_address + 1;
        }

        expected_pc = expected_pc & 0xFF; // Ensure expected_pc is 8 bits

        // std::cout << "Expected PC: " << std::bitset<8>(expected_pc) << std::endl;

        branch_logic->eval();

        if (branch_logic->new_pc != expected_pc)
        {
            std::cerr << "Test failed: " << test << std::endl;
            std::cerr << "expected: " << std::bitset<8>(expected_pc) << std::endl;
            std::cerr << "actual: " << std::bitset<8>(branch_logic->new_pc) << std::endl;
            delete branch_logic;
            return 1;
        }
    }

    std::cout << "All tests passed!" << std::endl;

    delete branch_logic;
    return 0;
}