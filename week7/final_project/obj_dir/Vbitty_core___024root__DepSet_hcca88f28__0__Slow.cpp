// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbitty_core.h for the primary calling header

#include "Vbitty_core__pch.h"
#include "Vbitty_core___024root.h"

VL_ATTR_COLD void Vbitty_core___024root___eval_static(Vbitty_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbitty_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vbitty_core___024root___eval_initial(Vbitty_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbitty_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
}

VL_ATTR_COLD void Vbitty_core___024root___eval_final(Vbitty_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbitty_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vbitty_core___024root___dump_triggers__stl(Vbitty_core___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vbitty_core___024root___eval_phase__stl(Vbitty_core___024root* vlSelf);

VL_ATTR_COLD void Vbitty_core___024root___eval_settle(Vbitty_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbitty_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core___024root___eval_settle\n"); );
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
            Vbitty_core___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("rtl/bitty_core.v", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vbitty_core___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vbitty_core___024root___dump_triggers__stl(Vbitty_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbitty_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

extern const VlUnpacked<CData/*1:0*/, 16> Vbitty_core__ConstPool__TABLE_h5bf4fed2_0;

VL_ATTR_COLD void Vbitty_core___024root___stl_sequent__TOP__0(Vbitty_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbitty_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core___024root___stl_sequent__TOP__0\n"); );
    // Init
    CData/*0:0*/ bitty_core__DOT__myControlUnit__DOT__reg_done;
    bitty_core__DOT__myControlUnit__DOT__reg_done = 0;
    CData/*3:0*/ bitty_core__DOT__myControlUnit__DOT__reg_mux_sel;
    bitty_core__DOT__myControlUnit__DOT__reg_mux_sel = 0;
    CData/*3:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    vlSelf->Reg_Inst_Out = vlSelf->bitty_core__DOT__Reg_Inst__DOT__reg_d_out;
    vlSelf->Reg_S_Out = vlSelf->bitty_core__DOT__Reg_S__DOT__reg_d_out;
    vlSelf->Reg_C_Out = vlSelf->bitty_core__DOT__Reg_C__DOT__reg_d_out;
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
    vlSelf->Reg_0_Out = vlSelf->bitty_core__DOT__Reg_0__DOT__reg_d_out;
    vlSelf->Reg_1_Out = vlSelf->bitty_core__DOT__Reg_1__DOT__reg_d_out;
    vlSelf->Reg_2_Out = vlSelf->bitty_core__DOT__Reg_2__DOT__reg_d_out;
    vlSelf->Reg_3_Out = vlSelf->bitty_core__DOT__Reg_3__DOT__reg_d_out;
    vlSelf->Reg_4_Out = vlSelf->bitty_core__DOT__Reg_4__DOT__reg_d_out;
    vlSelf->Reg_5_Out = vlSelf->bitty_core__DOT__Reg_5__DOT__reg_d_out;
    vlSelf->Reg_6_Out = vlSelf->bitty_core__DOT__Reg_6__DOT__reg_d_out;
    vlSelf->Reg_7_Out = vlSelf->bitty_core__DOT__Reg_7__DOT__reg_d_out;
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

VL_ATTR_COLD void Vbitty_core___024root___eval_stl(Vbitty_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbitty_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vbitty_core___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vbitty_core___024root___eval_triggers__stl(Vbitty_core___024root* vlSelf);

VL_ATTR_COLD bool Vbitty_core___024root___eval_phase__stl(Vbitty_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbitty_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vbitty_core___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vbitty_core___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vbitty_core___024root___dump_triggers__ico(Vbitty_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbitty_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core___024root___dump_triggers__ico\n"); );
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
VL_ATTR_COLD void Vbitty_core___024root___dump_triggers__act(Vbitty_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbitty_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vbitty_core___024root___dump_triggers__nba(Vbitty_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbitty_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vbitty_core___024root___ctor_var_reset(Vbitty_core___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbitty_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->reset = VL_RAND_RESET_I(1);
    vlSelf->run = VL_RAND_RESET_I(1);
    vlSelf->instruction = VL_RAND_RESET_I(16);
    vlSelf->done = VL_RAND_RESET_I(1);
    vlSelf->Reg_Inst_Out = VL_RAND_RESET_I(16);
    vlSelf->Reg_S_Out = VL_RAND_RESET_I(16);
    vlSelf->Reg_C_Out = VL_RAND_RESET_I(16);
    vlSelf->Reg_0_Out = VL_RAND_RESET_I(16);
    vlSelf->Reg_1_Out = VL_RAND_RESET_I(16);
    vlSelf->Reg_2_Out = VL_RAND_RESET_I(16);
    vlSelf->Reg_3_Out = VL_RAND_RESET_I(16);
    vlSelf->Reg_4_Out = VL_RAND_RESET_I(16);
    vlSelf->Reg_5_Out = VL_RAND_RESET_I(16);
    vlSelf->Reg_6_Out = VL_RAND_RESET_I(16);
    vlSelf->Reg_7_Out = VL_RAND_RESET_I(16);
    vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_run_prev = VL_RAND_RESET_I(1);
    vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_s = VL_RAND_RESET_I(1);
    vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_c = VL_RAND_RESET_I(1);
    vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_i = VL_RAND_RESET_I(1);
    vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_0 = VL_RAND_RESET_I(1);
    vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_1 = VL_RAND_RESET_I(1);
    vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_2 = VL_RAND_RESET_I(1);
    vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_3 = VL_RAND_RESET_I(1);
    vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_4 = VL_RAND_RESET_I(1);
    vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_5 = VL_RAND_RESET_I(1);
    vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_6 = VL_RAND_RESET_I(1);
    vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_en_7 = VL_RAND_RESET_I(1);
    vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_state = VL_RAND_RESET_I(2);
    vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_next_state = VL_RAND_RESET_I(2);
    vlSelf->bitty_core__DOT__myControlUnit__DOT__reg_sel = VL_RAND_RESET_I(3);
    vlSelf->bitty_core__DOT__Reg_Inst__DOT__reg_d_out = VL_RAND_RESET_I(16);
    vlSelf->bitty_core__DOT__Reg_S__DOT__reg_d_out = VL_RAND_RESET_I(16);
    vlSelf->bitty_core__DOT__Reg_C__DOT__reg_d_out = VL_RAND_RESET_I(16);
    vlSelf->bitty_core__DOT__Reg_0__DOT__reg_d_out = VL_RAND_RESET_I(16);
    vlSelf->bitty_core__DOT__Reg_1__DOT__reg_d_out = VL_RAND_RESET_I(16);
    vlSelf->bitty_core__DOT__Reg_2__DOT__reg_d_out = VL_RAND_RESET_I(16);
    vlSelf->bitty_core__DOT__Reg_3__DOT__reg_d_out = VL_RAND_RESET_I(16);
    vlSelf->bitty_core__DOT__Reg_4__DOT__reg_d_out = VL_RAND_RESET_I(16);
    vlSelf->bitty_core__DOT__Reg_5__DOT__reg_d_out = VL_RAND_RESET_I(16);
    vlSelf->bitty_core__DOT__Reg_6__DOT__reg_d_out = VL_RAND_RESET_I(16);
    vlSelf->bitty_core__DOT__Reg_7__DOT__reg_d_out = VL_RAND_RESET_I(16);
    vlSelf->bitty_core__DOT__myMux__DOT__in_8 = VL_RAND_RESET_I(16);
    vlSelf->bitty_core__DOT__myMux__DOT__in_9 = VL_RAND_RESET_I(16);
    vlSelf->bitty_core__DOT__myMux__DOT__reg_mux_out = VL_RAND_RESET_I(16);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
}
