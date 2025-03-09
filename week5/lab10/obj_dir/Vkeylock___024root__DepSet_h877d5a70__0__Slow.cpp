// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vkeylock.h for the primary calling header

#include "Vkeylock__pch.h"
#include "Vkeylock___024root.h"

VL_ATTR_COLD void Vkeylock___024root___eval_static(Vkeylock___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vkeylock__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkeylock___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vkeylock___024root___eval_initial(Vkeylock___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vkeylock__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkeylock___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
    vlSelf->__Vtrigprevexpr___TOP__reset__0 = vlSelf->reset;
}

VL_ATTR_COLD void Vkeylock___024root___eval_final(Vkeylock___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vkeylock__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkeylock___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vkeylock___024root___dump_triggers__stl(Vkeylock___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vkeylock___024root___eval_phase__stl(Vkeylock___024root* vlSelf);

VL_ATTR_COLD void Vkeylock___024root___eval_settle(Vkeylock___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vkeylock__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkeylock___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vkeylock___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("keylock.v", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vkeylock___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vkeylock___024root___dump_triggers__stl(Vkeylock___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vkeylock__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkeylock___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void Vkeylock___024root___ico_sequent__TOP__0(Vkeylock___024root* vlSelf);

VL_ATTR_COLD void Vkeylock___024root___eval_stl(Vkeylock___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vkeylock__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkeylock___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vkeylock___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vkeylock___024root___eval_triggers__stl(Vkeylock___024root* vlSelf);

VL_ATTR_COLD bool Vkeylock___024root___eval_phase__stl(Vkeylock___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vkeylock__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkeylock___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vkeylock___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vkeylock___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vkeylock___024root___dump_triggers__ico(Vkeylock___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vkeylock__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkeylock___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vkeylock___024root___dump_triggers__act(Vkeylock___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vkeylock__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkeylock___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk or posedge reset)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vkeylock___024root___dump_triggers__nba(Vkeylock___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vkeylock__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkeylock___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk or posedge reset)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vkeylock___024root___ctor_var_reset(Vkeylock___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vkeylock__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkeylock___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->reset = VL_RAND_RESET_I(1);
    vlSelf->digit = VL_RAND_RESET_I(4);
    vlSelf->locked = VL_RAND_RESET_I(1);
    vlSelf->keylock__DOT__current_state = VL_RAND_RESET_I(3);
    vlSelf->keylock__DOT__next_state = VL_RAND_RESET_I(3);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__reset__0 = VL_RAND_RESET_I(1);
}
