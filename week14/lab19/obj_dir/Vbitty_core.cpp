// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbitty_core.h for the primary calling header

#include "Vbitty_core.h"
#include "Vbitty_core__Syms.h"

//==========

void Vbitty_core::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vbitty_core::eval\n"); );
    Vbitty_core__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vbitty_core* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("rtl/bitty_core.v", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vbitty_core::_eval_initial_loop(Vbitty_core__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("rtl/bitty_core.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vbitty_core::_sequent__TOP__1(Vbitty_core__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core::_sequent__TOP__1\n"); );
    Vbitty_core* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vdlyvset__bitty_core__DOT__myRegisterMemory__DOT__memory_cell__v0 = 0U;
    if (vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_register_memory) {
        if ((4U & (IData)(vlTOPp->instruction))) {
            if ((4U & (IData)(vlTOPp->instruction))) {
                vlTOPp->__Vdlyvval__bitty_core__DOT__myRegisterMemory__DOT__memory_cell__v0 
                    = ((0x8000U & (IData)(vlTOPp->instruction))
                        ? ((0x4000U & (IData)(vlTOPp->instruction))
                            ? ((0x2000U & (IData)(vlTOPp->instruction))
                                ? (IData)(vlTOPp->Reg_7_Out)
                                : (IData)(vlTOPp->Reg_6_Out))
                            : ((0x2000U & (IData)(vlTOPp->instruction))
                                ? (IData)(vlTOPp->Reg_5_Out)
                                : (IData)(vlTOPp->Reg_4_Out)))
                        : ((0x4000U & (IData)(vlTOPp->instruction))
                            ? ((0x2000U & (IData)(vlTOPp->instruction))
                                ? (IData)(vlTOPp->Reg_3_Out)
                                : (IData)(vlTOPp->Reg_2_Out))
                            : ((0x2000U & (IData)(vlTOPp->instruction))
                                ? (IData)(vlTOPp->Reg_1_Out)
                                : (IData)(vlTOPp->Reg_0_Out))));
                vlTOPp->__Vdlyvset__bitty_core__DOT__myRegisterMemory__DOT__memory_cell__v0 = 1U;
                vlTOPp->__Vdlyvdim0__bitty_core__DOT__myRegisterMemory__DOT__memory_cell__v0 
                    = (7U & ((IData)(vlTOPp->instruction) 
                             >> 0xaU));
            }
        }
    }
}

VL_INLINE_OPT void Vbitty_core::_sequent__TOP__2(Vbitty_core__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core::_sequent__TOP__2\n"); );
    Vbitty_core* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->reset) {
        vlTOPp->bitty_core__DOT__Reg_M__DOT__reg_d_out = 0U;
    } else {
        if (vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_m) {
            vlTOPp->bitty_core__DOT__Reg_M__DOT__reg_d_out 
                = vlTOPp->bitty_core__DOT__myRegisterMemory__DOT__reg_out;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->bitty_core__DOT__Reg_C__DOT__reg_d_out = 0U;
    } else {
        if (vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_c) {
            vlTOPp->bitty_core__DOT__Reg_C__DOT__reg_d_out 
                = (0xffffU & ((4U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_sel))
                               ? ((2U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_sel))
                                   ? ((1U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_sel))
                                       ? (((IData)(vlTOPp->bitty_core__DOT__Reg_S__DOT__reg_d_out) 
                                           == (IData)(vlTOPp->bitty_core__DOT__myMux__DOT__reg_mux_out))
                                           ? 0U : (
                                                   ((IData)(vlTOPp->bitty_core__DOT__Reg_S__DOT__reg_d_out) 
                                                    > (IData)(vlTOPp->bitty_core__DOT__myMux__DOT__reg_mux_out))
                                                    ? 1U
                                                    : 2U))
                                       : ((0xfU >= 
                                           (0xfU & (IData)(vlTOPp->bitty_core__DOT__myMux__DOT__reg_mux_out)))
                                           ? ((IData)(vlTOPp->bitty_core__DOT__Reg_S__DOT__reg_d_out) 
                                              >> (0xfU 
                                                  & (IData)(vlTOPp->bitty_core__DOT__myMux__DOT__reg_mux_out)))
                                           : 0U)) : 
                                  ((1U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_sel))
                                    ? ((0xfU >= (0xfU 
                                                 & (IData)(vlTOPp->bitty_core__DOT__myMux__DOT__reg_mux_out)))
                                        ? ((IData)(vlTOPp->bitty_core__DOT__Reg_S__DOT__reg_d_out) 
                                           << (0xfU 
                                               & (IData)(vlTOPp->bitty_core__DOT__myMux__DOT__reg_mux_out)))
                                        : 0U) : ((IData)(vlTOPp->bitty_core__DOT__Reg_S__DOT__reg_d_out) 
                                                 ^ (IData)(vlTOPp->bitty_core__DOT__myMux__DOT__reg_mux_out))))
                               : ((2U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_sel))
                                   ? ((1U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_sel))
                                       ? ((IData)(vlTOPp->bitty_core__DOT__Reg_S__DOT__reg_d_out) 
                                          | (IData)(vlTOPp->bitty_core__DOT__myMux__DOT__reg_mux_out))
                                       : ((IData)(vlTOPp->bitty_core__DOT__Reg_S__DOT__reg_d_out) 
                                          & (IData)(vlTOPp->bitty_core__DOT__myMux__DOT__reg_mux_out)))
                                   : ((1U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_sel))
                                       ? ((IData)(vlTOPp->bitty_core__DOT__Reg_S__DOT__reg_d_out) 
                                          - (IData)(vlTOPp->bitty_core__DOT__myMux__DOT__reg_mux_out))
                                       : ((IData)(vlTOPp->bitty_core__DOT__Reg_S__DOT__reg_d_out) 
                                          + (IData)(vlTOPp->bitty_core__DOT__myMux__DOT__reg_mux_out))))));
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->bitty_core__DOT__Reg_7__DOT__reg_d_out = 0U;
    } else {
        if (vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_7) {
            vlTOPp->bitty_core__DOT__Reg_7__DOT__reg_d_out 
                = vlTOPp->bitty_core__DOT__myMux2__DOT__reg_mux2_out;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->bitty_core__DOT__Reg_6__DOT__reg_d_out = 0U;
    } else {
        if (vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_6) {
            vlTOPp->bitty_core__DOT__Reg_6__DOT__reg_d_out 
                = vlTOPp->bitty_core__DOT__myMux2__DOT__reg_mux2_out;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->bitty_core__DOT__Reg_5__DOT__reg_d_out = 0U;
    } else {
        if (vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_5) {
            vlTOPp->bitty_core__DOT__Reg_5__DOT__reg_d_out 
                = vlTOPp->bitty_core__DOT__myMux2__DOT__reg_mux2_out;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->bitty_core__DOT__Reg_4__DOT__reg_d_out = 0U;
    } else {
        if (vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_4) {
            vlTOPp->bitty_core__DOT__Reg_4__DOT__reg_d_out 
                = vlTOPp->bitty_core__DOT__myMux2__DOT__reg_mux2_out;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->bitty_core__DOT__Reg_3__DOT__reg_d_out = 0U;
    } else {
        if (vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_3) {
            vlTOPp->bitty_core__DOT__Reg_3__DOT__reg_d_out 
                = vlTOPp->bitty_core__DOT__myMux2__DOT__reg_mux2_out;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->bitty_core__DOT__Reg_2__DOT__reg_d_out = 0U;
    } else {
        if (vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_2) {
            vlTOPp->bitty_core__DOT__Reg_2__DOT__reg_d_out 
                = vlTOPp->bitty_core__DOT__myMux2__DOT__reg_mux2_out;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->bitty_core__DOT__Reg_1__DOT__reg_d_out = 0U;
    } else {
        if (vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_1) {
            vlTOPp->bitty_core__DOT__Reg_1__DOT__reg_d_out 
                = vlTOPp->bitty_core__DOT__myMux2__DOT__reg_mux2_out;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->bitty_core__DOT__Reg_0__DOT__reg_d_out = 0U;
    } else {
        if (vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_0) {
            vlTOPp->bitty_core__DOT__Reg_0__DOT__reg_d_out 
                = vlTOPp->bitty_core__DOT__myMux2__DOT__reg_mux2_out;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state = 0U;
    } else {
        if (vlTOPp->run) {
            vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state 
                = vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_next_state;
        }
    }
    vlTOPp->last_alu_result = vlTOPp->bitty_core__DOT__Reg_C__DOT__reg_d_out;
    if (vlTOPp->reset) {
        vlTOPp->bitty_core__DOT__Reg_S__DOT__reg_d_out = 0U;
    } else {
        if (vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_s) {
            vlTOPp->bitty_core__DOT__Reg_S__DOT__reg_d_out 
                = vlTOPp->bitty_core__DOT__myMux__DOT__reg_mux_out;
        }
    }
    vlTOPp->Reg_7_Out = vlTOPp->bitty_core__DOT__Reg_7__DOT__reg_d_out;
    vlTOPp->Reg_6_Out = vlTOPp->bitty_core__DOT__Reg_6__DOT__reg_d_out;
    vlTOPp->Reg_5_Out = vlTOPp->bitty_core__DOT__Reg_5__DOT__reg_d_out;
    vlTOPp->Reg_4_Out = vlTOPp->bitty_core__DOT__Reg_4__DOT__reg_d_out;
    vlTOPp->Reg_3_Out = vlTOPp->bitty_core__DOT__Reg_3__DOT__reg_d_out;
    vlTOPp->Reg_2_Out = vlTOPp->bitty_core__DOT__Reg_2__DOT__reg_d_out;
    vlTOPp->Reg_1_Out = vlTOPp->bitty_core__DOT__Reg_1__DOT__reg_d_out;
    vlTOPp->Reg_0_Out = vlTOPp->bitty_core__DOT__Reg_0__DOT__reg_d_out;
    vlTOPp->__Vtableidx1 = vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state;
    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_next_state 
        = vlTOPp->__Vtable1_bitty_core__DOT__myControlUnit__DOT__reg_next_state
        [vlTOPp->__Vtableidx1];
}

VL_INLINE_OPT void Vbitty_core::_sequent__TOP__4(Vbitty_core__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core::_sequent__TOP__4\n"); );
    Vbitty_core* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_register_memory) {
        if ((1U & (~ ((IData)(vlTOPp->instruction) 
                      >> 2U)))) {
            vlTOPp->bitty_core__DOT__myRegisterMemory__DOT__reg_out 
                = vlTOPp->bitty_core__DOT__myRegisterMemory__DOT__memory_cell
                [(7U & ((IData)(vlTOPp->instruction) 
                        >> 0xaU))];
        }
    }
    if (vlTOPp->__Vdlyvset__bitty_core__DOT__myRegisterMemory__DOT__memory_cell__v0) {
        vlTOPp->bitty_core__DOT__myRegisterMemory__DOT__memory_cell[vlTOPp->__Vdlyvdim0__bitty_core__DOT__myRegisterMemory__DOT__memory_cell__v0] 
            = vlTOPp->__Vdlyvval__bitty_core__DOT__myRegisterMemory__DOT__memory_cell__v0;
    }
}

VL_INLINE_OPT void Vbitty_core::_combo__TOP__5(Vbitty_core__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core::_combo__TOP__5\n"); );
    Vbitty_core* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_3 = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((4U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
            if ((2U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                if ((1U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_3 = 0U;
                }
            } else {
                if ((1U & (~ (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state)))) {
                    if ((2U & (IData)(vlTOPp->instruction))) {
                        if ((1U & (IData)(vlTOPp->instruction))) {
                            if ((1U & (~ ((IData)(vlTOPp->instruction) 
                                          >> 2U)))) {
                                if ((1U & (~ ((IData)(vlTOPp->instruction) 
                                              >> 0xfU)))) {
                                    if ((0x4000U & (IData)(vlTOPp->instruction))) {
                                        if ((0x2000U 
                                             & (IData)(vlTOPp->instruction))) {
                                            vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_3 = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        if ((1U & (IData)(vlTOPp->instruction))) {
                            if ((1U & (~ ((IData)(vlTOPp->instruction) 
                                          >> 0xfU)))) {
                                if ((0x4000U & (IData)(vlTOPp->instruction))) {
                                    if ((0x2000U & (IData)(vlTOPp->instruction))) {
                                        vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_3 = 1U;
                                    }
                                }
                            }
                        } else {
                            if ((1U & (~ ((IData)(vlTOPp->instruction) 
                                          >> 0xfU)))) {
                                if ((0x4000U & (IData)(vlTOPp->instruction))) {
                                    if ((0x2000U & (IData)(vlTOPp->instruction))) {
                                        vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_3 = 1U;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else {
            if ((1U & (~ ((IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state)))) {
                    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_3 = 0U;
                }
            }
        }
    }
    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_2 = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((4U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
            if ((2U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                if ((1U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_2 = 0U;
                }
            } else {
                if ((1U & (~ (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state)))) {
                    if ((2U & (IData)(vlTOPp->instruction))) {
                        if ((1U & (IData)(vlTOPp->instruction))) {
                            if ((1U & (~ ((IData)(vlTOPp->instruction) 
                                          >> 2U)))) {
                                if ((1U & (~ ((IData)(vlTOPp->instruction) 
                                              >> 0xfU)))) {
                                    if ((0x4000U & (IData)(vlTOPp->instruction))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->instruction) 
                                                    >> 0xdU)))) {
                                            vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_2 = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        if ((1U & (IData)(vlTOPp->instruction))) {
                            if ((1U & (~ ((IData)(vlTOPp->instruction) 
                                          >> 0xfU)))) {
                                if ((0x4000U & (IData)(vlTOPp->instruction))) {
                                    if ((1U & (~ ((IData)(vlTOPp->instruction) 
                                                  >> 0xdU)))) {
                                        vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_2 = 1U;
                                    }
                                }
                            }
                        } else {
                            if ((1U & (~ ((IData)(vlTOPp->instruction) 
                                          >> 0xfU)))) {
                                if ((0x4000U & (IData)(vlTOPp->instruction))) {
                                    if ((1U & (~ ((IData)(vlTOPp->instruction) 
                                                  >> 0xdU)))) {
                                        vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_2 = 1U;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else {
            if ((1U & (~ ((IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state)))) {
                    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_2 = 0U;
                }
            }
        }
    }
    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_m = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((4U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
            if ((2U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                if ((1U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_m = 0U;
                }
            }
        } else {
            if ((2U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                if ((1U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                    if ((2U & (IData)(vlTOPp->instruction))) {
                        if ((1U & (IData)(vlTOPp->instruction))) {
                            vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_m = 1U;
                        }
                    }
                } else {
                    if ((2U & (IData)(vlTOPp->instruction))) {
                        if ((1U & (IData)(vlTOPp->instruction))) {
                            vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_m = 0U;
                        }
                    }
                }
            } else {
                if ((1U & (~ (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state)))) {
                    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_m = 0U;
                }
            }
        }
    }
    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_c = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((4U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
            if ((2U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                if ((1U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_c = 0U;
                }
            }
        } else {
            if ((2U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                if ((1U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                    if ((1U & (~ ((IData)(vlTOPp->instruction) 
                                  >> 1U)))) {
                        vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_c = 1U;
                    }
                }
            } else {
                if ((1U & (~ (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state)))) {
                    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_c = 0U;
                }
            }
        }
    }
    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_0 = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((4U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
            if ((2U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                if ((1U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_0 = 0U;
                }
            } else {
                if ((1U & (~ (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state)))) {
                    if ((2U & (IData)(vlTOPp->instruction))) {
                        if ((1U & (IData)(vlTOPp->instruction))) {
                            if ((1U & (~ ((IData)(vlTOPp->instruction) 
                                          >> 2U)))) {
                                if ((1U & (~ ((IData)(vlTOPp->instruction) 
                                              >> 0xfU)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->instruction) 
                                                  >> 0xeU)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->instruction) 
                                                    >> 0xdU)))) {
                                            vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_0 = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        if ((1U & (IData)(vlTOPp->instruction))) {
                            if ((1U & (~ ((IData)(vlTOPp->instruction) 
                                          >> 0xfU)))) {
                                if ((1U & (~ ((IData)(vlTOPp->instruction) 
                                              >> 0xeU)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->instruction) 
                                                  >> 0xdU)))) {
                                        vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_0 = 1U;
                                    }
                                }
                            }
                        } else {
                            if ((1U & (~ ((IData)(vlTOPp->instruction) 
                                          >> 0xfU)))) {
                                if ((1U & (~ ((IData)(vlTOPp->instruction) 
                                              >> 0xeU)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->instruction) 
                                                  >> 0xdU)))) {
                                        vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_0 = 1U;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else {
            if ((1U & (~ ((IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state)))) {
                    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_0 = 0U;
                }
            }
        }
    }
    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_1 = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((4U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
            if ((2U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                if ((1U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_1 = 0U;
                }
            } else {
                if ((1U & (~ (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state)))) {
                    if ((2U & (IData)(vlTOPp->instruction))) {
                        if ((1U & (IData)(vlTOPp->instruction))) {
                            if ((1U & (~ ((IData)(vlTOPp->instruction) 
                                          >> 2U)))) {
                                if ((1U & (~ ((IData)(vlTOPp->instruction) 
                                              >> 0xfU)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->instruction) 
                                                  >> 0xeU)))) {
                                        if ((0x2000U 
                                             & (IData)(vlTOPp->instruction))) {
                                            vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_1 = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        if ((1U & (IData)(vlTOPp->instruction))) {
                            if ((1U & (~ ((IData)(vlTOPp->instruction) 
                                          >> 0xfU)))) {
                                if ((1U & (~ ((IData)(vlTOPp->instruction) 
                                              >> 0xeU)))) {
                                    if ((0x2000U & (IData)(vlTOPp->instruction))) {
                                        vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_1 = 1U;
                                    }
                                }
                            }
                        } else {
                            if ((1U & (~ ((IData)(vlTOPp->instruction) 
                                          >> 0xfU)))) {
                                if ((1U & (~ ((IData)(vlTOPp->instruction) 
                                              >> 0xeU)))) {
                                    if ((0x2000U & (IData)(vlTOPp->instruction))) {
                                        vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_1 = 1U;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else {
            if ((1U & (~ ((IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state)))) {
                    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_1 = 0U;
                }
            }
        }
    }
    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_4 = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((4U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
            if ((2U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                if ((1U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_4 = 0U;
                }
            } else {
                if ((1U & (~ (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state)))) {
                    if ((2U & (IData)(vlTOPp->instruction))) {
                        if ((1U & (IData)(vlTOPp->instruction))) {
                            if ((1U & (~ ((IData)(vlTOPp->instruction) 
                                          >> 2U)))) {
                                if ((0x8000U & (IData)(vlTOPp->instruction))) {
                                    if ((1U & (~ ((IData)(vlTOPp->instruction) 
                                                  >> 0xeU)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->instruction) 
                                                    >> 0xdU)))) {
                                            vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_4 = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        if ((1U & (IData)(vlTOPp->instruction))) {
                            if ((0x8000U & (IData)(vlTOPp->instruction))) {
                                if ((1U & (~ ((IData)(vlTOPp->instruction) 
                                              >> 0xeU)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->instruction) 
                                                  >> 0xdU)))) {
                                        vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_4 = 1U;
                                    }
                                }
                            }
                        } else {
                            if ((0x8000U & (IData)(vlTOPp->instruction))) {
                                if ((1U & (~ ((IData)(vlTOPp->instruction) 
                                              >> 0xeU)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->instruction) 
                                                  >> 0xdU)))) {
                                        vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_4 = 1U;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else {
            if ((1U & (~ ((IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state)))) {
                    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_4 = 0U;
                }
            }
        }
    }
    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_5 = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((4U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
            if ((2U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                if ((1U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_5 = 0U;
                }
            } else {
                if ((1U & (~ (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state)))) {
                    if ((2U & (IData)(vlTOPp->instruction))) {
                        if ((1U & (IData)(vlTOPp->instruction))) {
                            if ((1U & (~ ((IData)(vlTOPp->instruction) 
                                          >> 2U)))) {
                                if ((0x8000U & (IData)(vlTOPp->instruction))) {
                                    if ((1U & (~ ((IData)(vlTOPp->instruction) 
                                                  >> 0xeU)))) {
                                        if ((0x2000U 
                                             & (IData)(vlTOPp->instruction))) {
                                            vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_5 = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        if ((1U & (IData)(vlTOPp->instruction))) {
                            if ((0x8000U & (IData)(vlTOPp->instruction))) {
                                if ((1U & (~ ((IData)(vlTOPp->instruction) 
                                              >> 0xeU)))) {
                                    if ((0x2000U & (IData)(vlTOPp->instruction))) {
                                        vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_5 = 1U;
                                    }
                                }
                            }
                        } else {
                            if ((0x8000U & (IData)(vlTOPp->instruction))) {
                                if ((1U & (~ ((IData)(vlTOPp->instruction) 
                                              >> 0xeU)))) {
                                    if ((0x2000U & (IData)(vlTOPp->instruction))) {
                                        vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_5 = 1U;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else {
            if ((1U & (~ ((IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state)))) {
                    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_5 = 0U;
                }
            }
        }
    }
    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_6 = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((4U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
            if ((2U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                if ((1U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_6 = 0U;
                }
            } else {
                if ((1U & (~ (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state)))) {
                    if ((2U & (IData)(vlTOPp->instruction))) {
                        if ((1U & (IData)(vlTOPp->instruction))) {
                            if ((1U & (~ ((IData)(vlTOPp->instruction) 
                                          >> 2U)))) {
                                if ((0x8000U & (IData)(vlTOPp->instruction))) {
                                    if ((0x4000U & (IData)(vlTOPp->instruction))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->instruction) 
                                                    >> 0xdU)))) {
                                            vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_6 = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        if ((1U & (IData)(vlTOPp->instruction))) {
                            if ((0x8000U & (IData)(vlTOPp->instruction))) {
                                if ((0x4000U & (IData)(vlTOPp->instruction))) {
                                    if ((1U & (~ ((IData)(vlTOPp->instruction) 
                                                  >> 0xdU)))) {
                                        vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_6 = 1U;
                                    }
                                }
                            }
                        } else {
                            if ((0x8000U & (IData)(vlTOPp->instruction))) {
                                if ((0x4000U & (IData)(vlTOPp->instruction))) {
                                    if ((1U & (~ ((IData)(vlTOPp->instruction) 
                                                  >> 0xdU)))) {
                                        vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_6 = 1U;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else {
            if ((1U & (~ ((IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state)))) {
                    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_6 = 0U;
                }
            }
        }
    }
    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_7 = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((4U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
            if ((2U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                if ((1U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_7 = 0U;
                }
            } else {
                if ((1U & (~ (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state)))) {
                    if ((2U & (IData)(vlTOPp->instruction))) {
                        if ((1U & (IData)(vlTOPp->instruction))) {
                            if ((1U & (~ ((IData)(vlTOPp->instruction) 
                                          >> 2U)))) {
                                if ((0x8000U & (IData)(vlTOPp->instruction))) {
                                    if ((0x4000U & (IData)(vlTOPp->instruction))) {
                                        if ((0x2000U 
                                             & (IData)(vlTOPp->instruction))) {
                                            vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_7 = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        if ((1U & (IData)(vlTOPp->instruction))) {
                            if ((0x8000U & (IData)(vlTOPp->instruction))) {
                                if ((0x4000U & (IData)(vlTOPp->instruction))) {
                                    if ((0x2000U & (IData)(vlTOPp->instruction))) {
                                        vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_7 = 1U;
                                    }
                                }
                            }
                        } else {
                            if ((0x8000U & (IData)(vlTOPp->instruction))) {
                                if ((0x4000U & (IData)(vlTOPp->instruction))) {
                                    if ((0x2000U & (IData)(vlTOPp->instruction))) {
                                        vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_7 = 1U;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else {
            if ((1U & (~ ((IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state)))) {
                    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_7 = 0U;
                }
            }
        }
    }
    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_sel = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((4U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
            if ((2U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                if ((1U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_sel = 0U;
                }
            }
        } else {
            if ((2U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                if ((1U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                    if ((1U & (~ ((IData)(vlTOPp->instruction) 
                                  >> 1U)))) {
                        vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_sel 
                            = (7U & ((IData)(vlTOPp->instruction) 
                                     >> 2U));
                    }
                }
            } else {
                if ((1U & (~ (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state)))) {
                    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_sel = 0U;
                }
            }
        }
    }
    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_done2 = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((4U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
            vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_done2 
                = (1U & ((~ ((IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state) 
                             >> 1U)) & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state)));
        } else {
            if ((1U & (~ ((IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state)))) {
                    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_done2 = 0U;
                }
            }
        }
    }
    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_done1 = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((4U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
            vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_done1 
                = (1U & ((~ ((IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state) 
                             >> 1U)) & (~ (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))));
        } else {
            if ((1U & (~ ((IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state)))) {
                    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_done1 = 0U;
                }
            }
        }
    }
    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_mux2_sel = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((4U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
            if ((2U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                if ((1U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_mux2_sel = 0U;
                }
            } else {
                if ((1U & (~ (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state)))) {
                    if ((2U & (IData)(vlTOPp->instruction))) {
                        if ((1U & (IData)(vlTOPp->instruction))) {
                            vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_mux2_sel 
                                = (1U & (~ ((IData)(vlTOPp->instruction) 
                                            >> 2U)));
                        }
                    } else {
                        vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_mux2_sel = 0U;
                    }
                }
            }
        } else {
            if ((2U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                if ((1U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                    if ((2U & (IData)(vlTOPp->instruction))) {
                        if ((1U & (IData)(vlTOPp->instruction))) {
                            vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_mux2_sel = 1U;
                        }
                    } else {
                        vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_mux2_sel = 0U;
                    }
                } else {
                    if ((2U & (IData)(vlTOPp->instruction))) {
                        if ((1U & (IData)(vlTOPp->instruction))) {
                            vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_mux2_sel = 1U;
                        }
                    } else {
                        vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_mux2_sel = 0U;
                    }
                }
            } else {
                if ((1U & (~ (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state)))) {
                    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_mux2_sel = 0U;
                }
            }
        }
    }
    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_imm_val = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((4U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
            if ((2U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                if ((1U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_imm_val = 0U;
                }
            }
        } else {
            if ((2U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                if ((1U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                    if ((1U & (~ ((IData)(vlTOPp->instruction) 
                                  >> 1U)))) {
                        vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_imm_val 
                            = ((1U & (IData)(vlTOPp->instruction))
                                ? (0xffU & ((IData)(vlTOPp->instruction) 
                                            >> 5U))
                                : 0U);
                    }
                }
            } else {
                if ((1U & (~ (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state)))) {
                    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_imm_val = 0U;
                }
            }
        }
    }
    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_mux_sel = 0xfU;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((4U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
            if ((2U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                if ((1U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_mux_sel = 0xfU;
                }
            }
        } else {
            if ((2U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                if ((1U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                    if ((1U & (~ ((IData)(vlTOPp->instruction) 
                                  >> 1U)))) {
                        vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_mux_sel 
                            = ((1U & (IData)(vlTOPp->instruction))
                                ? 8U : (7U & ((IData)(vlTOPp->instruction) 
                                              >> 0xaU)));
                    }
                } else {
                    if ((1U & (~ ((IData)(vlTOPp->instruction) 
                                  >> 1U)))) {
                        vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_mux_sel 
                            = ((1U & (IData)(vlTOPp->instruction))
                                ? (7U & ((IData)(vlTOPp->instruction) 
                                         >> 0xdU)) : 
                               (7U & ((IData)(vlTOPp->instruction) 
                                      >> 0xdU)));
                    }
                }
            } else {
                if ((1U & (~ (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state)))) {
                    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_mux_sel = 0xfU;
                }
            }
        }
    }
    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_s = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((4U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
            if ((2U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                if ((1U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_s = 0U;
                }
            }
        } else {
            if ((2U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                if ((1U & (~ (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state)))) {
                    if ((1U & (~ ((IData)(vlTOPp->instruction) 
                                  >> 1U)))) {
                        vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_s = 1U;
                    }
                }
            } else {
                if ((1U & (~ (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state)))) {
                    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_s = 0U;
                }
            }
        }
    }
    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_register_memory = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((4U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
            if ((2U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                if ((1U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_register_memory = 0U;
                }
            }
        } else {
            if ((2U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                if ((1U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                    if ((2U & (IData)(vlTOPp->instruction))) {
                        if ((1U & (IData)(vlTOPp->instruction))) {
                            vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_register_memory = 1U;
                        }
                    }
                } else {
                    if ((2U & (IData)(vlTOPp->instruction))) {
                        if ((1U & (IData)(vlTOPp->instruction))) {
                            vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_register_memory = 1U;
                        }
                    }
                }
            } else {
                if ((1U & (~ (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state)))) {
                    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_register_memory = 0U;
                }
            }
        }
    }
    vlTOPp->done2 = vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_done2;
    vlTOPp->done1 = vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_done1;
    if (vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_mux2_sel) {
        if (vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_mux2_sel) {
            vlTOPp->bitty_core__DOT__myMux2__DOT__reg_mux2_out 
                = vlTOPp->bitty_core__DOT__Reg_M__DOT__reg_d_out;
        }
    } else {
        vlTOPp->bitty_core__DOT__myMux2__DOT__reg_mux2_out 
            = vlTOPp->bitty_core__DOT__Reg_C__DOT__reg_d_out;
    }
    vlTOPp->bitty_core__DOT__myMux__DOT__reg_mux_out 
        = ((8U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_mux_sel))
            ? ((4U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_mux_sel))
                ? 0U : ((2U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_mux_sel))
                         ? 0U : ((1U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_mux_sel))
                                  ? 0U : (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_imm_val))))
            : ((4U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_mux_sel))
                ? ((2U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_mux_sel))
                    ? ((1U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_mux_sel))
                        ? (IData)(vlTOPp->Reg_7_Out)
                        : (IData)(vlTOPp->Reg_6_Out))
                    : ((1U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_mux_sel))
                        ? (IData)(vlTOPp->Reg_5_Out)
                        : (IData)(vlTOPp->Reg_4_Out)))
                : ((2U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_mux_sel))
                    ? ((1U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_mux_sel))
                        ? (IData)(vlTOPp->Reg_3_Out)
                        : (IData)(vlTOPp->Reg_2_Out))
                    : ((1U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_mux_sel))
                        ? (IData)(vlTOPp->Reg_1_Out)
                        : (IData)(vlTOPp->Reg_0_Out)))));
}

void Vbitty_core::_eval(Vbitty_core__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core::_eval\n"); );
    Vbitty_core* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((IData)(vlTOPp->reset) & (~ (IData)(vlTOPp->__Vclklast__TOP__reset))))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
    }
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__4(vlSymsp);
    }
    vlTOPp->_combo__TOP__5(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__reset = vlTOPp->reset;
}

VL_INLINE_OPT QData Vbitty_core::_change_request(Vbitty_core__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core::_change_request\n"); );
    Vbitty_core* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vbitty_core::_change_request_1(Vbitty_core__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core::_change_request_1\n"); );
    Vbitty_core* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vbitty_core::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((run & 0xfeU))) {
        Verilated::overWidthError("run");}
}
#endif  // VL_DEBUG
