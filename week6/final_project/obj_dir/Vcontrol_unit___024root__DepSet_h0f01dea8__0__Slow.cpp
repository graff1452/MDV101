// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcontrol_unit.h for the primary calling header

#include "Vcontrol_unit__pch.h"
#include "Vcontrol_unit___024root.h"

VL_ATTR_COLD void Vcontrol_unit___024root___eval_static(Vcontrol_unit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcontrol_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_unit___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vcontrol_unit___024root___eval_initial(Vcontrol_unit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcontrol_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_unit___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
}

VL_ATTR_COLD void Vcontrol_unit___024root___eval_final(Vcontrol_unit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcontrol_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_unit___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vcontrol_unit___024root___dump_triggers__stl(Vcontrol_unit___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vcontrol_unit___024root___eval_phase__stl(Vcontrol_unit___024root* vlSelf);

VL_ATTR_COLD void Vcontrol_unit___024root___eval_settle(Vcontrol_unit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcontrol_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_unit___024root___eval_settle\n"); );
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
            Vcontrol_unit___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("rtl/control_unit.v", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vcontrol_unit___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vcontrol_unit___024root___dump_triggers__stl(Vcontrol_unit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcontrol_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_unit___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vcontrol_unit___024root___stl_sequent__TOP__0(Vcontrol_unit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcontrol_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_unit___024root___stl_sequent__TOP__0\n"); );
    // Init
    CData/*0:0*/ moduleName__DOT__reg_M;
    moduleName__DOT__reg_M = 0;
    CData/*0:0*/ moduleName__DOT__reg_en_s;
    moduleName__DOT__reg_en_s = 0;
    CData/*0:0*/ moduleName__DOT__reg_en_c;
    moduleName__DOT__reg_en_c = 0;
    CData/*0:0*/ moduleName__DOT__reg_en_i;
    moduleName__DOT__reg_en_i = 0;
    CData/*0:0*/ moduleName__DOT__reg_en_0;
    moduleName__DOT__reg_en_0 = 0;
    CData/*0:0*/ moduleName__DOT__reg_en_1;
    moduleName__DOT__reg_en_1 = 0;
    CData/*0:0*/ moduleName__DOT__reg_en_2;
    moduleName__DOT__reg_en_2 = 0;
    CData/*0:0*/ moduleName__DOT__reg_en_3;
    moduleName__DOT__reg_en_3 = 0;
    CData/*0:0*/ moduleName__DOT__reg_en_4;
    moduleName__DOT__reg_en_4 = 0;
    CData/*0:0*/ moduleName__DOT__reg_en_5;
    moduleName__DOT__reg_en_5 = 0;
    CData/*0:0*/ moduleName__DOT__reg_en_6;
    moduleName__DOT__reg_en_6 = 0;
    CData/*0:0*/ moduleName__DOT__reg_en_7;
    moduleName__DOT__reg_en_7 = 0;
    CData/*0:0*/ moduleName__DOT__reg_mode;
    moduleName__DOT__reg_mode = 0;
    CData/*0:0*/ moduleName__DOT__reg_done;
    moduleName__DOT__reg_done = 0;
    CData/*2:0*/ moduleName__DOT__reg_Rx;
    moduleName__DOT__reg_Rx = 0;
    CData/*2:0*/ moduleName__DOT__reg_Ry;
    moduleName__DOT__reg_Ry = 0;
    CData/*3:0*/ moduleName__DOT__reg_ALU_sel;
    moduleName__DOT__reg_ALU_sel = 0;
    CData/*3:0*/ moduleName__DOT__reg_sel;
    moduleName__DOT__reg_sel = 0;
    CData/*3:0*/ moduleName__DOT__reg_mux_sel;
    moduleName__DOT__reg_mux_sel = 0;
    // Body
    moduleName__DOT__reg_en_s = 0U;
    moduleName__DOT__reg_en_c = 0U;
    moduleName__DOT__reg_en_i = 0U;
    if ((1U & (~ ((IData)(vlSelf->moduleName__DOT__reg_state) 
                  >> 1U)))) {
        if ((1U & (IData)(vlSelf->moduleName__DOT__reg_state))) {
            moduleName__DOT__reg_en_s = 1U;
        }
        if ((1U & (~ (IData)(vlSelf->moduleName__DOT__reg_state)))) {
            moduleName__DOT__reg_en_i = 1U;
        }
    }
    moduleName__DOT__reg_done = 0U;
    moduleName__DOT__reg_sel = 0U;
    moduleName__DOT__reg_ALU_sel = (0xfU & ((IData)(vlSelf->instruction) 
                                            >> 3U));
    moduleName__DOT__reg_mode = 0U;
    moduleName__DOT__reg_M = (1U & ((IData)(vlSelf->instruction) 
                                    >> 2U));
    moduleName__DOT__reg_en_0 = 0U;
    moduleName__DOT__reg_en_1 = 0U;
    moduleName__DOT__reg_en_2 = 0U;
    moduleName__DOT__reg_en_3 = 0U;
    moduleName__DOT__reg_en_4 = 0U;
    moduleName__DOT__reg_en_5 = 0U;
    moduleName__DOT__reg_en_6 = 0U;
    moduleName__DOT__reg_en_7 = 0U;
    moduleName__DOT__reg_mux_sel = 0U;
    moduleName__DOT__reg_Rx = (7U & ((IData)(vlSelf->instruction) 
                                     >> 0xdU));
    moduleName__DOT__reg_Ry = (7U & ((IData)(vlSelf->instruction) 
                                     >> 0xaU));
    if ((2U & (IData)(vlSelf->moduleName__DOT__reg_state))) {
        if ((1U & (~ (IData)(vlSelf->moduleName__DOT__reg_state)))) {
            moduleName__DOT__reg_en_c = 1U;
            moduleName__DOT__reg_sel = moduleName__DOT__reg_ALU_sel;
            moduleName__DOT__reg_mode = moduleName__DOT__reg_M;
        }
        if ((1U & (IData)(vlSelf->moduleName__DOT__reg_state))) {
            moduleName__DOT__reg_done = 1U;
            if ((4U & (IData)(moduleName__DOT__reg_Rx))) {
                if ((2U & (IData)(moduleName__DOT__reg_Rx))) {
                    if ((1U & (IData)(moduleName__DOT__reg_Rx))) {
                        moduleName__DOT__reg_en_7 = 1U;
                    } else {
                        moduleName__DOT__reg_en_6 = 1U;
                    }
                } else if ((1U & (IData)(moduleName__DOT__reg_Rx))) {
                    moduleName__DOT__reg_en_5 = 1U;
                } else {
                    moduleName__DOT__reg_en_4 = 1U;
                }
            } else if ((2U & (IData)(moduleName__DOT__reg_Rx))) {
                if ((1U & (IData)(moduleName__DOT__reg_Rx))) {
                    moduleName__DOT__reg_en_3 = 1U;
                } else {
                    moduleName__DOT__reg_en_2 = 1U;
                }
            } else if ((1U & (IData)(moduleName__DOT__reg_Rx))) {
                moduleName__DOT__reg_en_1 = 1U;
            } else {
                moduleName__DOT__reg_en_0 = 1U;
            }
        } else {
            moduleName__DOT__reg_mux_sel = moduleName__DOT__reg_Ry;
        }
    } else if ((1U & (IData)(vlSelf->moduleName__DOT__reg_state))) {
        moduleName__DOT__reg_mux_sel = moduleName__DOT__reg_Rx;
    }
    vlSelf->en_s = moduleName__DOT__reg_en_s;
    vlSelf->en_c = moduleName__DOT__reg_en_c;
    vlSelf->en_i = moduleName__DOT__reg_en_i;
    vlSelf->done = moduleName__DOT__reg_done;
    vlSelf->sel = moduleName__DOT__reg_sel;
    vlSelf->mode = moduleName__DOT__reg_mode;
    vlSelf->en_0 = moduleName__DOT__reg_en_0;
    vlSelf->en_1 = moduleName__DOT__reg_en_1;
    vlSelf->en_2 = moduleName__DOT__reg_en_2;
    vlSelf->en_3 = moduleName__DOT__reg_en_3;
    vlSelf->en_4 = moduleName__DOT__reg_en_4;
    vlSelf->en_5 = moduleName__DOT__reg_en_5;
    vlSelf->en_6 = moduleName__DOT__reg_en_6;
    vlSelf->en_7 = moduleName__DOT__reg_en_7;
    vlSelf->mux_sel = moduleName__DOT__reg_mux_sel;
}

VL_ATTR_COLD void Vcontrol_unit___024root___eval_stl(Vcontrol_unit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcontrol_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_unit___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vcontrol_unit___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vcontrol_unit___024root___eval_triggers__stl(Vcontrol_unit___024root* vlSelf);

VL_ATTR_COLD bool Vcontrol_unit___024root___eval_phase__stl(Vcontrol_unit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcontrol_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_unit___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vcontrol_unit___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vcontrol_unit___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vcontrol_unit___024root___dump_triggers__ico(Vcontrol_unit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcontrol_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_unit___024root___dump_triggers__ico\n"); );
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
VL_ATTR_COLD void Vcontrol_unit___024root___dump_triggers__act(Vcontrol_unit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcontrol_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_unit___024root___dump_triggers__act\n"); );
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
VL_ATTR_COLD void Vcontrol_unit___024root___dump_triggers__nba(Vcontrol_unit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcontrol_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_unit___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vcontrol_unit___024root___ctor_var_reset(Vcontrol_unit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcontrol_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_unit___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->run = VL_RAND_RESET_I(1);
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->reset = VL_RAND_RESET_I(1);
    vlSelf->instruction = VL_RAND_RESET_I(16);
    vlSelf->en_s = VL_RAND_RESET_I(1);
    vlSelf->en_c = VL_RAND_RESET_I(1);
    vlSelf->en_i = VL_RAND_RESET_I(1);
    vlSelf->en_0 = VL_RAND_RESET_I(1);
    vlSelf->en_1 = VL_RAND_RESET_I(1);
    vlSelf->en_2 = VL_RAND_RESET_I(1);
    vlSelf->en_3 = VL_RAND_RESET_I(1);
    vlSelf->en_4 = VL_RAND_RESET_I(1);
    vlSelf->en_5 = VL_RAND_RESET_I(1);
    vlSelf->en_6 = VL_RAND_RESET_I(1);
    vlSelf->en_7 = VL_RAND_RESET_I(1);
    vlSelf->mode = VL_RAND_RESET_I(1);
    vlSelf->sel = VL_RAND_RESET_I(4);
    vlSelf->mux_sel = VL_RAND_RESET_I(4);
    vlSelf->done = VL_RAND_RESET_I(1);
    vlSelf->moduleName__DOT__reg_state = VL_RAND_RESET_I(2);
    vlSelf->moduleName__DOT__reg_next_state = VL_RAND_RESET_I(2);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
}
