#include "bitty_emu.h"

uint16_t BittyEmulator::Evaluate(uint16_t instruction)
{
    uint8_t     Rx      = (instruction >> 13)           & 0x07;
    uint8_t     Ry      = (instruction >> 10)           & 0x07;
    uint8_t     format  = (instruction)                 & 0x03;
    uint8_t     ALU_sel = (instruction >> 2)            & 0x07;
    uint16_t    immediate_value = (instruction >> 5)    & 0x00FF;
    if (format == 0x00) // R-type
    {
        switch (ALU_sel)
        {
            case 0b000: registers_[Rx] = registers_[Rx] +   registers_[Ry];             break; 
            case 0b001: registers_[Rx] = registers_[Rx] -   registers_[Ry];             break; 
            case 0b010: registers_[Rx] = registers_[Rx] &   registers_[Ry];             break; 
            case 0b011: registers_[Rx] = registers_[Rx] |   registers_[Ry];             break; 
            case 0b100: registers_[Rx] = registers_[Rx] ^   registers_[Ry];             break;
            case 0b101: registers_[Rx] = registers_[Rx] <<  registers_[Ry] % 16;        break; 
            case 0b110: registers_[Rx] = registers_[Rx] >>  registers_[Ry] % 16;        break; 
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
    }
    else if (format == 0x01) // I-type
    {
        switch (ALU_sel)
        {
            case 0b000: registers_[Rx] = registers_[Rx] +   immediate_value;        break; 
            case 0b001: registers_[Rx] = registers_[Rx] -   immediate_value;        break; 
            case 0b010: registers_[Rx] = registers_[Rx] &   immediate_value;        break; 
            case 0b011: registers_[Rx] = registers_[Rx] |   immediate_value;        break; 
            case 0b100: registers_[Rx] = registers_[Rx] ^   immediate_value;        break;
            case 0b101: registers_[Rx] = registers_[Rx] <<  immediate_value % 16;   break; 
            case 0b110: registers_[Rx] = registers_[Rx] >>  immediate_value % 16;   break;
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
    }
    return registers_[Rx];
}

uint16_t BittyEmulator::GetRegisterValue(uint16_t reg_num)
{
    return registers_[reg_num];
}

void BittyEmulator::SetRegisterValue(uint16_t reg_num, uint16_t value)
{
    registers_[reg_num] = value;
}
