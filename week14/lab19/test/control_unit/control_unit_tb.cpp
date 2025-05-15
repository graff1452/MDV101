#include <iostream>
#include "verilated.h"
#include "Vcontrol_unit.h"
#include <cstdlib>
#include <ctime>
#include <bitset>
#include <cstdint>

#define NUM_TESTS 1

int main(int argc, char** argv)
{
    Verilated::commandArgs(argc, argv);
    Vcontrol_unit* control_unit = new Vcontrol_unit; // Instantiate control unit

    std::srand(std::time(nullptr));  // Seed for random values

    // Initialize signals
    std::cout << "Starting Control Unit Test with " << NUM_TESTS << " iterations.\n";

    control_unit->run = 1;

    control_unit->reset = 0;
    control_unit->eval();
    control_unit->reset = 1;
    control_unit->eval();
    control_unit->reset = 0;
    control_unit->eval();
    control_unit->instruction = 0b0000010000000011;

    for (int test = 0; test < NUM_TESTS; test++)
    {
        control_unit->clk = 0;
        control_unit->eval();
        control_unit->clk = 1;
        control_unit->eval();
        std::cout << "Test#"                << test << ", Cycle#1:" << std::endl;
        std::cout << "en_s = "                  << std::bitset<1>(control_unit->en_s)               << std::endl;
        std::cout << "en_c = "                  << std::bitset<1>(control_unit->en_c)               << std::endl;
        std::cout << "en_i = "                  << std::bitset<1>(control_unit->en_i)               << std::endl;
        std::cout << "en_0 = "                  << std::bitset<1>(control_unit->en_0)               << std::endl;
        std::cout << "en_1 = "                  << std::bitset<1>(control_unit->en_1)               << std::endl;
        std::cout << "en_2 = "                  << std::bitset<1>(control_unit->en_2)               << std::endl;
        std::cout << "en_3 = "                  << std::bitset<1>(control_unit->en_3)               << std::endl;
        std::cout << "en_4 = "                  << std::bitset<1>(control_unit->en_4)               << std::endl;
        std::cout << "en_5 = "                  << std::bitset<1>(control_unit->en_5)               << std::endl;
        std::cout << "en_6 = "                  << std::bitset<1>(control_unit->en_6)               << std::endl;
        std::cout << "en_7 = "                  << std::bitset<1>(control_unit->en_7)               << std::endl;
        std::cout << "sel = "                   << std::bitset<3>(control_unit->sel)                << std::endl;
        std::cout << "mux_sel = "               << std::bitset<4>(control_unit->mux_sel)            << std::endl;
        std::cout << "done1 = "                 << std::bitset<1>(control_unit->done1)              << std::endl;
        std::cout << "done2 = "                 << std::bitset<1>(control_unit->done2)              << std::endl;
        std::cout << "imm_val = "               << std::bitset<16>(control_unit->imm_val)           << std::endl;
        std::cout << "en_register_memory = "    << std::bitset<1>(control_unit->en_register_memory) << std::endl;
        std::cout << "mux2_sel = "              << std::bitset<1>(control_unit->mux2_sel)           << std::endl;
        std::cout << "en_m = "                  << std::bitset<1>(control_unit->en_m)               << std::endl << std::endl;

        control_unit->clk = 0;
        control_unit->eval();
        control_unit->clk = 1;
        control_unit->eval();
        std::cout << "Test#"        << test << ", Cycle#2:" << std::endl;
        std::cout << "en_s = "                  << std::bitset<1>(control_unit->en_s)               << std::endl;
        std::cout << "en_c = "                  << std::bitset<1>(control_unit->en_c)               << std::endl;
        std::cout << "en_i = "                  << std::bitset<1>(control_unit->en_i)               << std::endl;
        std::cout << "en_0 = "                  << std::bitset<1>(control_unit->en_0)               << std::endl;
        std::cout << "en_1 = "                  << std::bitset<1>(control_unit->en_1)               << std::endl;
        std::cout << "en_2 = "                  << std::bitset<1>(control_unit->en_2)               << std::endl;
        std::cout << "en_3 = "                  << std::bitset<1>(control_unit->en_3)               << std::endl;
        std::cout << "en_4 = "                  << std::bitset<1>(control_unit->en_4)               << std::endl;
        std::cout << "en_5 = "                  << std::bitset<1>(control_unit->en_5)               << std::endl;
        std::cout << "en_6 = "                  << std::bitset<1>(control_unit->en_6)               << std::endl;
        std::cout << "en_7 = "                  << std::bitset<1>(control_unit->en_7)               << std::endl;
        std::cout << "sel = "                   << std::bitset<3>(control_unit->sel)                << std::endl;
        std::cout << "mux_sel = "               << std::bitset<4>(control_unit->mux_sel)            << std::endl;
        std::cout << "done1 = "                 << std::bitset<1>(control_unit->done1)              << std::endl;
        std::cout << "done2 = "                 << std::bitset<1>(control_unit->done2)              << std::endl;
        std::cout << "imm_val = "               << std::bitset<16>(control_unit->imm_val)           << std::endl;
        std::cout << "en_register_memory = "    << std::bitset<1>(control_unit->en_register_memory) << std::endl;
        std::cout << "mux2_sel = "              << std::bitset<1>(control_unit->mux2_sel)           << std::endl;
        std::cout << "en_m = "                  << std::bitset<1>(control_unit->en_m)               << std::endl << std::endl;

        control_unit->clk = 0;
        control_unit->eval();
        control_unit->clk = 1;
        control_unit->eval();
        std::cout << "Test#"        << test << ", Cycle#3:" << std::endl;
        std::cout << "en_s = "                  << std::bitset<1>(control_unit->en_s)               << std::endl;
        std::cout << "en_c = "                  << std::bitset<1>(control_unit->en_c)               << std::endl;
        std::cout << "en_i = "                  << std::bitset<1>(control_unit->en_i)               << std::endl;
        std::cout << "en_0 = "                  << std::bitset<1>(control_unit->en_0)               << std::endl;
        std::cout << "en_1 = "                  << std::bitset<1>(control_unit->en_1)               << std::endl;
        std::cout << "en_2 = "                  << std::bitset<1>(control_unit->en_2)               << std::endl;
        std::cout << "en_3 = "                  << std::bitset<1>(control_unit->en_3)               << std::endl;
        std::cout << "en_4 = "                  << std::bitset<1>(control_unit->en_4)               << std::endl;
        std::cout << "en_5 = "                  << std::bitset<1>(control_unit->en_5)               << std::endl;
        std::cout << "en_6 = "                  << std::bitset<1>(control_unit->en_6)               << std::endl;
        std::cout << "en_7 = "                  << std::bitset<1>(control_unit->en_7)               << std::endl;
        std::cout << "sel = "                   << std::bitset<3>(control_unit->sel)                << std::endl;
        std::cout << "mux_sel = "               << std::bitset<4>(control_unit->mux_sel)            << std::endl;
        std::cout << "done1 = "                 << std::bitset<1>(control_unit->done1)              << std::endl;
        std::cout << "done2 = "                 << std::bitset<1>(control_unit->done2)              << std::endl;
        std::cout << "imm_val = "               << std::bitset<16>(control_unit->imm_val)           << std::endl;
        std::cout << "en_register_memory = "    << std::bitset<1>(control_unit->en_register_memory) << std::endl;
        std::cout << "mux2_sel = "              << std::bitset<1>(control_unit->mux2_sel)           << std::endl;
        std::cout << "en_m = "                  << std::bitset<1>(control_unit->en_m)               << std::endl << std::endl;

        control_unit->clk = 0;
        control_unit->eval();
        control_unit->clk = 1;
        control_unit->eval();
        std::cout << "Test#"        << test << ", Cycle#4:" << std::endl;
        std::cout << "en_s = "                  << std::bitset<1>(control_unit->en_s)               << std::endl;
        std::cout << "en_c = "                  << std::bitset<1>(control_unit->en_c)               << std::endl;
        std::cout << "en_i = "                  << std::bitset<1>(control_unit->en_i)               << std::endl;
        std::cout << "en_0 = "                  << std::bitset<1>(control_unit->en_0)               << std::endl;
        std::cout << "en_1 = "                  << std::bitset<1>(control_unit->en_1)               << std::endl;
        std::cout << "en_2 = "                  << std::bitset<1>(control_unit->en_2)               << std::endl;
        std::cout << "en_3 = "                  << std::bitset<1>(control_unit->en_3)               << std::endl;
        std::cout << "en_4 = "                  << std::bitset<1>(control_unit->en_4)               << std::endl;
        std::cout << "en_5 = "                  << std::bitset<1>(control_unit->en_5)               << std::endl;
        std::cout << "en_6 = "                  << std::bitset<1>(control_unit->en_6)               << std::endl;
        std::cout << "en_7 = "                  << std::bitset<1>(control_unit->en_7)               << std::endl;
        std::cout << "sel = "                   << std::bitset<3>(control_unit->sel)                << std::endl;
        std::cout << "mux_sel = "               << std::bitset<4>(control_unit->mux_sel)            << std::endl;
        std::cout << "done1 = "                 << std::bitset<1>(control_unit->done1)              << std::endl;
        std::cout << "done2 = "                 << std::bitset<1>(control_unit->done2)              << std::endl;
        std::cout << "imm_val = "               << std::bitset<16>(control_unit->imm_val)           << std::endl;
        std::cout << "en_register_memory = "    << std::bitset<1>(control_unit->en_register_memory) << std::endl;
        std::cout << "mux2_sel = "              << std::bitset<1>(control_unit->mux2_sel)           << std::endl;
        std::cout << "en_m = "                  << std::bitset<1>(control_unit->en_m)               << std::endl << std::endl;

        control_unit->clk = 0;
        control_unit->eval();
        control_unit->clk = 1;
        control_unit->eval();
        std::cout << "Test#"        << test << ", Cycle#5:" << std::endl;
        std::cout << "en_s = "                  << std::bitset<1>(control_unit->en_s)               << std::endl;
        std::cout << "en_c = "                  << std::bitset<1>(control_unit->en_c)               << std::endl;
        std::cout << "en_i = "                  << std::bitset<1>(control_unit->en_i)               << std::endl;
        std::cout << "en_0 = "                  << std::bitset<1>(control_unit->en_0)               << std::endl;
        std::cout << "en_1 = "                  << std::bitset<1>(control_unit->en_1)               << std::endl;
        std::cout << "en_2 = "                  << std::bitset<1>(control_unit->en_2)               << std::endl;
        std::cout << "en_3 = "                  << std::bitset<1>(control_unit->en_3)               << std::endl;
        std::cout << "en_4 = "                  << std::bitset<1>(control_unit->en_4)               << std::endl;
        std::cout << "en_5 = "                  << std::bitset<1>(control_unit->en_5)               << std::endl;
        std::cout << "en_6 = "                  << std::bitset<1>(control_unit->en_6)               << std::endl;
        std::cout << "en_7 = "                  << std::bitset<1>(control_unit->en_7)               << std::endl;
        std::cout << "sel = "                   << std::bitset<3>(control_unit->sel)                << std::endl;
        std::cout << "mux_sel = "               << std::bitset<4>(control_unit->mux_sel)            << std::endl;
        std::cout << "done1 = "                 << std::bitset<1>(control_unit->done1)              << std::endl;
        std::cout << "done2 = "                 << std::bitset<1>(control_unit->done2)              << std::endl;
        std::cout << "imm_val = "               << std::bitset<16>(control_unit->imm_val)           << std::endl;
        std::cout << "en_register_memory = "    << std::bitset<1>(control_unit->en_register_memory) << std::endl;
        std::cout << "mux2_sel = "              << std::bitset<1>(control_unit->mux2_sel)           << std::endl;
        std::cout << "en_m = "                  << std::bitset<1>(control_unit->en_m)               << std::endl << std::endl;

        control_unit->clk = 0;
        control_unit->eval();
        control_unit->clk = 1;
        control_unit->eval();
        std::cout << "Test#"        << test << ", Cycle#6:" << std::endl;
        std::cout << "en_s = "                  << std::bitset<1>(control_unit->en_s)               << std::endl;
        std::cout << "en_c = "                  << std::bitset<1>(control_unit->en_c)               << std::endl;
        std::cout << "en_i = "                  << std::bitset<1>(control_unit->en_i)               << std::endl;
        std::cout << "en_0 = "                  << std::bitset<1>(control_unit->en_0)               << std::endl;
        std::cout << "en_1 = "                  << std::bitset<1>(control_unit->en_1)               << std::endl;
        std::cout << "en_2 = "                  << std::bitset<1>(control_unit->en_2)               << std::endl;
        std::cout << "en_3 = "                  << std::bitset<1>(control_unit->en_3)               << std::endl;
        std::cout << "en_4 = "                  << std::bitset<1>(control_unit->en_4)               << std::endl;
        std::cout << "en_5 = "                  << std::bitset<1>(control_unit->en_5)               << std::endl;
        std::cout << "en_6 = "                  << std::bitset<1>(control_unit->en_6)               << std::endl;
        std::cout << "en_7 = "                  << std::bitset<1>(control_unit->en_7)               << std::endl;
        std::cout << "sel = "                   << std::bitset<3>(control_unit->sel)                << std::endl;
        std::cout << "mux_sel = "               << std::bitset<4>(control_unit->mux_sel)            << std::endl;
        std::cout << "done1 = "                 << std::bitset<1>(control_unit->done1)              << std::endl;
        std::cout << "done2 = "                 << std::bitset<1>(control_unit->done2)              << std::endl;
        std::cout << "imm_val = "               << std::bitset<16>(control_unit->imm_val)           << std::endl;
        std::cout << "en_register_memory = "    << std::bitset<1>(control_unit->en_register_memory) << std::endl;
        std::cout << "mux2_sel = "              << std::bitset<1>(control_unit->mux2_sel)           << std::endl;
        std::cout << "en_m = "                  << std::bitset<1>(control_unit->en_m)               << std::endl << std::endl;
    }

    std::cout << "control unit Testbench completed." << std::endl;
    delete control_unit;
    return 0;
}
