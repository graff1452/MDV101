#include <verilated.h>
#include "Valu.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

#define NUM_TESTS 1000000

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);
    Valu* alu = new Valu;  // Instantiate the ALU module

    std::srand(std::time(nullptr));  // Seed for random values

    for (int sel = 0; sel < 16; sel++) // Loop through all Sel values 
    {
        for (int test = 0; test < NUM_TESTS; test++) 
        {
            uint16_t A = std::rand() & 0xFFFF;  // Generate random 16-bit A
            uint16_t B = std::rand() & 0xFFFF;  // Generate random 16-bit B
            int Mode = std::rand() % 2;        // Randomly choose Logic (1) or Arithmetic mode (0)
            int CIn = std::rand() % 2;         // Randomly choose CIn (0 or 1)

            // Apply inputs
            alu->A = A;
            alu->B = B;
            alu->Sel = sel;
            alu->Mode = Mode;
            alu->CIn = CIn;

            alu->eval();

            uint16_t expected_result;  // Variable for expected result
            bool expected_cout = false;
            bool expected_cmp = false;

            // Logic operations
            if (Mode == 1) {
                switch (sel) {
                    case 0x0: expected_result = ~A; break;
                    case 0x1: expected_result = ~(A | B); break;
                    case 0x2: expected_result = ~A & B; break;
                    case 0x3: expected_result = 0x0000; break;
                    case 0x4: expected_result = ~(A & B); break;
                    case 0x5: expected_result = ~B; break;
                    case 0x6: expected_result = A ^ B; break;
                    case 0x7: expected_result = A & ~B; break;
                    case 0x8: expected_result = ~A | B; break;
                    case 0x9: expected_result = ~(A ^ B); break;
                    case 0xA: expected_result = B; break;
                    case 0xB: expected_result = A & B; break;
                    case 0xC: expected_result = 0xFFFF; break;
                    case 0xD: expected_result = A | ~B; break;
                    case 0xE: expected_result = A | B; break;
                    case 0xF: expected_result = A; break;
                }
            }
            // Arithmetic operations
            else 
            {
                int32_t result = 0;
                switch (sel) {
                    case 0x0: result = A; break;
                    case 0x1: result = A | B; break;
                    case 0x2: result = A | ~B; break;
                    case 0x3: result = 0xFFFF; break;
                    case 0x4: result = A | (A & ~B); break;
                    case 0x5: result = (A | B) + (A & ~B) + CIn; break;
                    case 0x6: result = A - B - 1; break;
                    case 0x7: result = (A & ~B) - 1; break;
                    case 0x8: result = A + (A & B) + CIn; break;
                    case 0x9: result = A + B + CIn; break;
                    case 0xA: result = (A | ~B) + (A & B) + CIn; break;
                    case 0xB: result = (A & B) - 1; break;
                    case 0xC: result = A + A + CIn; break;
                    case 0xD: result = (A | B) + A + CIn; break;
                    case 0xE: result = (A | ~B) + A + CIn; break;
                    case 0xF: result = A - 1; break;
                }
                expected_result = result & 0xFFFF;  // Truncate to 16 bits
                expected_cout = (result >> 16) & 1; // Extract carry-out bit
                expected_cmp = A == B;
            }

            // Check output
            if (alu->ALUOut != expected_result || alu->COut != expected_cout || alu->Cmp != expected_cmp) 
            {
                std::cout << "Mismatch at Sel=" << sel
                          << " A=" << A << " B=" << B
                          << " Mode=" << Mode << " CIn=" << CIn
                          << " Expected=" << expected_result
                          << " Got=" << alu->ALUOut
                          << " Expected COut=" << expected_cout
                          << " Got COut=" << (int)alu->COut
                          << " Expected Cmp=" << expected_cmp
                          << " Got Cmp=" << (int)alu->Cmp
                          << std::endl;
            }
        }
    }

    std::cout << "ALU Testbench completed." << std::endl;
    delete alu;
    return 0;
}
