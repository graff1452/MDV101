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
#include <fstream>

#define NUM_TESTS 256 // Number of tests

int main(int argc, char **argv, char **env) {
    Verilated::commandArgs(argc, argv);
    Vinstruction_fetch_unit *instruction_fetch_unit = new Vinstruction_fetch_unit;



    // Vector to store instructions
    std::vector<uint16_t> instructions;

    // Read instructions from file
    std::ifstream file("/home/zhan/Desktop/MDV101/week14/lab19/generator/instructions.txt");
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



    std::ifstream inputFile("/home/zhan/Desktop/MDV101/week14/lab19/emulator/txt/register_c_values.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open file for reading." << std::endl;
        return 1;
    }

    std::vector<uint16_t> registerCValues;
    uint16_t value;

    // Read values from the file and store them in the vector
    while (inputFile >> value) {
        registerCValues.push_back(value);
    }

    inputFile.close();

    // Output the values to verify Debug
    // std::cout << "Values read from the file:" << std::endl;
    // for (const auto& val : registerCValues) {
    //     std::cout << val << std::endl;
    // }



    std::ifstream instructionFetchFile("/home/zhan/Desktop/MDV101/week14/lab19/emulator/txt/instruction_fetch_unit_out.txt");
    if (!instructionFetchFile.is_open()) {
        std::cerr << "Error: Could not open file instruction_fetch_unit_out.txt for reading." << std::endl;
        return 1;
    }
    
    std::vector<uint16_t> instruction_fetch_unit_out;
    uint16_t instructionValue;
    
    // Read values from the file in hexadecimal format
    while (instructionFetchFile >> std::hex >> instructionValue) {
        instruction_fetch_unit_out.push_back(instructionValue);
    }
    
    instructionFetchFile.close();
    
    // Debug: Output the values to verify
    // std::cout << "Values read from instruction_fetch_unit_out.txt:" << std::endl;
    // for (const auto& val : instruction_fetch_unit_out) {
    //     std::cout << std::hex << val << std::endl;
    // }



    instruction_fetch_unit->clk = 0; // Initialize clock
    instruction_fetch_unit->reset = 1; // Assert reset
    instruction_fetch_unit->eval(); // Evaluate the design
    instruction_fetch_unit->clk = 1; // Toggle clock
    instruction_fetch_unit->eval(); // Evaluate the design again
    instruction_fetch_unit->reset = 0; // Deassert reset
    instruction_fetch_unit->clk = 0; // Initialize clock
    instruction_fetch_unit->bitty_core_done1 = 0;
    instruction_fetch_unit->eval(); // Evaluate the design again

    if (instruction_fetch_unit->instruction_out != 0)
    {
        std::cerr << "Error: Instruction output should be 0 after reset." << std::endl;
        return 1;
    }

    for (int test = 0; test < NUM_TESTS; test++) 
    {
        // save the new instruction to the register
        instruction_fetch_unit->bitty_core_done1 = 1;
        instruction_fetch_unit->bitty_core_done2 = 0;
        instruction_fetch_unit->last_alu_result = registerCValues[test]; // Set the last ALU result
        instruction_fetch_unit->clk = 0;
        instruction_fetch_unit->eval();
        instruction_fetch_unit->clk = 1;
        instruction_fetch_unit->eval();

        // save the new instruction to the pc register
        instruction_fetch_unit->bitty_core_done1 = 0;
        instruction_fetch_unit->bitty_core_done2 = 1;
        instruction_fetch_unit->clk = 0;
        instruction_fetch_unit->eval();
        instruction_fetch_unit->clk = 1;
        instruction_fetch_unit->eval();

        // Execute the instruction
        instruction_fetch_unit->bitty_core_done1 = 0;
        instruction_fetch_unit->bitty_core_done2 = 0;
        instruction_fetch_unit->clk = 0;
        instruction_fetch_unit->eval();
        instruction_fetch_unit->clk = 1;
        instruction_fetch_unit->eval();

        if (instruction_fetch_unit->instruction_out != instruction_fetch_unit_out[test])
        {
            std::cerr << "failed at test" << test << std::endl;
        }
    }
    std::cout << "All tests passed!" << std::endl;
    delete instruction_fetch_unit; // Clean up
    return 0;
}
