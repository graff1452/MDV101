#include "bitty_generator.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <random>

uint16_t BittyInstructionGenerator::Generate() {
    return std::rand() % 0xFFFF;  // Generate a random 16-bit instruction
}

int main(int argc, char* argv[])
{
    std::srand(std::time(nullptr));  // Seed for random values
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <number_of_instructions>" << std::endl;
        return 1;
    }

    int num_instructions = std::atoi(argv[1]);
    if (num_instructions <= 0)
    {
        std::cerr << "Number of instructions must be a positive integer." << std::endl;
        return 1;
    }
    std::ofstream output_file("instructions.txt");
    if (!output_file)
    {
        std::cerr << "Error opening file for writing." << std::endl;
        return 1;
    }
    BittyInstructionGenerator generator;
    for (int i = 0; i < num_instructions; ++i)
    {
        uint16_t instruction = generator.Generate();
        output_file << std::hex << std::uppercase << instruction << std::endl;
    }
    output_file.close();
    std::cout << "Generated " << num_instructions << " instructions and saved to instructions.txt" << std::endl;
    return 0;
}