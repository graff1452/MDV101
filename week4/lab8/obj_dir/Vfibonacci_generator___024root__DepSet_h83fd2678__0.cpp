// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfibonacci_generator.h for the primary calling header

#include "Vfibonacci_generator__pch.h"
#include "Vfibonacci_generator___024root.h"

void Vfibonacci_generator___024root___eval_act(Vfibonacci_generator___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfibonacci_generator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfibonacci_generator___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vfibonacci_generator___024root___nba_sequent__TOP__0(Vfibonacci_generator___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfibonacci_generator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfibonacci_generator___024root___nba_sequent__TOP__0\n"); );
    // Init
    IData/*31:0*/ __Vdly__fibonacci_generator__DOT__fib_prev;
    __Vdly__fibonacci_generator__DOT__fib_prev = 0;
    IData/*31:0*/ __Vdly__fib_out;
    __Vdly__fib_out = 0;
    // Body
    __Vdly__fib_out = vlSelf->fib_out;
    __Vdly__fibonacci_generator__DOT__fib_prev = vlSelf->fibonacci_generator__DOT__fib_prev;
    if (vlSelf->rst) {
        __Vdly__fibonacci_generator__DOT__fib_prev = 0U;
        __Vdly__fib_out = 0U;
        vlSelf->fibonacci_generator__DOT__fib_curr = 1U;
    } else if (vlSelf->enable) {
        __Vdly__fib_out = (vlSelf->fibonacci_generator__DOT__fib_curr 
                           + vlSelf->fibonacci_generator__DOT__fib_prev);
        __Vdly__fibonacci_generator__DOT__fib_prev 
            = vlSelf->fibonacci_generator__DOT__fib_curr;
        vlSelf->fibonacci_generator__DOT__fib_curr 
            = vlSelf->fib_out;
    }
    vlSelf->fibonacci_generator__DOT__fib_prev = __Vdly__fibonacci_generator__DOT__fib_prev;
    vlSelf->fib_out = __Vdly__fib_out;
}

void Vfibonacci_generator___024root___eval_nba(Vfibonacci_generator___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfibonacci_generator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfibonacci_generator___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vfibonacci_generator___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vfibonacci_generator___024root___eval_triggers__act(Vfibonacci_generator___024root* vlSelf);

bool Vfibonacci_generator___024root___eval_phase__act(Vfibonacci_generator___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfibonacci_generator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfibonacci_generator___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vfibonacci_generator___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vfibonacci_generator___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vfibonacci_generator___024root___eval_phase__nba(Vfibonacci_generator___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfibonacci_generator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfibonacci_generator___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vfibonacci_generator___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfibonacci_generator___024root___dump_triggers__nba(Vfibonacci_generator___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vfibonacci_generator___024root___dump_triggers__act(Vfibonacci_generator___024root* vlSelf);
#endif  // VL_DEBUG

void Vfibonacci_generator___024root___eval(Vfibonacci_generator___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfibonacci_generator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfibonacci_generator___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vfibonacci_generator___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("fibonacci_generator.v", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vfibonacci_generator___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("fibonacci_generator.v", 1, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vfibonacci_generator___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vfibonacci_generator___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vfibonacci_generator___024root___eval_debug_assertions(Vfibonacci_generator___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfibonacci_generator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfibonacci_generator___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->enable & 0xfeU))) {
        Verilated::overWidthError("enable");}
}
#endif  // VL_DEBUG
