#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <bitset>

// Function to print usage instructions
void printUsage(const char* programName) {
    std::cerr << "Usage: " << programName << " -i <input file> [-o <output file>] -a|-d" << std::endl;
}

// Function to assemble assembly code into machine code
void assemble(const std::string& inputFileName, const std::string& outputFileName = "") {
    // Define the instruction set
    std::map<std::string, uint8_t> instructionToALU = {
        {"ADD", 0b000},
        {"SUB", 0b001},
        {"AND", 0b010},
        {"OR",  0b011},
        {"XOR", 0b100},
        {"LSH", 0b101}, // Left shift
        {"RSH", 0b110}, // Right shift
        {"CMP", 0b111}  // Compare
    };

    // Open the input file
    std::ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open input file: " << inputFileName << std::endl;
        return;
    }

    // Open the output file if specified
    std::ofstream outputFile;
    if (!outputFileName.empty()) {
        outputFile.open(outputFileName, std::ios::binary);
        if (!outputFile.is_open()) {
            std::cerr << "Error: Could not open output file: " << outputFileName << std::endl;
            return;
        }
    }

    // Read and encode the assembly code
    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string instruction, rx, ry_or_imm;
        iss >> instruction >> rx >> ry_or_imm;

        if (instructionToALU.count(instruction) == 0) {
            std::cerr << "Error: Unknown instruction '" << instruction << "' in line: " << line << std::endl;
            continue;
        }

        uint8_t alu_sel = instructionToALU[instruction];
        uint8_t rx_num = std::stoi(rx.substr(1)); // Extract register number (e.g., R1 -> 1)
        uint16_t encodedInstruction = 0;

        if (ry_or_imm[0] == 'R') { // R-type instruction
            uint8_t ry_num = std::stoi(ry_or_imm.substr(1));
            encodedInstruction = (rx_num << 13) | (ry_num << 10) | (alu_sel << 2) | 0b00;
        } else { // I-type instruction
            uint8_t imm_value = std::stoi(ry_or_imm);
            encodedInstruction = (rx_num << 13) | (alu_sel << 2) | (imm_value << 5) | 0b01;
        }

        // Write to output file or print to console
        if (outputFile.is_open()) {
            outputFile.write(reinterpret_cast<const char*>(&encodedInstruction), sizeof(encodedInstruction));
        } else {
            std::cout << "Encoded: " << line << "\t" << " -> " << std::bitset<16>(encodedInstruction) << std::endl;
        }
    }

    // Close files
    inputFile.close();
    if (outputFile.is_open()) {
        outputFile.close();
    }
}

// Function to disassemble machine code into assembly code
void disassemble(const std::string& inputFileName, const std::string& outputFileName = "") {
    // Define the instruction set
    std::map<uint8_t, std::string> aluToInstruction = {
        {0b000, "ADD"},
        {0b001, "SUB"},
        {0b010, "AND"},
        {0b011, "OR"},
        {0b100, "XOR"},
        {0b101, "LSH"}, // Left shift
        {0b110, "RSH"}, // Right shift
        {0b111, "CMP"}  // Compare
    };

    // Open the input file
    std::ifstream inputFile(inputFileName, std::ios::binary);
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open input file: " << inputFileName << std::endl;
        return;
    }

    // Open the output file if specified
    std::ofstream outputFile;
    if (!outputFileName.empty()) {
        outputFile.open(outputFileName);
        if (!outputFile.is_open()) {
            std::cerr << "Error: Could not open output file: " << outputFileName << std::endl;
            return;
        }
    }

    // Read and decode the machine code
    uint16_t encodedInstruction;
    while (inputFile.read(reinterpret_cast<char*>(&encodedInstruction), sizeof(encodedInstruction))) {
        uint8_t rx = (encodedInstruction >> 13) & 0x07;
        uint8_t ry = (encodedInstruction >> 10) & 0x07;
        uint8_t alu_sel = (encodedInstruction >> 2) & 0x07;
        uint8_t format = encodedInstruction & 0x03;

        std::string decodedInstruction;
        if (format == 0b01) { // I-type
            uint8_t imm_value = (encodedInstruction >> 5) & 0x7F;
            decodedInstruction = aluToInstruction[alu_sel] + " R" + std::to_string(rx) + " " + std::to_string(imm_value);
        } else { // R-type
            decodedInstruction = aluToInstruction[alu_sel] + " R" + std::to_string(rx) + " R" + std::to_string(ry);
        }

        // Write to output file or print to console
        if (outputFile.is_open()) {
            outputFile << decodedInstruction << std::endl;
        } else {
            std::cout << decodedInstruction << std::endl;
        }
    }

    // Close files
    inputFile.close();
    if (outputFile.is_open()) {
        outputFile.close();
    }
}

// Main function to handle command-line arguments
int main(int argc, char *argv[]) {
    if (argc != 4 && argc != 6) {
        std::cerr << "Error: Invalid number of arguments provided." << std::endl;
        printUsage(argv[0]);
        return 1;
    }

    // Check for "-i" flag
    if (std::string(argv[1]) != "-i") {
        std::cerr << "Error: Missing or incorrect '-i' flag for input file." << std::endl;
        printUsage(argv[0]);
        return 1;
    }

    std::string inputFileName = argv[2];
    std::string outputFileName;
    std::string operation;

    if (argc == 6) {
        if (std::string(argv[3]) != "-o") {
            std::cerr << "Error: Missing or incorrect '-o' flag for output file." << std::endl;
            printUsage(argv[0]);
            return 1;
        }
        outputFileName = argv[4];
        operation = argv[5];
    } else if (argc == 4) {
        operation = argv[3];
    }

    // Validate operation flag
    if (operation != "-a" && operation != "-d") {
        std::cerr << "Error: Missing or incorrect operation flag. Use '-a' to assemble or '-d' to disassemble." << std::endl;
        printUsage(argv[0]);
        return 1;
    }

    // Perform assembly or disassembly
    if (operation == "-a") {
        assemble(inputFileName, outputFileName);
    } else if (operation == "-d") {
        disassemble(inputFileName, outputFileName);
    }

    return 0;
}