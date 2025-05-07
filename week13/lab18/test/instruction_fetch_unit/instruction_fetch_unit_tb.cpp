#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "verilated.h"
#include "Vinstruction_fetch_unit.h"
#include <cstdlib>
#include <ctime>
#include <bitset>
#include <cstdint>

#define NUM_TESTS 256 // Number of tests

int main(int argc, char **argv, char **env) {
    Verilated::commandArgs(argc, argv);
    Vinstruction_fetch_unit *instruction_fetch_unit = new Vinstruction_fetch_unit;

    instruction_fetch_unit->clk = 0; // Initialize clock
    instruction_fetch_unit->reset = 1; // Assert reset
    instruction_fetch_unit->eval(); // Evaluate the design
    instruction_fetch_unit->reset = 0; // Deassert reset
    instruction_fetch_unit->en_pc = 1; // Enable the PC
    instruction_fetch_unit->eval(); // Evaluate the design again

    if (instruction_fetch_unit->instruction_out != 0)
    {
        std::cerr << "Error: Instruction output should be 0 after reset." << std::endl;
        return 1;
    }

    // Vector to store instructions
    std::vector<uint16_t> instructions;

    // Read instructions from file
    std::ifstream file("/home/zhan/Desktop/MDV101/week12/lab16/generator/instructions.txt");
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

    instruction_fetch_unit->clk = 0; // Initialize clock
    instruction_fetch_unit->eval(); // Evaluate the design
    instruction_fetch_unit->clk = 1; // Rising edge
    instruction_fetch_unit->eval(); // Evaluate the design

    for (int test = 0; test < NUM_TESTS; test++) 
    {
        instruction_fetch_unit->clk = 0; // Initialize clock
        instruction_fetch_unit->eval(); // Evaluate the design
        instruction_fetch_unit->clk = 1; // Rising edge
        instruction_fetch_unit->eval(); // Evaluate the design

        if (instruction_fetch_unit->instruction_out != instructions[test]) 
        {
            std::cerr << "Error: Instruction output mismatch at test " << test << ". Expected: " << std::hex << instructions[test] << ", Got: " << std::hex << instruction_fetch_unit->instruction_out << std::endl;
            return 1;
        }
    }
    std::cout << "All tests passed!" << std::endl;
    delete instruction_fetch_unit; // Clean up
    return 0;
}
