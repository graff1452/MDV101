// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vkeylock.h for the primary calling header

#include "Vkeylock__pch.h"
#include "Vkeylock__Syms.h"
#include "Vkeylock___024root.h"

void Vkeylock___024root___ctor_var_reset(Vkeylock___024root* vlSelf);

Vkeylock___024root::Vkeylock___024root(Vkeylock__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vkeylock___024root___ctor_var_reset(this);
}

void Vkeylock___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vkeylock___024root::~Vkeylock___024root() {
}
