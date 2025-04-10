#include <iostream>
#include "verilated.h"
#include "Vcontrol_unit.h"
#include <cstdlib>
#include <ctime>
#include <bitset>

#define NUM_TESTS 1000000

int main(int argc, char** argv)
{
    Verilated::commandArgs(argc, argv);
    Vcontrol_unit* control_unit = new Vcontrol_unit; // Instantiate control unit

    std::srand(std::time(nullptr));  // Seed for random values

    // Initialize signals
    std::cout << "Starting Control Unit Test with " << NUM_TESTS << " iterations.\n";

    bool test_passed = true;
    int failed_tests = 0;

    for (int test = 0; test < NUM_TESTS; test++)
    {
        // Generate a random 16-bit instruction
        control_unit->instruction = std::rand() & 0xFFFF;

        control_unit->reset = 1;
        control_unit->run = 0;

        // Evaluate with reset active
        control_unit->clk = 0;
        control_unit->eval();
        control_unit->clk = 1;
        control_unit->eval();

        // Take out of reset, keep run=0
        control_unit->reset = 0;
        control_unit->clk = 0;
        control_unit->eval();
        control_unit->clk = 1;
        control_unit->eval();

        if (control_unit->en_i || control_unit->en_s || control_unit->en_c || control_unit->done || 
            control_unit->en_0 || control_unit->en_1 || control_unit->en_2 || control_unit->en_3 || 
            control_unit->en_4 || control_unit->en_5 || control_unit->en_6 || control_unit->en_7) {
            std::cout << "Test " << test << " FAIL: Some outputs active after reset but before run" << std::endl;
            test_passed = false;
            failed_tests++;
        }

        control_unit->clk = 0;
        control_unit->eval();
        control_unit->run = 1;
        control_unit->eval();
        control_unit->clk = 1;
        control_unit->eval();

        // Cicle 1

        if (control_unit->en_s != 0 ||
            control_unit->en_c != 0 ||
            control_unit->en_i != 1 ||
            control_unit->en_0 != 0 ||
            control_unit->en_1 != 0 ||
            control_unit->en_2 != 0 ||
            control_unit->en_3 != 0 ||
            control_unit->en_4 != 0 ||
            control_unit->en_5 != 0 ||
            control_unit->en_6 != 0 ||
            control_unit->en_7 != 0 ||
            control_unit->sel != 0 ||
            control_unit->mux_sel != 0b1111 ||
            control_unit->done != 0)
        {
            std::cout << "CicleN1: intsruction = " << std::bitset<16>(control_unit->instruction) << std::endl
                      << "\ten_s = " << std::bitset<1>(control_unit->en_s) << ", should be 0" << std::endl
                      << "\ten_c = " << std::bitset<1>(control_unit->en_c) << ", should be 0" << std::endl 
                      << "\ten_i = " << std::bitset<1>(control_unit->en_i) << ", should be 1" << std::endl 
                      << "\ten_0 = " << std::bitset<1>(control_unit->en_0) << ", should be 0" << std::endl 
                      << "\ten_1 = " << std::bitset<1>(control_unit->en_1) << ", should be 0" << std::endl 
                      << "\ten_2 = " << std::bitset<1>(control_unit->en_2) << ", should be 0" << std::endl 
                      << "\ten_3 = " << std::bitset<1>(control_unit->en_3) << ", should be 0" << std::endl 
                      << "\ten_4 = " << std::bitset<1>(control_unit->en_4) << ", should be 0" << std::endl 
                      << "\ten_5 = " << std::bitset<1>(control_unit->en_5) << ", should be 0" << std::endl 
                      << "\ten_6 = " << std::bitset<1>(control_unit->en_6) << ", should be 0" << std::endl 
                      << "\ten_7 = " << std::bitset<1>(control_unit->en_7) << ", should be 0" << std::endl 
                      << "\tsel = " << std::bitset<3>(control_unit->sel) << ", should be 0" << std::endl 
                      << "\tmux_sel = " << std::bitset<4>(control_unit->mux_sel) << ", should be 0" << std::endl 
                      << "\tdone = " << std::bitset<1>(control_unit->done) << ", should be 0" << std::endl << std::endl;
        }

        // Cicle 2

        control_unit->clk = 0;
        control_unit->eval();
        control_unit->clk = 1;
        control_unit->eval();

        if (control_unit->en_s != 1 ||
            control_unit->en_c != 0 ||
            control_unit->en_i != 0 ||
            control_unit->en_0 != 0 ||
            control_unit->en_1 != 0 ||
            control_unit->en_2 != 0 ||
            control_unit->en_3 != 0 ||
            control_unit->en_4 != 0 ||
            control_unit->en_5 != 0 ||
            control_unit->en_6 != 0 ||
            control_unit->en_7 != 0 ||
            control_unit->sel != 0 ||
            ((control_unit->mux_sel & 0b111) != (((control_unit->instruction) >> 13) & 0b111)) ||
            control_unit->done != 0)
        {
            std::cout << "CicleN2: intsruction = " << std::bitset<16>(control_unit->instruction) << std::endl
                      << "\ten_s = " << std::bitset<1>(control_unit->en_s) << ", should be 1" << std::endl
                      << "\ten_c = " << std::bitset<1>(control_unit->en_c) << ", should be 0" << std::endl 
                      << "\ten_i = " << std::bitset<1>(control_unit->en_i) << ", should be 0" << std::endl 
                      << "\ten_0 = " << std::bitset<1>(control_unit->en_0) << ", should be 0" << std::endl 
                      << "\ten_1 = " << std::bitset<1>(control_unit->en_1) << ", should be 0" << std::endl 
                      << "\ten_2 = " << std::bitset<1>(control_unit->en_2) << ", should be 0" << std::endl 
                      << "\ten_3 = " << std::bitset<1>(control_unit->en_3) << ", should be 0" << std::endl 
                      << "\ten_4 = " << std::bitset<1>(control_unit->en_4) << ", should be 0" << std::endl 
                      << "\ten_5 = " << std::bitset<1>(control_unit->en_5) << ", should be 0" << std::endl 
                      << "\ten_6 = " << std::bitset<1>(control_unit->en_6) << ", should be 0" << std::endl 
                      << "\ten_7 = " << std::bitset<1>(control_unit->en_7) << ", should be 0" << std::endl 
                      << "\tsel = " << std::bitset<3>(control_unit->sel) << ", should be 0" << std::endl 
                      << "\tmux_sel = " << std::bitset<3>(control_unit->mux_sel) << ", should be " << std::bitset<3>(((control_unit->instruction) >> 13) & 0b111) << std::endl 
                      << "\tdone = " << std::bitset<1>(control_unit->done) << ", should be 0" << std::endl << std::endl;
        }

        // Cicle 3
        control_unit->clk = 0;
        control_unit->eval();
        control_unit->clk = 1;
        control_unit->eval();

        if (((((control_unit->instruction) << 14) >> 14) & 0b11) == 0b01) 
        {
            if (control_unit->en_s != 0 ||
                control_unit->en_c != 1 ||
                control_unit->en_i != 0 ||
                control_unit->en_0 != 0 ||
                control_unit->en_1 != 0 ||
                control_unit->en_2 != 0 ||
                control_unit->en_3 != 0 ||
                control_unit->en_4 != 0 ||
                control_unit->en_5 != 0 ||
                control_unit->en_6 != 0 ||
                control_unit->en_7 != 0 ||
                (control_unit->sel & 0b111) != ((((control_unit->instruction) << 11) >> 13) & 0b111) ||
                (((control_unit->mux_sel & 0b1111) != 0b1000)) ||
                control_unit->done != 0)
                {
                    std::cout << "CicleN3: intsruction = " << std::bitset<16>(control_unit->instruction) << std::endl
                              << "\ten_s = " << std::bitset<1>(control_unit->en_s) << ", should be 0" << std::endl
                              << "\ten_c = " << std::bitset<1>(control_unit->en_c) << ", should be 1" << std::endl
                              << "\ten_i = " << std::bitset<1>(control_unit->en_i) << ", should be 0" << std::endl
                              << "\ten_0 = " << std::bitset<1>(control_unit->en_0) << ", should be 0" << std::endl
                              << "\ten_1 = " << std::bitset<1>(control_unit->en_1) << ", should be 0" << std::endl
                              << "\ten_2 = " << std::bitset<1>(control_unit->en_2) << ", should be 0" << std::endl
                              << "\ten_3 = " << std::bitset<1>(control_unit->en_3) << ", should be 0" << std::endl
                              << "\ten_4 = " << std::bitset<1>(control_unit->en_4) << ", should be 0" << std::endl
                              << "\ten_5 = " << std::bitset<1>(control_unit->en_5) << ", should be 0" << std::endl
                              << "\ten_6 = " << std::bitset<1>(control_unit->en_6) << ", should be 0" << std::endl
                              << "\ten_7 = " << std::bitset<1>(control_unit->en_7) << ", should be 0" << std::endl
                              << "\tsel = " << std::bitset<3>(control_unit->sel) << ", should be " << std::bitset<3>((((control_unit->instruction) << 11) >> 13) & 0b111) << std::endl 
                              << "\tmux_sel = " << std::bitset<3>(control_unit->mux_sel) << ", should be 1000" << std::endl 
                              << "\tdone = " << std::bitset<1>(control_unit->done) << ", should be 0" << std::endl << std::endl;
                }
        } 
        else 
        {
            if (control_unit->en_s != 0 ||
                control_unit->en_c != 1 ||
                control_unit->en_i != 0 ||
                control_unit->en_0 != 0 ||
                control_unit->en_1 != 0 ||
                control_unit->en_2 != 0 ||
                control_unit->en_3 != 0 ||
                control_unit->en_4 != 0 ||
                control_unit->en_5 != 0 ||
                control_unit->en_6 != 0 ||
                control_unit->en_7 != 0 ||
                (control_unit->sel & 0b111) != ((((control_unit->instruction) << 11) >> 13) & 0b111) ||
                ((control_unit->mux_sel & 0b111) != ((((control_unit->instruction) << 3) >> 13) & 0b111) && ((control_unit->mux_sel & 0b1111) != 0b1000)) ||
                control_unit->done != 0)
            {
                std::cout << "CicleN3: intsruction = " << std::bitset<16>(control_unit->instruction) << std::endl
                          << "\ten_s = " << std::bitset<1>(control_unit->en_s) << ", should be 0" << std::endl
                          << "\ten_c = " << std::bitset<1>(control_unit->en_c) << ", should be 1" << std::endl
                          << "\ten_i = " << std::bitset<1>(control_unit->en_i) << ", should be 0" << std::endl
                          << "\ten_0 = " << std::bitset<1>(control_unit->en_0) << ", should be 0" << std::endl
                          << "\ten_1 = " << std::bitset<1>(control_unit->en_1) << ", should be 0" << std::endl
                          << "\ten_2 = " << std::bitset<1>(control_unit->en_2) << ", should be 0" << std::endl
                          << "\ten_3 = " << std::bitset<1>(control_unit->en_3) << ", should be 0" << std::endl
                          << "\ten_4 = " << std::bitset<1>(control_unit->en_4) << ", should be 0" << std::endl
                          << "\ten_5 = " << std::bitset<1>(control_unit->en_5) << ", should be 0" << std::endl
                          << "\ten_6 = " << std::bitset<1>(control_unit->en_6) << ", should be 0" << std::endl
                          << "\ten_7 = " << std::bitset<1>(control_unit->en_7) << ", should be 0" << std::endl
                          << "\tsel = " << std::bitset<3>(control_unit->sel) << ", should be " << std::bitset<3>((((control_unit->instruction) << 11) >> 13) & 0b111) << std::endl 
                          << "\tmux_sel = " << std::bitset<3>(control_unit->mux_sel) << ", should be " << std::bitset<3>((((control_unit->instruction) << 3) >> 13) & 0b111) << std::endl 
                          << "\tdone = " << std::bitset<1>(control_unit->done) << ", should be 0" << std::endl << std::endl;
            }
        }

        // Cicle 4
        control_unit->clk = 0;
        control_unit->eval();
        control_unit->clk = 1;
        control_unit->eval();

        switch ((control_unit->instruction >> 13) & 0b111)
        {
        case 0b000:
            if ((control_unit->en_0) != 1) 
            {
                std::cout << "CicleN4: intsruction = " << std::bitset<16>(control_unit->instruction) << std::endl 
                          << "\ten_0 = " << std::bitset<1>(control_unit->en_0) << ", should be 1" << std::endl;
            }
            break;
        case 0b001:
            if ((control_unit->en_1) != 1) 
            {
                std::cout << "CicleN4: intsruction = " << std::bitset<16>(control_unit->instruction) << std::endl 
                          << "\ten_1 = " << std::bitset<1>(control_unit->en_0) << ", should be 1" << std::endl;
            }
            break;
        case 0b010:
            if ((control_unit->en_2) != 1)
            {
                std::cout << "CicleN4: intsruction = " << std::bitset<16>(control_unit->instruction) << std::endl 
                          << "\ten_2 = " << std::bitset<1>(control_unit->en_0) << ", should be 1" << std::endl;
            }
            break;
        case 0b011:
            if ((control_unit->en_3) != 1)
            {
                std::cout << "CicleN4: intsruction = " << std::bitset<16>(control_unit->instruction) << std::endl 
                          << "\ten_3 = " << std::bitset<1>(control_unit->en_0) << ", should be 1" << std::endl;
            }
            break;
        case 0b100:
            if ((control_unit->en_4) != 1)
            {
                std::cout << "CicleN4: intsruction = " << std::bitset<16>(control_unit->instruction) << std::endl 
                          << "\ten_4 = " << std::bitset<1>(control_unit->en_0) << ", should be 1" << std::endl;
            }
            break;
        case 0b101:
            if ((control_unit->en_5) != 1)
            {
                std::cout << "CicleN4: intsruction = " << std::bitset<16>(control_unit->instruction) << std::endl 
                          << "\ten_5 = " << std::bitset<1>(control_unit->en_0) << ", should be 1" << std::endl;
            }
            break;
        case 0b110:
            if ((control_unit->en_6) != 1)
            {
                std::cout << "CicleN4: intsruction = " << std::bitset<16>(control_unit->instruction) << std::endl 
                          << "\ten_6 = " << std::bitset<1>(control_unit->en_0) << ", should be 1" << std::endl;
            }
            break;
        case 0b111:
            if ((control_unit->en_7) != 1)
            {
                std::cout << "CicleN4: intsruction = " << std::bitset<16>(control_unit->instruction) << std::endl 
                          << "\ten_7 = " << std::bitset<1>(control_unit->en_0) << ", should be 1" << std::endl;
            }
            break;
        default:
            std::cout << "Something went off testign cycle 4" << std::endl;
            break;
        }

        if (control_unit->sel != 0 ||
            control_unit->mux_sel != 0b1111 ||
            control_unit->done != 1
        )
        {
            std::cout << "\ten_s = " << std::bitset<1>(control_unit->en_s) << ", should be 0" << std::endl
                      << "\ten_c = " << std::bitset<1>(control_unit->en_c) << ", should be 0" << std::endl 
                      << "\ten_i = " << std::bitset<1>(control_unit->en_i) << ", should be 0" << std::endl 
                      << "\tsel = " << std::bitset<4>(control_unit->sel) << ", should be 0" << std::endl 
                      << "\tmux_sel = " << std::bitset<3>(control_unit->mux_sel) << ", should be 1111" << std::endl 
                      << "\tdone = " << std::bitset<1>(control_unit->done) << ", should be 1" << std::endl << std::endl;
        }
    }

    std::cout << "control unit Testbench completed." << std::endl;
    delete control_unit;
    return 0;
}
