// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VALU.h for the primary calling header

#include "VALU__pch.h"
#include "VALU___024root.h"

VL_INLINE_OPT void VALU___024root___ico_sequent__TOP__0(VALU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU___024root___ico_sequent__TOP__0\n"); );
    // Init
    SData/*15:0*/ ALU__DOT__Logic_LoOut;
    ALU__DOT__Logic_LoOut = 0;
    IData/*16:0*/ ALU__DOT__myArithmetic__DOT__result;
    ALU__DOT__myArithmetic__DOT__result = 0;
    // Body
    vlSelf->Cmp = ((~ (IData)(vlSelf->Mode)) & ((IData)(vlSelf->A) 
                                                == (IData)(vlSelf->B)));
    if ((8U & (IData)(vlSelf->Sel))) {
        if ((4U & (IData)(vlSelf->Sel))) {
            if ((2U & (IData)(vlSelf->Sel))) {
                if ((1U & (IData)(vlSelf->Sel))) {
                    ALU__DOT__Logic_LoOut = (0xffffU 
                                             & (IData)(vlSelf->A));
                    ALU__DOT__myArithmetic__DOT__result 
                        = (0x1ffffU & (((IData)(vlSelf->A) 
                                        - (IData)(1U)) 
                                       + (IData)(vlSelf->CIn)));
                } else {
                    ALU__DOT__Logic_LoOut = (0xffffU 
                                             & ((IData)(vlSelf->A) 
                                                | (IData)(vlSelf->B)));
                    ALU__DOT__myArithmetic__DOT__result 
                        = (0x1ffffU & ((((IData)(vlSelf->A) 
                                         | (~ (IData)(vlSelf->B))) 
                                        + (IData)(vlSelf->A)) 
                                       + (IData)(vlSelf->CIn)));
                }
            } else if ((1U & (IData)(vlSelf->Sel))) {
                ALU__DOT__Logic_LoOut = (0xffffU & 
                                         ((IData)(vlSelf->A) 
                                          | (~ (IData)(vlSelf->B))));
                ALU__DOT__myArithmetic__DOT__result 
                    = (0x1ffffU & ((((IData)(vlSelf->A) 
                                     | (IData)(vlSelf->B)) 
                                    + (IData)(vlSelf->A)) 
                                   + (IData)(vlSelf->CIn)));
            } else {
                ALU__DOT__Logic_LoOut = (0xffffU & 0xffffU);
                ALU__DOT__myArithmetic__DOT__result 
                    = (0x1ffffU & (((IData)(vlSelf->A) 
                                    + (IData)(vlSelf->A)) 
                                   + (IData)(vlSelf->CIn)));
            }
        } else if ((2U & (IData)(vlSelf->Sel))) {
            if ((1U & (IData)(vlSelf->Sel))) {
                ALU__DOT__Logic_LoOut = (0xffffU & 
                                         ((IData)(vlSelf->A) 
                                          & (IData)(vlSelf->B)));
                ALU__DOT__myArithmetic__DOT__result 
                    = (0x1ffffU & ((((IData)(vlSelf->A) 
                                     & (IData)(vlSelf->B)) 
                                    - (IData)(1U)) 
                                   + (IData)(vlSelf->CIn)));
            } else {
                ALU__DOT__Logic_LoOut = (0xffffU & (IData)(vlSelf->B));
                ALU__DOT__myArithmetic__DOT__result 
                    = (0x1ffffU & ((((IData)(vlSelf->A) 
                                     | (~ (IData)(vlSelf->B))) 
                                    + ((IData)(vlSelf->A) 
                                       & (IData)(vlSelf->B))) 
                                   + (IData)(vlSelf->CIn)));
            }
        } else if ((1U & (IData)(vlSelf->Sel))) {
            ALU__DOT__Logic_LoOut = (0xffffU & (~ ((IData)(vlSelf->A) 
                                                   ^ (IData)(vlSelf->B))));
            ALU__DOT__myArithmetic__DOT__result = (0x1ffffU 
                                                   & (((IData)(vlSelf->A) 
                                                       + (IData)(vlSelf->B)) 
                                                      + (IData)(vlSelf->CIn)));
        } else {
            ALU__DOT__Logic_LoOut = (0xffffU & ((~ (IData)(vlSelf->A)) 
                                                | (IData)(vlSelf->B)));
            ALU__DOT__myArithmetic__DOT__result = (0x1ffffU 
                                                   & (((IData)(vlSelf->A) 
                                                       + 
                                                       ((IData)(vlSelf->A) 
                                                        & (IData)(vlSelf->B))) 
                                                      + (IData)(vlSelf->CIn)));
        }
    } else if ((4U & (IData)(vlSelf->Sel))) {
        if ((2U & (IData)(vlSelf->Sel))) {
            if ((1U & (IData)(vlSelf->Sel))) {
                ALU__DOT__Logic_LoOut = (0xffffU & 
                                         ((IData)(vlSelf->A) 
                                          & (~ (IData)(vlSelf->B))));
                ALU__DOT__myArithmetic__DOT__result 
                    = (0x1ffffU & ((((IData)(vlSelf->A) 
                                     & (~ (IData)(vlSelf->B))) 
                                    - (IData)(1U)) 
                                   + (IData)(vlSelf->CIn)));
            } else {
                ALU__DOT__Logic_LoOut = (0xffffU & 
                                         ((IData)(vlSelf->A) 
                                          ^ (IData)(vlSelf->B)));
                ALU__DOT__myArithmetic__DOT__result 
                    = (0x1ffffU & ((((IData)(vlSelf->A) 
                                     - (IData)(vlSelf->B)) 
                                    - (IData)(1U)) 
                                   + (IData)(vlSelf->CIn)));
            }
        } else if ((1U & (IData)(vlSelf->Sel))) {
            ALU__DOT__Logic_LoOut = (0xffffU & (~ (IData)(vlSelf->B)));
            ALU__DOT__myArithmetic__DOT__result = (0x1ffffU 
                                                   & ((((IData)(vlSelf->A) 
                                                        | (IData)(vlSelf->B)) 
                                                       + 
                                                       ((IData)(vlSelf->A) 
                                                        & (~ (IData)(vlSelf->B)))) 
                                                      + (IData)(vlSelf->CIn)));
        } else {
            ALU__DOT__Logic_LoOut = (0xffffU & (~ ((IData)(vlSelf->A) 
                                                   & (IData)(vlSelf->B))));
            ALU__DOT__myArithmetic__DOT__result = (0x1ffffU 
                                                   & ((IData)(vlSelf->A) 
                                                      | ((~ (IData)(vlSelf->B)) 
                                                         & (IData)(vlSelf->A))));
        }
    } else if ((2U & (IData)(vlSelf->Sel))) {
        if ((1U & (IData)(vlSelf->Sel))) {
            ALU__DOT__Logic_LoOut = (0xffffU & 0U);
            ALU__DOT__myArithmetic__DOT__result = (0x1ffffU 
                                                   & 0xffffU);
        } else {
            ALU__DOT__Logic_LoOut = (0xffffU & ((~ (IData)(vlSelf->A)) 
                                                & (IData)(vlSelf->B)));
            ALU__DOT__myArithmetic__DOT__result = (0x1ffffU 
                                                   & ((~ (IData)(vlSelf->B)) 
                                                      | (IData)(vlSelf->A)));
        }
    } else if ((1U & (IData)(vlSelf->Sel))) {
        ALU__DOT__Logic_LoOut = (0xffffU & (~ ((IData)(vlSelf->A) 
                                               | (IData)(vlSelf->B))));
        ALU__DOT__myArithmetic__DOT__result = (0x1ffffU 
                                               & ((IData)(vlSelf->A) 
                                                  | (IData)(vlSelf->B)));
    } else {
        ALU__DOT__Logic_LoOut = (0xffffU & (~ (IData)(vlSelf->A)));
        ALU__DOT__myArithmetic__DOT__result = (0x1ffffU 
                                               & (IData)(vlSelf->A));
    }
    vlSelf->COut = ((~ (IData)(vlSelf->Mode)) & (ALU__DOT__myArithmetic__DOT__result 
                                                 >> 0x10U));
    vlSelf->ALUOut = (0xffffU & ((IData)(vlSelf->Mode)
                                  ? (IData)(ALU__DOT__Logic_LoOut)
                                  : ALU__DOT__myArithmetic__DOT__result));
}

void VALU___024root___eval_ico(VALU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VALU___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void VALU___024root___eval_triggers__ico(VALU___024root* vlSelf);

bool VALU___024root___eval_phase__ico(VALU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    VALU___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        VALU___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void VALU___024root___eval_act(VALU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU___024root___eval_act\n"); );
}

void VALU___024root___eval_nba(VALU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU___024root___eval_nba\n"); );
}

void VALU___024root___eval_triggers__act(VALU___024root* vlSelf);

bool VALU___024root___eval_phase__act(VALU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<0> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    VALU___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        VALU___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool VALU___024root___eval_phase__nba(VALU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        VALU___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VALU___024root___dump_triggers__ico(VALU___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VALU___024root___dump_triggers__nba(VALU___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VALU___024root___dump_triggers__act(VALU___024root* vlSelf);
#endif  // VL_DEBUG

void VALU___024root___eval(VALU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelf->__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            VALU___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("ALU.v", 68, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (VALU___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            VALU___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("ALU.v", 68, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                VALU___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("ALU.v", 68, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (VALU___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (VALU___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void VALU___024root___eval_debug_assertions(VALU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->CIn & 0xfeU))) {
        Verilated::overWidthError("CIn");}
    if (VL_UNLIKELY((vlSelf->Sel & 0xf0U))) {
        Verilated::overWidthError("Sel");}
    if (VL_UNLIKELY((vlSelf->Mode & 0xfeU))) {
        Verilated::overWidthError("Mode");}
}
#endif  // VL_DEBUG
