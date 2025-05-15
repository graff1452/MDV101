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
    std::ifstream file("/home/zhan/Desktop/MDV101/week14/lab19/emulator/txt/instruction_fetch_unit_out.txt");
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
        bool j_type = false;
        std::cout << "Test#" << test << std::endl;
        if (bitty_core->last_alu_result != registerCValues[test])
        {
            std::cerr << "error in test#" << test << std::endl;
            std::cerr << "should be: " << registerCValues[test] << ", got: " << (int)bitty_core->last_alu_result;
            return 1;
        }
        bitty_core->instruction = instructions[test];
        bitty_core->clk = 0;
        bitty_core->eval();
        bitty_core->clk = 1;
        bitty_core->eval();
        std::cout << "Cicle#1" << std::endl;
        std::cout << "Instruction: " << std::bitset<16>(bitty_core->instruction) << " (DEC: " << std::dec << (bitty_core->instruction) << ")" << " (HEX: " << std::hex << bitty_core->instruction << ")" << std::endl;
        std::cout << "Format: ";
        switch((bitty_core->instruction) & 0b11)
        {
            case 0b00: // R-type
                std::cout << "R-type" << std::endl;
                break;
            case 0b01: // I-type
                std::cout << "I-type" << std::endl;
                break;
            case 0b10: // J-type
                std::cout << "J-type" << std::endl;
                break;
            case 0b11:
                std::cout << "LOAD/STORE-type" << std::endl;
                break;
        }
        std::cout << "Operation: ";
        switch((bitty_core->instruction) & 0b11)
        {
            case 0b00: // R-type
                switch(((bitty_core->instruction) >> 2) & 0b111)
                {
                    case 0b000: std::cout << "ADD"; break;
                    case 0b001: std::cout << "SUB"; break;
                    case 0b010: std::cout << "AND"; break;
                    case 0b011: std::cout << "OR"; break;
                    case 0b100: std::cout << "XOR"; break;
                    case 0b101: std::cout << "SHL"; break;
                    case 0b110: std::cout << "SHR"; break;
                    case 0b111: std::cout << "CONDITION"; break;
                }
                break;
            case 0b01: // I-type
                switch(((bitty_core->instruction) >> 2) & 0b111)
                {
                    case 0x00: std::cout << "ADD"; break;
                    case 0x01: std::cout << "SUB"; break;
                    case 0x02: std::cout << "AND"; break;
                    case 0x03: std::cout << "OR"; break;
                    case 0x04: std::cout << "XOR"; break;
                    case 0x05: std::cout << "SHL"; break;
                    case 0x06: std::cout << "SHR"; break;
                    case 0x07: std::cout << "CONDITION"; break;
                }
                break;
            case 0b10: // J-type
                switch(((bitty_core->instruction) >> 2) & 0b11)
                {
                    case 0b00: std::cout << "BEZ"; break;
                    case 0b01: std::cout << "BE (1)"; break;
                    case 0b10: std::cout << "BE (2)"; break;
                    default: std::cout << "BEZ"; break;
                }
                j_type = true;
                break;
            case 0b11: //LOAD/STORE-type
                switch(((bitty_core->instruction) >> 2) & 0b1)
                {
                    case 0b0: std::cout << "LOAD"; break;
                    case 0b1: std::cout << "STORE"; break;
                }
                break;
        }
        std::cout << std::endl;
        std::cout << "Rx = " << std::bitset<16>(((bitty_core->instruction) >> 13) & 0b111) << " (DEC: " << std::dec << (((bitty_core->instruction) >> 13) & 0b111) << ")" << " (HEX: " << std::hex << (((bitty_core->instruction) >> 13) & 0b111) << ")" << std::endl;
        std::cout << "Ry = " << std::bitset<16>(((bitty_core->instruction) >> 10) & 0b111) << " (DEC: " << std::dec << (((bitty_core->instruction) >> 10) & 0b111) << ")" << " (HEX: " << std::hex << (((bitty_core->instruction) >> 10) & 0b111) << ")" << std::endl;
        if (j_type)
        {
            std::cout << "Immediate value = " << std::bitset<12>(((bitty_core->instruction) >> 4) & 0xFFF) << " (DEC: " << std::dec << (((bitty_core->instruction) >> 4) & 0xFFF) << ")" << " (HEX: " << std::hex << (((bitty_core->instruction) >> 4) & 0xFFF) << ")" << std::endl;
        }
        else 
        {
            std::cout << "Immediate value = " << std::bitset<8>(((bitty_core->instruction) >> 5) & 0xFF) << " (DEC: " << std::dec << (((bitty_core->instruction) >> 5) & 0xFF) << ")" << " (HEX: " << std::hex << (((bitty_core->instruction) >> 5) & 0xFF) << ")" << std::endl;
        }
        std::cout << "done1: " << std::bitset<1>(bitty_core->done1) << std::endl;
        std::cout << "done2: " << std::bitset<1>(bitty_core->done2) << std::endl;
        std::cout << "Reg_0_Out: " << std::bitset<16>(bitty_core->Reg_0_Out) << " (DEC: " << std::dec << bitty_core->Reg_0_Out << ")" << std::endl;
        std::cout << "Reg_1_Out: " << std::bitset<16>(bitty_core->Reg_1_Out) << " (DEC: " << std::dec << bitty_core->Reg_1_Out << ")" << std::endl;
        std::cout << "Reg_2_Out: " << std::bitset<16>(bitty_core->Reg_2_Out) << " (DEC: " << std::dec << bitty_core->Reg_2_Out << ")" << std::endl;
        std::cout << "Reg_3_Out: " << std::bitset<16>(bitty_core->Reg_3_Out) << " (DEC: " << std::dec << bitty_core->Reg_3_Out << ")" << std::endl;
        std::cout << "Reg_4_Out: " << std::bitset<16>(bitty_core->Reg_4_Out) << " (DEC: " << std::dec << bitty_core->Reg_4_Out << ")" << std::endl;
        std::cout << "Reg_5_Out: " << std::bitset<16>(bitty_core->Reg_5_Out) << " (DEC: " << std::dec << bitty_core->Reg_5_Out << ")" << std::endl;
        std::cout << "Reg_6_Out: " << std::bitset<16>(bitty_core->Reg_6_Out) << " (DEC: " << std::dec << bitty_core->Reg_6_Out << ")" << std::endl;
        std::cout << "Reg_7_Out: " << std::bitset<16>(bitty_core->Reg_7_Out) << " (DEC: " << std::dec << bitty_core->Reg_7_Out << ")" << std::endl;
        std::cout << "last alu input: " << std::bitset<16>(bitty_core->last_alu_result) << " (DEC: " << std::dec << bitty_core->last_alu_result << ")" <<  std::endl << std::endl;

        bitty_core->clk = 0;
        bitty_core->eval();
        bitty_core->clk = 1;
        bitty_core->eval();
        std::cout << "Cicle#2" << std::endl;
        std::cout << "instruction: " << std::bitset<16>(bitty_core->instruction) << std::endl;
        std::cout << "done1: " << std::bitset<1>(bitty_core->done1) << std::endl;
        std::cout << "done2: " << std::bitset<1>(bitty_core->done2) << std::endl;
        std::cout << "Reg_0_Out: " << std::bitset<16>(bitty_core->Reg_0_Out) << " (DEC: " << std::dec << bitty_core->Reg_0_Out << ")" << std::endl;
        std::cout << "Reg_1_Out: " << std::bitset<16>(bitty_core->Reg_1_Out) << " (DEC: " << std::dec << bitty_core->Reg_1_Out << ")" << std::endl;
        std::cout << "Reg_2_Out: " << std::bitset<16>(bitty_core->Reg_2_Out) << " (DEC: " << std::dec << bitty_core->Reg_2_Out << ")" << std::endl;
        std::cout << "Reg_3_Out: " << std::bitset<16>(bitty_core->Reg_3_Out) << " (DEC: " << std::dec << bitty_core->Reg_3_Out << ")" << std::endl;
        std::cout << "Reg_4_Out: " << std::bitset<16>(bitty_core->Reg_4_Out) << " (DEC: " << std::dec << bitty_core->Reg_4_Out << ")" << std::endl;
        std::cout << "Reg_5_Out: " << std::bitset<16>(bitty_core->Reg_5_Out) << " (DEC: " << std::dec << bitty_core->Reg_5_Out << ")" << std::endl;
        std::cout << "Reg_6_Out: " << std::bitset<16>(bitty_core->Reg_6_Out) << " (DEC: " << std::dec << bitty_core->Reg_6_Out << ")" << std::endl;
        std::cout << "Reg_7_Out: " << std::bitset<16>(bitty_core->Reg_7_Out) << " (DEC: " << std::dec << bitty_core->Reg_7_Out << ")" << std::endl;
        std::cout << "last alu input: " << std::bitset<16>(bitty_core->last_alu_result) << " (DEC: " << std::dec << bitty_core->last_alu_result << ")" <<  std::endl << std::endl;

        bitty_core->clk = 0;
        bitty_core->eval();
        bitty_core->clk = 1;
        bitty_core->eval();
        std::cout << "Cicle#3" << std::endl;
        std::cout << "instruction: " << std::bitset<16>(bitty_core->instruction) << std::endl;
        std::cout << "done1: " << std::bitset<1>(bitty_core->done1) << std::endl;
        std::cout << "done2: " << std::bitset<1>(bitty_core->done2) << std::endl;
        std::cout << "Reg_0_Out: " << std::bitset<16>(bitty_core->Reg_0_Out) << " (DEC: " << std::dec << bitty_core->Reg_0_Out << ")" << std::endl;
        std::cout << "Reg_1_Out: " << std::bitset<16>(bitty_core->Reg_1_Out) << " (DEC: " << std::dec << bitty_core->Reg_1_Out << ")" << std::endl;
        std::cout << "Reg_2_Out: " << std::bitset<16>(bitty_core->Reg_2_Out) << " (DEC: " << std::dec << bitty_core->Reg_2_Out << ")" << std::endl;
        std::cout << "Reg_3_Out: " << std::bitset<16>(bitty_core->Reg_3_Out) << " (DEC: " << std::dec << bitty_core->Reg_3_Out << ")" << std::endl;
        std::cout << "Reg_4_Out: " << std::bitset<16>(bitty_core->Reg_4_Out) << " (DEC: " << std::dec << bitty_core->Reg_4_Out << ")" << std::endl;
        std::cout << "Reg_5_Out: " << std::bitset<16>(bitty_core->Reg_5_Out) << " (DEC: " << std::dec << bitty_core->Reg_5_Out << ")" << std::endl;
        std::cout << "Reg_6_Out: " << std::bitset<16>(bitty_core->Reg_6_Out) << " (DEC: " << std::dec << bitty_core->Reg_6_Out << ")" << std::endl;
        std::cout << "Reg_7_Out: " << std::bitset<16>(bitty_core->Reg_7_Out) << " (DEC: " << std::dec << bitty_core->Reg_7_Out << ")" << std::endl;
        std::cout << "last alu input: " << std::bitset<16>(bitty_core->last_alu_result) << " (DEC: " << std::dec << bitty_core->last_alu_result << ")" <<  std::endl << std::endl;

        bitty_core->clk = 0;
        bitty_core->eval();
        bitty_core->clk = 1;
        bitty_core->eval();
        std::cout << "Cicle#4" << std::endl;
        std::cout << "instruction: " << std::bitset<16>(bitty_core->instruction) << std::endl;
        std::cout << "done1: " << std::bitset<1>(bitty_core->done1) << std::endl;
        std::cout << "done2: " << std::bitset<1>(bitty_core->done2) << std::endl;
        std::cout << "Reg_0_Out: " << std::bitset<16>(bitty_core->Reg_0_Out) << " (DEC: " << std::dec << bitty_core->Reg_0_Out << ")" << std::endl;
        std::cout << "Reg_1_Out: " << std::bitset<16>(bitty_core->Reg_1_Out) << " (DEC: " << std::dec << bitty_core->Reg_1_Out << ")" << std::endl;
        std::cout << "Reg_2_Out: " << std::bitset<16>(bitty_core->Reg_2_Out) << " (DEC: " << std::dec << bitty_core->Reg_2_Out << ")" << std::endl;
        std::cout << "Reg_3_Out: " << std::bitset<16>(bitty_core->Reg_3_Out) << " (DEC: " << std::dec << bitty_core->Reg_3_Out << ")" << std::endl;
        std::cout << "Reg_4_Out: " << std::bitset<16>(bitty_core->Reg_4_Out) << " (DEC: " << std::dec << bitty_core->Reg_4_Out << ")" << std::endl;
        std::cout << "Reg_5_Out: " << std::bitset<16>(bitty_core->Reg_5_Out) << " (DEC: " << std::dec << bitty_core->Reg_5_Out << ")" << std::endl;
        std::cout << "Reg_6_Out: " << std::bitset<16>(bitty_core->Reg_6_Out) << " (DEC: " << std::dec << bitty_core->Reg_6_Out << ")" << std::endl;
        std::cout << "Reg_7_Out: " << std::bitset<16>(bitty_core->Reg_7_Out) << " (DEC: " << std::dec << bitty_core->Reg_7_Out << ")" << std::endl;
        std::cout << "last alu input: " << std::bitset<16>(bitty_core->last_alu_result) << " (DEC: " << std::dec << bitty_core->last_alu_result << ")" <<  std::endl << std::endl;

        bitty_core->clk = 0;
        bitty_core->eval();
        bitty_core->clk = 1;
        bitty_core->eval();
        std::cout << "Cicle#5" << std::endl;
        std::cout << "instruction: " << std::bitset<16>(bitty_core->instruction) << std::endl;
        std::cout << "done1: " << std::bitset<1>(bitty_core->done1) << std::endl;
        std::cout << "done2: " << std::bitset<1>(bitty_core->done2) << std::endl;
        std::cout << "Reg_0_Out: " << std::bitset<16>(bitty_core->Reg_0_Out) << " (DEC: " << std::dec << bitty_core->Reg_0_Out << ")" << std::endl;
        std::cout << "Reg_1_Out: " << std::bitset<16>(bitty_core->Reg_1_Out) << " (DEC: " << std::dec << bitty_core->Reg_1_Out << ")" << std::endl;
        std::cout << "Reg_2_Out: " << std::bitset<16>(bitty_core->Reg_2_Out) << " (DEC: " << std::dec << bitty_core->Reg_2_Out << ")" << std::endl;
        std::cout << "Reg_3_Out: " << std::bitset<16>(bitty_core->Reg_3_Out) << " (DEC: " << std::dec << bitty_core->Reg_3_Out << ")" << std::endl;
        std::cout << "Reg_4_Out: " << std::bitset<16>(bitty_core->Reg_4_Out) << " (DEC: " << std::dec << bitty_core->Reg_4_Out << ")" << std::endl;
        std::cout << "Reg_5_Out: " << std::bitset<16>(bitty_core->Reg_5_Out) << " (DEC: " << std::dec << bitty_core->Reg_5_Out << ")" << std::endl;
        std::cout << "Reg_6_Out: " << std::bitset<16>(bitty_core->Reg_6_Out) << " (DEC: " << std::dec << bitty_core->Reg_6_Out << ")" << std::endl;
        std::cout << "Reg_7_Out: " << std::bitset<16>(bitty_core->Reg_7_Out) << " (DEC: " << std::dec << bitty_core->Reg_7_Out << ")" << std::endl;
        std::cout << "last alu input: " << std::bitset<16>(bitty_core->last_alu_result) << " (DEC: " << std::dec << bitty_core->last_alu_result << ")" <<  std::endl << std::endl;

        bitty_core->clk = 0;
        bitty_core->eval();
        bitty_core->clk = 1;
        bitty_core->eval();
        std::cout << "Cicle#6" << std::endl;
        std::cout << "instruction: " << std::bitset<16>(bitty_core->instruction) << std::endl;
        std::cout << "done1: " << std::bitset<1>(bitty_core->done1) << std::endl;
        std::cout << "done2: " << std::bitset<1>(bitty_core->done2) << std::endl;
        std::cout << "Reg_0_Out: " << std::bitset<16>(bitty_core->Reg_0_Out) << " (DEC: " << std::dec << bitty_core->Reg_0_Out << ")" << std::endl;
        std::cout << "Reg_1_Out: " << std::bitset<16>(bitty_core->Reg_1_Out) << " (DEC: " << std::dec << bitty_core->Reg_1_Out << ")" << std::endl;
        std::cout << "Reg_2_Out: " << std::bitset<16>(bitty_core->Reg_2_Out) << " (DEC: " << std::dec << bitty_core->Reg_2_Out << ")" << std::endl;
        std::cout << "Reg_3_Out: " << std::bitset<16>(bitty_core->Reg_3_Out) << " (DEC: " << std::dec << bitty_core->Reg_3_Out << ")" << std::endl;
        std::cout << "Reg_4_Out: " << std::bitset<16>(bitty_core->Reg_4_Out) << " (DEC: " << std::dec << bitty_core->Reg_4_Out << ")" << std::endl;
        std::cout << "Reg_5_Out: " << std::bitset<16>(bitty_core->Reg_5_Out) << " (DEC: " << std::dec << bitty_core->Reg_5_Out << ")" << std::endl;
        std::cout << "Reg_6_Out: " << std::bitset<16>(bitty_core->Reg_6_Out) << " (DEC: " << std::dec << bitty_core->Reg_6_Out << ")" << std::endl;
        std::cout << "Reg_7_Out: " << std::bitset<16>(bitty_core->Reg_7_Out) << " (DEC: " << std::dec << bitty_core->Reg_7_Out << ")" << std::endl;
        std::cout << "last alu input: " << std::bitset<16>(bitty_core->last_alu_result) << " (DEC: " << std::dec << bitty_core->last_alu_result << ")" <<  std::endl << std::endl;
    }
    delete bitty_core;
    return 0;
}