#include "Vfibonacci_generator.h"
#include "verilated.h"
#include <iostream>

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);
    Vfibonacci_generator* tb = new Vfibonacci_generator;
    vluint64_t sim_time = 0;
    const vluint64_t max_sim_time = 1000;
    tb->clk = 0;
    tb->rst = 1;
    while (sim_time < max_sim_time) 
    {
        tb->clk = !(tb->clk);
        if (sim_time == 10)
        {
            tb->rst = 0;
        }
        tb->enable = true;
        tb->eval();
        if (tb->clk && !tb->rst) {
            std::cout << "Cycle " << sim_time / 2 << ": Fibonacci number = " << tb->fib_out << std::endl;
        }
        sim_time++;
    }
}