#include <iostream>
#include "verilated.h"
#include "Vbitty_core.h"
#include <cstdlib>
#include <ctime>
#include <bitset>
#include <cstdint>
#include <fstream>
#include <vector>
#include <string>

#define NUM_TESTS 256

int main(int argc, char** argv)
{
    Verilated::commandArgs(argc, argv);
    Vbitty_core* bitty_core = new Vbitty_core; // Instantiate bitty_core



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



    bitty_core->reset = 1;
    bitty_core->clk = 0;
    bitty_core->eval();
    bitty_core->clk = 1;
    bitty_core->eval();
    bitty_core->reset = 0;
    bitty_core->run = 1;
    bitty_core->eval();

    // Initialize signals
    std::cout << "Starting bitty_core Test with " << std::dec << NUM_TESTS << " iterations.\n";

    for (int i = 0; i < 4; i++)
    {
        bitty_core->clk = 0;
        bitty_core->eval();
        bitty_core->clk = 1;
        bitty_core->eval();
    }

    for (int test = 0; test < NUM_TESTS; test++)
    {
        bitty_core->instruction = instructions[test]; // Set the instruction
        std::cout << "last_alu_result = " << std::dec << bitty_core->last_alu_result << std::endl;
        for (int i = 0; i < 5; i++)
        {
            bitty_core->clk = 0;
            bitty_core->eval();
            bitty_core->clk = 1;
            bitty_core->eval();
        }
    }
    delete bitty_core;
    return 0;
}