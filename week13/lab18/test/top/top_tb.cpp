#include <iostream>
#include "verilated.h"
#include "Vtop.h"
#include <cstdlib>
#include <ctime>
#include <bitset>
#include <vector>
#include <cstdint>
#include <fstream>

#define NUM_TESTS 256 // Number of tests

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);
    Vtop *top = new Vtop; // Creating top module



        // Vector to store instructions
    std::vector<uint16_t> instructions;

    // Read instructions from file
    std::ifstream file("/home/zhan/Desktop/MDV101/week13/lab18/emulator/txt/instruction_fetch_unit_out.txt");
    if (!file.is_open()) {
        std::cerr << "Error: Could not open instructions file." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) {
            try {
                uint16_t instruction = static_cast<uint16_t>(std::stoi(line, nullptr, 16)); // Convert hex string to uint16_t
                instructions.push_back(instruction);
            } catch (const std::invalid_argument& e) {
                std::cerr << "Invalid instruction format: " << line << std::endl;
            }
        }
    }
    file.close();

    // Debug: Print loaded instructions
    // std::cout << "Loaded instructions:" << std::endl;
    // for (size_t i = 0; i < instructions.size(); i++) {
    //     std::cout << "Instruction[" << i << "] = " << std::hex << instructions[i] << std::endl;
    // }



    // Start the test
    top->reset = 0; // Enable the run signal
    top->eval();
    top->reset = 1;
    top->eval();
    top->reset = 0; // Enable the run signal
    top->run = 1;
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
        // std::cout << "Test#" << test << ", instruction: " << std::hex << (top->top_out) << std::endl;
        if (top->top_out != instructions[test])
        {
            std::cerr << "error in test#" << test << std::endl;
            return 1;
        }
    }

    std::cout << "Top Testbench completed." << std::endl;
    delete top;
    return 0;
}