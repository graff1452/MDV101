// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbitty_core.h for the primary calling header

#include "Vbitty_core__pch.h"
#include "Vbitty_core___024root.h"

extern const VlUnpacked<CData/*1:0*/, 16> Vbitty_core__ConstPool__TABLE_h5bf4fed2_0;

VL_INLINE_OPT void Vbitty_core___024root___ico_sequent__TOP__0(Vbitty_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbitty_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core___024root___ico_sequent__TOP__0\n"); );
    // Init
    CData/*0:0*/ bitty_core__DOT__myControlUnit__DOT__reg_done;
    bitty_core__DOT__myControlUnit__DOT__reg_done = 0;
    CData/*3:0*/ bitty_core__DOT__myControlUnit__DOT__reg_mux_sel;
    bitty_core__DOT__myControlUnit__DOT__reg_mux_sel = 0;
    CData/*3:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_i = 0U;
    vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_c = 0U;
    vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_s = 0U;
    vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_sel = 0U;
    vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_7 = 0U;
    vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_6 = 0U;
    vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_5 = 0U;
    vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_4 = 0U;
    vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_3 = 0U;
    vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_2 = 0U;
    vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_1 = 0U;
    vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_0 = 0U;
    bitty_core__DOT__myControlUnit__DOT__reg_done = 0U;
    __Vtableidx1 = (((IData)(vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_run_prev) 
                     << 3U) | (((IData)(vlSelf->run) 
                                << 2U) | (IData)(vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_state)));
    vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_next_state 
        = Vbitty_core__ConstPool__TABLE_h5bf4fed2_0
        [__Vtableidx1];
    bitty_core__DOT__myControlUnit__DOT__reg_mux_sel = 0xfU;
    if (((~ (IData)(vlSelf->reset)) & (IData)(vlSelf->run))) {
        if ((1U & (~ ((IData)(vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_state) 
                      >> 1U)))) {
            if ((1U & (~ (IData)(vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_state)))) {
                vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_i = 1U;
            }
            if ((1U & (IData)(vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_s = 1U;
            }
        }
        if ((2U & (IData)(vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
            if ((1U & (~ (IData)(vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_state)))) {
                vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_c = 1U;
                vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_sel 
                    = (7U & ((IData)(vlSelf->instruction) 
                             >> 2U));
                bitty_core__DOT__myControlUnit__DOT__reg_mux_sel 
                    = (7U & ((IData)(vlSelf->instruction) 
                             >> 0xaU));
            }
            if ((1U & (IData)(vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                if ((0x8000U & (IData)(vlSelf->instruction))) {
                    if ((0x4000U & (IData)(vlSelf->instruction))) {
                        if ((0x2000U & (IData)(vlSelf->instruction))) {
                            vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_7 = 1U;
                        }
                        if ((1U & (~ ((IData)(vlSelf->instruction) 
                                      >> 0xdU)))) {
                            vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_6 = 1U;
                        }
                    }
                    if ((1U & (~ ((IData)(vlSelf->instruction) 
                                  >> 0xeU)))) {
                        if ((0x2000U & (IData)(vlSelf->instruction))) {
                            vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_5 = 1U;
                        }
                        if ((1U & (~ ((IData)(vlSelf->instruction) 
                                      >> 0xdU)))) {
                            vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_4 = 1U;
                        }
                    }
                }
                if ((1U & (~ ((IData)(vlSelf->instruction) 
                              >> 0xfU)))) {
                    if ((0x4000U & (IData)(vlSelf->instruction))) {
                        if ((0x2000U & (IData)(vlSelf->instruction))) {
                            vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_3 = 1U;
                        }
                        if ((1U & (~ ((IData)(vlSelf->instruction) 
                                      >> 0xdU)))) {
                            vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_2 = 1U;
                        }
                    }
                    if ((1U & (~ ((IData)(vlSelf->instruction) 
                                  >> 0xeU)))) {
                        if ((0x2000U & (IData)(vlSelf->instruction))) {
                            vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_1 = 1U;
                        }
                        if ((1U & (~ ((IData)(vlSelf->instruction) 
                                      >> 0xdU)))) {
                            vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_0 = 1U;
                        }
                    }
                }
                bitty_core__DOT__myControlUnit__DOT__reg_done = 1U;
            }
        } else if ((1U & (IData)(vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
            bitty_core__DOT__myControlUnit__DOT__reg_mux_sel 
                = (7U & ((IData)(vlSelf->instruction) 
                         >> 0xdU));
        }
    }
    vlSelf->done = bitty_core__DOT__myControlUnit__DOT__reg_done;
    vlSelf->bitty_core__DOT__myMux__DOT__reg_mux_out 
        = ((8U & (IData)(bitty_core__DOT__myControlUnit__DOT__reg_mux_sel))
            ? ((4U & (IData)(bitty_core__DOT__myControlUnit__DOT__reg_mux_sel))
                ? 0U : ((2U & (IData)(bitty_core__DOT__myControlUnit__DOT__reg_mux_sel))
                         ? 0U : ((1U & (IData)(bitty_core__DOT__myControlUnit__DOT__reg_mux_sel))
                                  ? (IData)(vlSelf->bitty_core__DOT__myMux__DOT__in_9)
                                  : (IData)(vlSelf->bitty_core__DOT__myMux__DOT__in_8))))
            : ((4U & (IData)(bitty_core__DOT__myControlUnit__DOT__reg_mux_sel))
                ? ((2U & (IData)(bitty_core__DOT__myControlUnit__DOT__reg_mux_sel))
                    ? ((1U & (IData)(bitty_core__DOT__myControlUnit__DOT__reg_mux_sel))
                        ? (IData)(vlSelf->Reg_7_Out)
                        : (IData)(vlSelf->Reg_6_Out))
                    : ((1U & (IData)(bitty_core__DOT__myControlUnit__DOT__reg_mux_sel))
                        ? (IData)(vlSelf->Reg_5_Out)
                        : (IData)(vlSelf->Reg_4_Out)))
                : ((2U & (IData)(bitty_core__DOT__myControlUnit__DOT__reg_mux_sel))
                    ? ((1U & (IData)(bitty_core__DOT__myControlUnit__DOT__reg_mux_sel))
                        ? (IData)(vlSelf->Reg_3_Out)
                        : (IData)(vlSelf->Reg_2_Out))
                    : ((1U & (IData)(bitty_core__DOT__myControlUnit__DOT__reg_mux_sel))
                        ? (IData)(vlSelf->Reg_1_Out)
                        : (IData)(vlSelf->Reg_0_Out)))));
}

void Vbitty_core___024root___eval_ico(Vbitty_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbitty_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        Vbitty_core___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vbitty_core___024root___eval_triggers__ico(Vbitty_core___024root* vlSelf);

bool Vbitty_core___024root___eval_phase__ico(Vbitty_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbitty_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vbitty_core___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        Vbitty_core___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vbitty_core___024root___eval_act(Vbitty_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbitty_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vbitty_core___024root___nba_sequent__TOP__0(Vbitty_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbitty_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*0:0*/ bitty_core__DOT__myControlUnit__DOT__reg_done;
    bitty_core__DOT__myControlUnit__DOT__reg_done = 0;
    CData/*3:0*/ bitty_core__DOT__myControlUnit__DOT__reg_mux_sel;
    bitty_core__DOT__myControlUnit__DOT__reg_mux_sel = 0;
    CData/*3:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_run_prev 
        = vlSelf->run;
    if (vlSelf->reset) {
        vlSelf->bitty_core__DOT__Reg_Inst__DOT__reg_d_out = 0U;
        vlSelf->bitty_core__DOT__Reg_S__DOT__reg_d_out = 0U;
        vlSelf->bitty_core__DOT__Reg_C__DOT__reg_d_out = 0U;
        vlSelf->bitty_core__DOT__Reg_7__DOT__reg_d_out = 0U;
        vlSelf->bitty_core__DOT__Reg_6__DOT__reg_d_out = 0U;
        vlSelf->bitty_core__DOT__Reg_5__DOT__reg_d_out = 0U;
        vlSelf->bitty_core__DOT__Reg_4__DOT__reg_d_out = 0U;
        vlSelf->bitty_core__DOT__Reg_3__DOT__reg_d_out = 0U;
        vlSelf->bitty_core__DOT__Reg_2__DOT__reg_d_out = 0U;
        vlSelf->bitty_core__DOT__Reg_1__DOT__reg_d_out = 0U;
        vlSelf->bitty_core__DOT__Reg_0__DOT__reg_d_out = 0U;
        vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_state = 0U;
    } else {
        if (vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_i) {
            vlSelf->bitty_core__DOT__Reg_Inst__DOT__reg_d_out 
                = vlSelf->instruction;
        }
        if (vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_s) {
            vlSelf->bitty_core__DOT__Reg_S__DOT__reg_d_out 
                = vlSelf->bitty_core__DOT__myMux__DOT__reg_mux_out;
        }
        if (vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_c) {
            vlSelf->bitty_core__DOT__Reg_C__DOT__reg_d_out 
                = (0xffffU & ((4U & (IData)(vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_sel))
                               ? ((2U & (IData)(vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_sel))
                                   ? ((1U & (IData)(vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_sel))
                                       ? (((IData)(vlSelf->Reg_S_Out) 
                                           == (IData)(vlSelf->bitty_core__DOT__myMux__DOT__reg_mux_out))
                                           ? 0U : (
                                                   ((IData)(vlSelf->Reg_S_Out) 
                                                    > (IData)(vlSelf->bitty_core__DOT__myMux__DOT__reg_mux_out))
                                                    ? 1U
                                                    : 2U))
                                       : VL_SHIFTR_III(16,16,32, (IData)(vlSelf->Reg_S_Out), 
                                                       (0xfU 
                                                        & (IData)(vlSelf->bitty_core__DOT__myMux__DOT__reg_mux_out))))
                                   : ((1U & (IData)(vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_sel))
                                       ? VL_SHIFTL_III(16,16,32, (IData)(vlSelf->Reg_S_Out), 
                                                       (0xfU 
                                                        & (IData)(vlSelf->bitty_core__DOT__myMux__DOT__reg_mux_out)))
                                       : ((IData)(vlSelf->Reg_S_Out) 
                                          ^ (IData)(vlSelf->bitty_core__DOT__myMux__DOT__reg_mux_out))))
                               : ((2U & (IData)(vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_sel))
                                   ? ((1U & (IData)(vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_sel))
                                       ? ((IData)(vlSelf->Reg_S_Out) 
                                          | (IData)(vlSelf->bitty_core__DOT__myMux__DOT__reg_mux_out))
                                       : ((IData)(vlSelf->Reg_S_Out) 
                                          & (IData)(vlSelf->bitty_core__DOT__myMux__DOT__reg_mux_out)))
                                   : ((1U & (IData)(vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_sel))
                                       ? ((IData)(vlSelf->Reg_S_Out) 
                                          - (IData)(vlSelf->bitty_core__DOT__myMux__DOT__reg_mux_out))
                                       : ((IData)(vlSelf->Reg_S_Out) 
                                          + (IData)(vlSelf->bitty_core__DOT__myMux__DOT__reg_mux_out))))));
        }
        if (vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_7) {
            vlSelf->bitty_core__DOT__Reg_7__DOT__reg_d_out 
                = vlSelf->Reg_C_Out;
        }
        if (vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_6) {
            vlSelf->bitty_core__DOT__Reg_6__DOT__reg_d_out 
                = vlSelf->Reg_C_Out;
        }
        if (vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_5) {
            vlSelf->bitty_core__DOT__Reg_5__DOT__reg_d_out 
                = vlSelf->Reg_C_Out;
        }
        if (vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_4) {
            vlSelf->bitty_core__DOT__Reg_4__DOT__reg_d_out 
                = vlSelf->Reg_C_Out;
        }
        if (vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_3) {
            vlSelf->bitty_core__DOT__Reg_3__DOT__reg_d_out 
                = vlSelf->Reg_C_Out;
        }
        if (vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_2) {
            vlSelf->bitty_core__DOT__Reg_2__DOT__reg_d_out 
                = vlSelf->Reg_C_Out;
        }
        if (vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_1) {
            vlSelf->bitty_core__DOT__Reg_1__DOT__reg_d_out 
                = vlSelf->Reg_C_Out;
        }
        if (vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_0) {
            vlSelf->bitty_core__DOT__Reg_0__DOT__reg_d_out 
                = vlSelf->Reg_C_Out;
        }
        if (vlSelf->run) {
            vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_state 
                = vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_next_state;
        }
    }
    vlSelf->Reg_Inst_Out = vlSelf->bitty_core__DOT__Reg_Inst__DOT__reg_d_out;
    vlSelf->Reg_S_Out = vlSelf->bitty_core__DOT__Reg_S__DOT__reg_d_out;
    vlSelf->Reg_C_Out = vlSelf->bitty_core__DOT__Reg_C__DOT__reg_d_out;
    vlSelf->Reg_7_Out = vlSelf->bitty_core__DOT__Reg_7__DOT__reg_d_out;
    vlSelf->Reg_6_Out = vlSelf->bitty_core__DOT__Reg_6__DOT__reg_d_out;
    vlSelf->Reg_5_Out = vlSelf->bitty_core__DOT__Reg_5__DOT__reg_d_out;
    vlSelf->Reg_4_Out = vlSelf->bitty_core__DOT__Reg_4__DOT__reg_d_out;
    vlSelf->Reg_3_Out = vlSelf->bitty_core__DOT__Reg_3__DOT__reg_d_out;
    vlSelf->Reg_2_Out = vlSelf->bitty_core__DOT__Reg_2__DOT__reg_d_out;
    vlSelf->Reg_1_Out = vlSelf->bitty_core__DOT__Reg_1__DOT__reg_d_out;
    vlSelf->Reg_0_Out = vlSelf->bitty_core__DOT__Reg_0__DOT__reg_d_out;
    vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_i = 0U;
    vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_c = 0U;
    vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_s = 0U;
    vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_sel = 0U;
    vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_7 = 0U;
    vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_6 = 0U;
    vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_5 = 0U;
    vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_4 = 0U;
    vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_3 = 0U;
    vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_2 = 0U;
    vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_1 = 0U;
    vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_0 = 0U;
    bitty_core__DOT__myControlUnit__DOT__reg_done = 0U;
    __Vtableidx1 = (((IData)(vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_run_prev) 
                     << 3U) | (((IData)(vlSelf->run) 
                                << 2U) | (IData)(vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_state)));
    vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_next_state 
        = Vbitty_core__ConstPool__TABLE_h5bf4fed2_0
        [__Vtableidx1];
    bitty_core__DOT__myControlUnit__DOT__reg_mux_sel = 0xfU;
    if (((~ (IData)(vlSelf->reset)) & (IData)(vlSelf->run))) {
        if ((1U & (~ ((IData)(vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_state) 
                      >> 1U)))) {
            if ((1U & (~ (IData)(vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_state)))) {
                vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_i = 1U;
            }
            if ((1U & (IData)(vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_s = 1U;
            }
        }
        if ((2U & (IData)(vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
            if ((1U & (~ (IData)(vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_state)))) {
                vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_c = 1U;
                vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_sel 
                    = (7U & ((IData)(vlSelf->instruction) 
                             >> 2U));
                bitty_core__DOT__myControlUnit__DOT__reg_mux_sel 
                    = (7U & ((IData)(vlSelf->instruction) 
                             >> 0xaU));
            }
            if ((1U & (IData)(vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                if ((0x8000U & (IData)(vlSelf->instruction))) {
                    if ((0x4000U & (IData)(vlSelf->instruction))) {
                        if ((0x2000U & (IData)(vlSelf->instruction))) {
                            vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_7 = 1U;
                        }
                        if ((1U & (~ ((IData)(vlSelf->instruction) 
                                      >> 0xdU)))) {
                            vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_6 = 1U;
                        }
                    }
                    if ((1U & (~ ((IData)(vlSelf->instruction) 
                                  >> 0xeU)))) {
                        if ((0x2000U & (IData)(vlSelf->instruction))) {
                            vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_5 = 1U;
                        }
                        if ((1U & (~ ((IData)(vlSelf->instruction) 
                                      >> 0xdU)))) {
                            vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_4 = 1U;
                        }
                    }
                }
                if ((1U & (~ ((IData)(vlSelf->instruction) 
                              >> 0xfU)))) {
                    if ((0x4000U & (IData)(vlSelf->instruction))) {
                        if ((0x2000U & (IData)(vlSelf->instruction))) {
                            vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_3 = 1U;
                        }
                        if ((1U & (~ ((IData)(vlSelf->instruction) 
                                      >> 0xdU)))) {
                            vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_2 = 1U;
                        }
                    }
                    if ((1U & (~ ((IData)(vlSelf->instruction) 
                                  >> 0xeU)))) {
                        if ((0x2000U & (IData)(vlSelf->instruction))) {
                            vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_1 = 1U;
                        }
                        if ((1U & (~ ((IData)(vlSelf->instruction) 
                                      >> 0xdU)))) {
                            vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_0 = 1U;
                        }
                    }
                }
                bitty_core__DOT__myControlUnit__DOT__reg_done = 1U;
            }
        } else if ((1U & (IData)(vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
            bitty_core__DOT__myControlUnit__DOT__reg_mux_sel 
                = (7U & ((IData)(vlSelf->instruction) 
                         >> 0xdU));
        }
    }
    vlSelf->done = bitty_core__DOT__myControlUnit__DOT__reg_done;
    vlSelf->bitty_core__DOT__myMux__DOT__reg_mux_out 
        = ((8U & (IData)(bitty_core__DOT__myControlUnit__DOT__reg_mux_sel))
            ? ((4U & (IData)(bitty_core__DOT__myControlUnit__DOT__reg_mux_sel))
                ? 0U : ((2U & (IData)(bitty_core__DOT__myControlUnit__DOT__reg_mux_sel))
                         ? 0U : ((1U & (IData)(bitty_core__DOT__myControlUnit__DOT__reg_mux_sel))
                                  ? (IData)(vlSelf->bitty_core__DOT__myMux__DOT__in_9)
                                  : (IData)(vlSelf->bitty_core__DOT__myMux__DOT__in_8))))
            : ((4U & (IData)(bitty_core__DOT__myControlUnit__DOT__reg_mux_sel))
                ? ((2U & (IData)(bitty_core__DOT__myControlUnit__DOT__reg_mux_sel))
                    ? ((1U & (IData)(bitty_core__DOT__myControlUnit__DOT__reg_mux_sel))
                        ? (IData)(vlSelf->Reg_7_Out)
                        : (IData)(vlSelf->Reg_6_Out))
                    : ((1U & (IData)(bitty_core__DOT__myControlUnit__DOT__reg_mux_sel))
                        ? (IData)(vlSelf->Reg_5_Out)
                        : (IData)(vlSelf->Reg_4_Out)))
                : ((2U & (IData)(bitty_core__DOT__myControlUnit__DOT__reg_mux_sel))
                    ? ((1U & (IData)(bitty_core__DOT__myControlUnit__DOT__reg_mux_sel))
                        ? (IData)(vlSelf->Reg_3_Out)
                        : (IData)(vlSelf->Reg_2_Out))
                    : ((1U & (IData)(bitty_core__DOT__myControlUnit__DOT__reg_mux_sel))
                        ? (IData)(vlSelf->Reg_1_Out)
                        : (IData)(vlSelf->Reg_0_Out)))));
}

void Vbitty_core___024root___eval_nba(Vbitty_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbitty_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vbitty_core___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vbitty_core___024root___eval_triggers__act(Vbitty_core___024root* vlSelf);

bool Vbitty_core___024root___eval_phase__act(Vbitty_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbitty_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vbitty_core___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vbitty_core___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vbitty_core___024root___eval_phase__nba(Vbitty_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbitty_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vbitty_core___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vbitty_core___024root___dump_triggers__ico(Vbitty_core___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vbitty_core___024root___dump_triggers__nba(Vbitty_core___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vbitty_core___024root___dump_triggers__act(Vbitty_core___024root* vlSelf);
#endif  // VL_DEBUG

void Vbitty_core___024root___eval(Vbitty_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbitty_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core___024root___eval\n"); );
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
            Vbitty_core___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("rtl/bitty_core.v", 1, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vbitty_core___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vbitty_core___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("rtl/bitty_core.v", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vbitty_core___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("rtl/bitty_core.v", 1, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vbitty_core___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vbitty_core___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vbitty_core___024root___eval_debug_assertions(Vbitty_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbitty_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((vlSelf->run & 0xfeU))) {
        Verilated::overWidthError("run");}
}
#endif  // VL_DEBUG
