#include "verilated.h"
#include "Vkeylock.h"
#include <iostream>

int main(int argc, char **argv)
{
    Verilated::commandArgs(argc, argv);
    Vkeylock* myKeylock = new Vkeylock; // Instantiate the keylock module 

    myKeylock->clk = 0; // Reseting values
    myKeylock->reset = 1;
    myKeylock->eval();
    myKeylock->clk = 1;
    myKeylock->eval();
    myKeylock->clk = 0;
    myKeylock->reset = 0;
    myKeylock->eval();

    int myList1[] = {3, 3, 5, 2, 5, 1}; // Wrong sequence
    for (int i = 0; i < 6; i++) 
    {
        myKeylock->digit = myList1[i];
        myKeylock->clk = 1;
        myKeylock->eval();
        myKeylock->clk = 0;
        myKeylock->eval();
    }

    myKeylock->clk = 1;
    myKeylock->eval();
    myKeylock->clk = 0;
    myKeylock->eval();

    std::cout << "Sequence: 3 3 5 2 5 1, locked = " << (int)myKeylock->locked << std::endl;

    myKeylock->clk = 0; // Reseting values
    myKeylock->reset = 1;
    myKeylock->eval();
    myKeylock->clk = 1;
    myKeylock->eval();
    myKeylock->clk = 0;
    myKeylock->reset = 0;
    myKeylock->eval();

    int myList2[] = {3, 3, 5, 2, 5, 6, 0}; // Accepting sequence
    for (int i = 0; i < 7; i++) 
    {
        myKeylock->digit = myList2[i];
        myKeylock->clk = 1;
        myKeylock->eval();
        myKeylock->clk = 0;
        myKeylock->eval();
    }

    myKeylock->clk = 1;
    myKeylock->eval();
    myKeylock->clk = 0;
    myKeylock->eval();

    std::cout << "Sequence: 3 3 5 2 5 6, locked = " << (int)myKeylock->locked << std::endl;

    myKeylock->clk = 0; // Reseting values
    myKeylock->reset = 1;
    myKeylock->eval();
    myKeylock->clk = 1;
    myKeylock->eval();
    myKeylock->clk = 0;
    myKeylock->reset = 0;
    myKeylock->eval();

    int myList3[] = {3, 3, 5, 2, 5, 3}; // Wrong sequence
    for (int i = 0; i < 6; i++) 
    {
        myKeylock->digit = myList3[i];
        myKeylock->clk = 1;
        myKeylock->eval();
        myKeylock->clk = 0;
        myKeylock->eval();
    }

    myKeylock->clk = 1;
    myKeylock->eval();
    myKeylock->clk = 0;
    myKeylock->eval();

    std::cout << "Sequence: 3 3 5 2 5 3, locked = " << (int)myKeylock->locked << std::endl;

    delete myKeylock;
    return 0;
}