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



    std::ifstream inputFile("/home/zhan/Desktop/MDV101/week13/lab18/emulator/txt/register_c_values.txt");
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



    bitty_core->reset = 1;
    bitty_core->clk = 0;
    bitty_core->eval();
    bitty_core->clk = 1;
    bitty_core->eval();
    bitty_core->reset = 0;
    bitty_core->run = 1;
    bitty_core->eval();

    std::cout << "At reset: done1 = " << std::bitset<1>(bitty_core->done1) << ", done2 = " << std::bitset<1>(bitty_core->done2) << ", c = " << std::bitset<16>(bitty_core->last_alu_result) << std::endl;

    // Initialize signals
    std::cout << "Starting bitty_core Test with " << std::dec << NUM_TESTS << " iterations.\n";


    for (int test = 0; test < NUM_TESTS; test++)
    {
        if (bitty_core->last_alu_result != registerCValues[test])
        {
            std::cerr << "error in test#" << test << std::endl;
            return 1;
        }
        bitty_core->instruction = instructions[test];
        bitty_core->clk = 0;
        bitty_core->eval();
        bitty_core->clk = 1;
        bitty_core->eval();
        std::cout << "Cycle#1 Test#" << test << ": done1 = " << std::bitset<1>(bitty_core->done1) << ", done2 = " << std::bitset<1>(bitty_core->done2) << ", c = " << std::bitset<16>(bitty_core->last_alu_result) << std::endl;

        bitty_core->clk = 0;
        bitty_core->eval();
        bitty_core->clk = 1;
        bitty_core->eval();
        std::cout << "Cycle#2 Test#" << test << ": done1 = " << std::bitset<1>(bitty_core->done1) << ", done2 = " << std::bitset<1>(bitty_core->done2) << ", c = " << std::bitset<16>(bitty_core->last_alu_result) << std::endl;

        bitty_core->clk = 0;
        bitty_core->eval();
        bitty_core->clk = 1;
        bitty_core->eval();
        std::cout << "Cycle#3 Test#" << test << ": done1 = " << std::bitset<1>(bitty_core->done1) << ", done2 = " << std::bitset<1>(bitty_core->done2) << ", c = " << std::bitset<16>(bitty_core->last_alu_result) << std::endl;

        bitty_core->clk = 0;
        bitty_core->eval();
        bitty_core->clk = 1;
        bitty_core->eval();
        std::cout << "Cycle#4 Test#" << test << ": done1 = " << std::bitset<1>(bitty_core->done1) << ", done2 = " << std::bitset<1>(bitty_core->done2) << ", c = " << std::bitset<16>(bitty_core->last_alu_result) << std::endl;

        bitty_core->clk = 0;
        bitty_core->eval();
        bitty_core->clk = 1;
        bitty_core->eval();
        std::cout << "Cycle#5 Test#" << test << ": done1 = " << std::bitset<1>(bitty_core->done1) << ", done2 = " << std::bitset<1>(bitty_core->done2) << ", c = " << std::bitset<16>(bitty_core->last_alu_result) << std::endl;

        bitty_core->clk = 0;
        bitty_core->eval();
        bitty_core->clk = 1;
        bitty_core->eval();
        std::cout << "Cycle#6 Test#" << test << ": done1 = " << std::bitset<1>(bitty_core->done1) << ", done2 = " << std::bitset<1>(bitty_core->done2) << ", c = " << std::bitset<16>(bitty_core->last_alu_result) << std::endl;
    }
    delete bitty_core;
    return 0;
}