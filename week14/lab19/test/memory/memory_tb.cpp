#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "verilated.h"
#include "Vmemory.h"
#include <cstdlib>
#include <cstdint>

#define NUM_TESTS 256 // Number of tests

int main(int argc, char** argv)
{
    Verilated::commandArgs(argc, argv);
    Vmemory* myMemory = new Vmemory; // Creating memory

    int clk;
    uint8_t address;
    uint16_t out;

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
    std::cout << "Loaded instructions:" << std::endl;
    for (size_t i = 0; i < instructions.size(); i++) {
        std::cout << "Instruction[" << i << "] = " << std::hex << instructions[i] << std::endl;
    }

    for (int test = 0; test < NUM_TESTS; test++)
    {
        myMemory->clk = 0;
        myMemory->eval();
        myMemory->clk = 1;
        myMemory->address = test;
        myMemory->eval();

        uint16_t expected_value = instructions[test];

        if (myMemory->out != expected_value)
        {
            std::cout << "Test " << std::dec << test + 1 << " failed!" << std::endl;
        } 
        else 
        {
            std::cout << "Test " << std::dec << test + 1 << " passed!" << std::endl;
        }
    }

    std::cout << "Memory Testbench completed." << std::endl;
    delete myMemory;
    return 0;
}