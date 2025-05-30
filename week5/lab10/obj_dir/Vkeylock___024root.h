// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vkeylock.h for the primary calling header

#ifndef VERILATED_VKEYLOCK___024ROOT_H_
#define VERILATED_VKEYLOCK___024ROOT_H_  // guard

#include "verilated.h"


class Vkeylock__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vkeylock___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(digit,3,0);
    VL_OUT8(locked,0,0);
    CData/*2:0*/ keylock__DOT__current_state;
    CData/*2:0*/ keylock__DOT__next_state;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__reset__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vkeylock__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vkeylock___024root(Vkeylock__Syms* symsp, const char* v__name);
    ~Vkeylock___024root();
    VL_UNCOPYABLE(Vkeylock___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
