// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcontrol_unit.h for the primary calling header

#include "Vcontrol_unit__pch.h"
#include "Vcontrol_unit___024root.h"

VL_INLINE_OPT void Vcontrol_unit___024root___ico_sequent__TOP__0(Vcontrol_unit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcontrol_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_unit___024root___ico_sequent__TOP__0\n"); );
    // Init
    CData/*0:0*/ moduleName__DOT__reg_M;
    moduleName__DOT__reg_M = 0;
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
            moduleName__DOT__reg_sel = moduleName__DOT__reg_ALU_sel;
            moduleName__DOT__reg_mode = moduleName__DOT__reg_M;
        }
        if ((1U & (IData)(vlSelf->moduleName__DOT__reg_state))) {
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

void Vcontrol_unit___024root___eval_ico(Vcontrol_unit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcontrol_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_unit___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        Vcontrol_unit___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vcontrol_unit___024root___eval_triggers__ico(Vcontrol_unit___024root* vlSelf);

bool Vcontrol_unit___024root___eval_phase__ico(Vcontrol_unit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcontrol_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_unit___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vcontrol_unit___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        Vcontrol_unit___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vcontrol_unit___024root___eval_act(Vcontrol_unit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcontrol_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_unit___024root___eval_act\n"); );
}

extern const VlUnpacked<CData/*1:0*/, 64> Vcontrol_unit__ConstPool__TABLE_h0b35b154_0;
extern const VlUnpacked<CData/*1:0*/, 64> Vcontrol_unit__ConstPool__TABLE_h615c81c6_0;
extern const VlUnpacked<CData/*1:0*/, 64> Vcontrol_unit__ConstPool__TABLE_hbc5f49a4_0;

VL_INLINE_OPT void Vcontrol_unit___024root___nba_sequent__TOP__0(Vcontrol_unit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcontrol_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_unit___024root___nba_sequent__TOP__0\n"); );
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
    CData/*5:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    __Vtableidx1 = (((IData)(vlSelf->moduleName__DOT__reg_next_state) 
                     << 4U) | (((IData)(vlSelf->moduleName__DOT__reg_state) 
                                << 2U) | (((IData)(vlSelf->run) 
                                           << 1U) | (IData)(vlSelf->reset))));
    if ((1U & Vcontrol_unit__ConstPool__TABLE_h0b35b154_0
         [__Vtableidx1])) {
        vlSelf->moduleName__DOT__reg_state = Vcontrol_unit__ConstPool__TABLE_h615c81c6_0
            [__Vtableidx1];
    }
    if ((2U & Vcontrol_unit__ConstPool__TABLE_h0b35b154_0
         [__Vtableidx1])) {
        vlSelf->moduleName__DOT__reg_next_state = Vcontrol_unit__ConstPool__TABLE_hbc5f49a4_0
            [__Vtableidx1];
    }
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

void Vcontrol_unit___024root___eval_nba(Vcontrol_unit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcontrol_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_unit___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vcontrol_unit___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vcontrol_unit___024root___eval_triggers__act(Vcontrol_unit___024root* vlSelf);

bool Vcontrol_unit___024root___eval_phase__act(Vcontrol_unit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcontrol_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_unit___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vcontrol_unit___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vcontrol_unit___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vcontrol_unit___024root___eval_phase__nba(Vcontrol_unit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcontrol_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_unit___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vcontrol_unit___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vcontrol_unit___024root___dump_triggers__ico(Vcontrol_unit___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vcontrol_unit___024root___dump_triggers__nba(Vcontrol_unit___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vcontrol_unit___024root___dump_triggers__act(Vcontrol_unit___024root* vlSelf);
#endif  // VL_DEBUG

void Vcontrol_unit___024root___eval(Vcontrol_unit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcontrol_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_unit___024root___eval\n"); );
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
            Vcontrol_unit___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("rtl/control_unit.v", 1, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vcontrol_unit___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vcontrol_unit___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("rtl/control_unit.v", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vcontrol_unit___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("rtl/control_unit.v", 1, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vcontrol_unit___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vcontrol_unit___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vcontrol_unit___024root___eval_debug_assertions(Vcontrol_unit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcontrol_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_unit___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->run & 0xfeU))) {
        Verilated::overWidthError("run");}
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
}
#endif  // VL_DEBUG
