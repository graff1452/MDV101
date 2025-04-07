#include "verilated.h"
#include "Vmux.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

#define NUM_TESTS 1000000 // Number of tests

int main(int argc, char** argv)
{
    Verilated::commandArgs(argc, argv); 
    Vmux* mux = new Vmux; // Creating multiplexor

    std::srand(std::time(nullptr));  // Seed for random values

    for (int sel = 0; sel < 16; sel++) // Going through all possible selector values
    {
        for (int test = 0; test < NUM_TESTS; test++) // Number of tests in each selected value for selector
        {

            uint16_t in_0 = std::rand() & 0xFFFF; // Random 16-bit values
            uint16_t in_1 = std::rand() & 0xFFFF;
            uint16_t in_2 = std::rand() & 0xFFFF;
            uint16_t in_3 = std::rand() & 0xFFFF;
            uint16_t in_4 = std::rand() & 0xFFFF;
            uint16_t in_5 = std::rand() & 0xFFFF;
            uint16_t in_6 = std::rand() & 0xFFFF;
            uint16_t in_7 = std::rand() & 0xFFFF;
            uint16_t in_8 = std::rand() & 0xFFFF;
            uint16_t in_9 = std::rand() & 0xFFFF;

            uint16_t expected_result; // The expected result

            mux->mux_sel = sel; // Assigning values to mux inputs
            mux->in_0 = in_0;
            mux->in_1 = in_1;
            mux->in_2 = in_2;
            mux->in_3 = in_3;
            mux->in_4 = in_4;
            mux->in_5 = in_5;
            mux->in_6 = in_6;
            mux->in_7 = in_7;
            mux->in_8 = in_8;
            mux->in_9 = in_9;
            mux->eval();

            switch (sel) 
            {
                case 0x0: expected_result = in_0; break;
                case 0x1: expected_result = in_1; break;
                case 0x2: expected_result = in_2; break;
                case 0x3: expected_result = in_3; break;
                case 0x4: expected_result = in_4; break;
                case 0x5: expected_result = in_5; break;
                case 0x6: expected_result = in_6; break;
                case 0x7: expected_result = in_7; break;
                case 0x8: expected_result = in_8; break;
                case 0x9: expected_result = in_9; break;
                default: expected_result = 0x0000; break;
            }

            // Check output
            if (mux->mux_out != expected_result) {
                std::cout   << "Mismatch at Sel=" << sel
                            << " in_0=" << in_0 
                            << " in_1=" << in_1 
                            << " in_2=" << in_2 
                            << " in_3=" << in_3 
                            << " in_4=" << in_4 
                            << " in_5=" << in_5 
                            << " in_6=" << in_6 
                            << " in_7=" << in_7
                            << " in_8=" << in_8
                            << " in_9=" << in_9
                            << " Expected=" << expected_result
                            << " Got=" << mux->mux_out
                            << std::endl;
            }
        }
    }

    std::cout << "mux Testbench completed." << std::endl;
    delete mux;
    return 0;
}
