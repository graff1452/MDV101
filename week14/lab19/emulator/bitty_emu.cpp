#include "bitty_emu.h"
#include <iostream>
#include <fstream>

uint16_t BittyEmulator::Evaluate(uint16_t instruction)
{
    uint8_t     Rx      = (instruction >> 13)           & 0x07;
    uint8_t     Ry      = (instruction >> 10)           & 0x07;
    uint8_t     format  = (instruction)                 & 0x03;
    uint8_t     ALU_sel = (instruction >> 2)            & 0x07;
    uint16_t    immediate_value = (instruction >> 5)    & 0x00FF;
    uint8_t     condition = (instruction >> 2)          & 0x03;
    if (format == 0b00) // R-type
    {
        switch (ALU_sel)
        {
            case 0b000: registers_[Rx] = registers_[Rx] +   registers_[Ry];             break; 
            case 0b001: registers_[Rx] = registers_[Rx] -   registers_[Ry];             break; 
            case 0b010: registers_[Rx] = registers_[Rx] &   registers_[Ry];             break; 
            case 0b011: registers_[Rx] = registers_[Rx] |   registers_[Ry];             break; 
            case 0b100: registers_[Rx] = registers_[Rx] ^   registers_[Ry];             break;
            case 0b101: registers_[Rx] = registers_[Rx] <<  (registers_[Ry] % 16);        break; 
            case 0b110: registers_[Rx] = registers_[Rx] >>  (registers_[Ry] % 16);        break; 
            case 0b111: 
                if (registers_[Rx] == registers_[Ry]) 
                {
                    registers_[Rx] = 0x0000;
                } else if (registers_[Rx] > registers_[Ry]) 
                {
                    registers_[Rx] = 0x0001;
                } else 
                {
                    registers_[Rx] = 0x0002;
                }
                break;
        }
        register_c = registers_[Rx];
        pc_++;
    }
    else if (format == 0b01) // I-type
    {
        immediate_value = (instruction >> 5)    & 0x00FF;
        switch (ALU_sel)
        {
            case 0b000: registers_[Rx] = registers_[Rx] +   immediate_value;        break; 
            case 0b001: registers_[Rx] = registers_[Rx] -   immediate_value;        break; 
            case 0b010: registers_[Rx] = registers_[Rx] &   immediate_value;        break; 
            case 0b011: registers_[Rx] = registers_[Rx] |   immediate_value;        break; 
            case 0b100: registers_[Rx] = registers_[Rx] ^   immediate_value;        break;
            case 0b101: registers_[Rx] = registers_[Rx] <<  (immediate_value % 16);   break; 
            case 0b110: registers_[Rx] = registers_[Rx] >>  (immediate_value % 16);   break;
            case 0b111: 
                if (registers_[Rx] == immediate_value) 
                {
                    registers_[Rx] = 0x0000;
                } else if (registers_[Rx] > immediate_value) 
                {
                    registers_[Rx] = 0x0001;
                } else 
                {
                    registers_[Rx] = 0x0002;
                }
                break;
        }
        register_c = registers_[Rx];
        pc_++;
    }
    else if (format == 0b10) // J-type
    {
        immediate_value = (instruction >> 4) & 0x0FFF;
        switch (condition)
        {
            case 0b00: 
                if (register_c == 0x0000)
                {
                    pc_ += immediate_value;
                }
                else 
                {
                    pc_++;
                }
                break; // Jump if equal
            case 0b01: 
                if (register_c == 0x0001)
                {
                    pc_ += immediate_value;
                }
                else 
                {
                    pc_++;
                }
                break; // Jump if register C is one
            case 0b10: 
                if (register_c == 0x0002)
                {
                    pc_ += immediate_value;
                }
                else 
                {
                    pc_++;
                }
                break; // Jump if register C is two
            default:
                if (register_c == 0x0000)
                {
                    pc_ += immediate_value;
                }
                else 
                {
                    pc_++;
                }
                break; // Jump if equal
        }
    }
    else // Load, Store Instructions
    {
        switch ((instruction >> 2) & 0b1) 
        {
            case (0b0): // LOAD OPERATION
            SetRegisterValue(Rx, GetRegisterMemoryValue(Ry));
            break;
            case (0b1): // STORE OPERATION
            SetRegisterMemoryValue(Ry, GetRegisterValue(Rx));
            break;
        }
        pc_++;
    }
    if (pc_ >= instruction_memory_.size()) // 
    {
        pc_ = pc_ % instruction_memory_.size(); // Wrap around if PC exceeds memory size
    }
    return registers_[Rx];
}

uint16_t BittyEmulator::GetRegisterValue(uint16_t reg_num)
{
    return registers_[reg_num];
}

uint16_t BittyEmulator::GetPCValue(){return pc_;}

uint16_t BittyEmulator::GetInstructionMemoryValue(uint16_t address)
{
    if (address >= instruction_memory_.size())
    {
        throw std::out_of_range("Instruction memory address out of range");
    }
    return instruction_memory_[address];
}

uint16_t BittyEmulator::GetRegisterMemoryValue(uint16_t address)
{
    if (address >= instruction_memory_.size())
    {
        throw std::out_of_range("Register memory address out of range");
    }
    return register_memory_[address];
}

uint16_t BittyEmulator::GetRegisterCValue(){return register_c;}

void BittyEmulator::SetRegisterValue(uint16_t reg_num, uint16_t value)
{
    if (reg_num >= registers_.size())
    {
        throw std::out_of_range("Register number out of range");
    }
    registers_[reg_num] = value;
}

void BittyEmulator::SetPCValue(uint16_t pc){pc_ = pc;}

void BittyEmulator::SetInstructionMemoryValue(uint16_t address, uint16_t value)
{
    if (address >= instruction_memory_.size())
    {
        throw std::out_of_range("Memory address out of range");
    }
    instruction_memory_[address] = value;
}

void BittyEmulator::SetRegisterMemoryValue(uint16_t address, uint16_t value)
{
    if (address >= register_memory_.size())
    {
        throw std::out_of_range("Register memory address out of range");
    }
    register_memory_[address] = value;
}

void BittyEmulator::SetRegisterCValue(uint16_t value){register_c = value;} // Set Register C output

void BittyEmulator::ResetRegisters() { registers_.assign(16, 0); } // Reset all registers to 0

void BittyEmulator::ResetInstructionMemory() { instruction_memory_.assign(256, 0); } // Reset all memory to 0

void BittyEmulator::ResetRegisterMemory() { register_memory_.assign(8, 0); } // Reset all memory to 0

void BittyEmulator::ResetPC() { pc_ = 0; } // Reset Program Counter to 0

void BittyEmulator::ResetRegisterC() { register_c = 0; } // Reset Register C to 0

bool BittyEmulator::LoadInstructionMemoryFromFile(const std::string& filename, uint16_t start_address)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error opening file: " << filename << std::endl;
        return false;
    }
    std::string line;
    uint16_t address = start_address;
    while (std::getline(file, line))
    {
        std::string instruction_str = line.substr(0, 4);
        uint16_t instruction = static_cast<uint16_t>(std::stoi(instruction_str, nullptr, 16));
        if (line.empty()) continue; // Skip empty lines
        try
        {
            if (address < 256) // Assuming memory size is 256
            {
                instruction_memory_[address] = instruction; // Uncomment this line to load into memory
                address++;
            }
            else
            {
                std::cerr << "Memory overflow at address: " << address << std::endl;
                break;
            }
        }
        catch (const std::invalid_argument& e)
        {
            std::cerr << "Invalid instruction format: " << line << std::endl;
        }
    }
    file.close();
    return true;
}

uint16_t BittyEmulator::Step()
{
    if (pc_ >= instruction_memory_.size()) // 
    {
        pc_ = pc_ % instruction_memory_.size(); // Wrap around if PC exceeds memory size
    }
    uint16_t instruction = instruction_memory_[pc_];
    return Evaluate(instruction);
}
