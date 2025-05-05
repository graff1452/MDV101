// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"
#include "Vtop__Syms.h"

//==========

VL_CTOR_IMP(Vtop) {
    Vtop__Syms* __restrict vlSymsp = __VlSymsp = new Vtop__Syms(this, name());
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vtop::__Vconfigure(Vtop__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vtop::~Vtop() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vtop::_initial__TOP__1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_initial__TOP__1\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    WData/*543:0*/ __Vtemp1[17];
    // Body
    __Vtemp1[0U] = 0x2e747874U;
    __Vtemp1[1U] = 0x696f6e73U;
    __Vtemp1[2U] = 0x72756374U;
    __Vtemp1[3U] = 0x696e7374U;
    __Vtemp1[4U] = 0x746f722fU;
    __Vtemp1[5U] = 0x6e657261U;
    __Vtemp1[6U] = 0x362f6765U;
    __Vtemp1[7U] = 0x6c616231U;
    __Vtemp1[8U] = 0x6b31322fU;
    __Vtemp1[9U] = 0x2f776565U;
    __Vtemp1[0xaU] = 0x56313031U;
    __Vtemp1[0xbU] = 0x702f4d44U;
    __Vtemp1[0xcU] = 0x736b746fU;
    __Vtemp1[0xdU] = 0x6e2f4465U;
    __Vtemp1[0xeU] = 0x2f7a6861U;
    __Vtemp1[0xfU] = 0x686f6d65U;
    __Vtemp1[0x10U] = 0x2fU;
    VL_READMEM_N(true, 16, 256, 0, VL_CVT_PACK_STR_NW(17, __Vtemp1)
                 , vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__memory_unit__DOT__memory_cell
                 , 0, ~0ULL);
}

void Vtop::_settle__TOP__4(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_settle__TOP__4\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_next_state 
        = ((2U & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state))
            ? ((1U & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state))
                ? 0U : 3U) : ((1U & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state))
                               ? 2U : 1U));
    vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_done = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((2U & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state))) {
            if ((1U & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_done = 1U;
            }
        }
    }
    vlTOPp->done = vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_done;
}

void Vtop::_eval_initial(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_initial\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__reset = vlTOPp->reset;
}

void Vtop::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::final\n"); );
    // Variables
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vtop::_eval_settle(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_settle\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__4(vlSymsp);
}

void Vtop::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    run = VL_RAND_RESET_I(1);
    done = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<256; ++__Vi0) {
            top__DOT__my_instuction_fetch_unit__DOT__memory_unit__DOT__memory_cell[__Vi0] = VL_RAND_RESET_I(16);
    }}
    top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state = VL_RAND_RESET_I(2);
    top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_next_state = VL_RAND_RESET_I(2);
    top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_done = VL_RAND_RESET_I(1);
}
