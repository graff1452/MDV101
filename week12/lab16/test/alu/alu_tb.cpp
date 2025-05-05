#include <verilated.h>
#include "Valu.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdint>

#define NUM_TESTS 1000000

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);
    Valu* alu = new Valu;  // Instantiate the ALU module

    std::srand(std::time(nullptr));  // Seed for random values

    for (int sel = 0; sel < 8; sel++) // Loop through all Sel values 
    {
        for (int test = 0; test < NUM_TESTS; test++) 
        {
            uint16_t A = std::rand() & 0xFFFF;  // Generate random 16-bit A
            uint16_t B = std::rand() & 0xFFFF;  // Generate random 16-bit B

            // Apply inputs
            alu->A = A;
            alu->B = B;
            alu->Sel = sel;

            alu->eval();

            uint16_t expected_result;  // Variable for expected result

            switch (sel) 
            {
                case 0b000: expected_result = A + B; break;
                case 0b001: expected_result = A - B; break;
                case 0b010: expected_result = A & B; break;
                case 0b011: expected_result = A | B; break;
                case 0b100: expected_result = A ^ B; break;
                case 0b101: expected_result = A << B % 16; break;
                case 0b110: expected_result = A >> B % 16; break;
                case 0b111: if (A == B) {expected_result = 0;} else if (A > B) {expected_result = 1;} else {expected_result = 2;} break;
            }

            // Check output
            if (alu->ALUOut != expected_result) 
            {
                std::cout << "Mismatch at Sel=" << sel
                          << " A=" << A << " B=" << B
                          << " Expected=" << expected_result
                          << " Got=" << alu->ALUOut
                          << std::endl;
            }
        }
    }

    std::cout << "ALU Testbench completed." << std::endl;
    delete alu;
    return 0;
}
