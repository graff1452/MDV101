#include "Vand_gate.h"
#include <verilated.h>
#include <iostream>

int main(int args, char **argv)
{
    Verilated::commandArgs(args, argv);
    Vand_gate* and_gate = new Vand_gate;

    and_gate->a = 0;
    and_gate->b = 0;
    and_gate->eval();
    std::cout << "a=0, b=0 -> y=" << (int)and_gate->y << std::endl;

    and_gate->a = 0;
    and_gate->b = 1;
    and_gate->eval();
    std::cout << "a=0, b=0 -> y=" << (int)and_gate->y << std::endl;

    and_gate->a = 1;
    and_gate->b = 0;
    and_gate->eval();
    std::cout << "a=0, b=0 -> y=" << (int)and_gate->y << std::endl;

    and_gate->a = 1;
    and_gate->b = 1;
    and_gate->eval();
    std::cout << "a=0, b=0 -> y=" << (int)and_gate->y << std::endl;

    delete and_gate;
    return 0;
}
