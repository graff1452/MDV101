#include "bitty_generator.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

uint16_t BittyInstructionGenerator::Generate() {
    std::srand(std::time(nullptr));  // Seed for random values
    return std::rand() % 0xFFFF;  // Generate a random 16-bit instruction
}