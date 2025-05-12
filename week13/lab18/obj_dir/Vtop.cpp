// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"
#include "Vtop__Syms.h"

//==========

void Vtop::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtop::eval\n"); );
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("rtl/top.v", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vtop::_eval_initial_loop(Vtop__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("rtl/top.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__1\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->reset) {
        vlTOPp->top__DOT__my_bitty_core__DOT__Reg_7__DOT__reg_d_out = 0U;
    } else {
        if (vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_en_7) {
            vlTOPp->top__DOT__my_bitty_core__DOT__Reg_7__DOT__reg_d_out 
                = vlTOPp->top__DOT__my_bitty_core__DOT__Reg_C__DOT__reg_d_out;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top__DOT__my_bitty_core__DOT__Reg_6__DOT__reg_d_out = 0U;
    } else {
        if (vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_en_6) {
            vlTOPp->top__DOT__my_bitty_core__DOT__Reg_6__DOT__reg_d_out 
                = vlTOPp->top__DOT__my_bitty_core__DOT__Reg_C__DOT__reg_d_out;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top__DOT__my_bitty_core__DOT__Reg_5__DOT__reg_d_out = 0U;
    } else {
        if (vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_en_5) {
            vlTOPp->top__DOT__my_bitty_core__DOT__Reg_5__DOT__reg_d_out 
                = vlTOPp->top__DOT__my_bitty_core__DOT__Reg_C__DOT__reg_d_out;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top__DOT__my_bitty_core__DOT__Reg_4__DOT__reg_d_out = 0U;
    } else {
        if (vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_en_4) {
            vlTOPp->top__DOT__my_bitty_core__DOT__Reg_4__DOT__reg_d_out 
                = vlTOPp->top__DOT__my_bitty_core__DOT__Reg_C__DOT__reg_d_out;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top__DOT__my_bitty_core__DOT__Reg_3__DOT__reg_d_out = 0U;
    } else {
        if (vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_en_3) {
            vlTOPp->top__DOT__my_bitty_core__DOT__Reg_3__DOT__reg_d_out 
                = vlTOPp->top__DOT__my_bitty_core__DOT__Reg_C__DOT__reg_d_out;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top__DOT__my_bitty_core__DOT__Reg_2__DOT__reg_d_out = 0U;
    } else {
        if (vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_en_2) {
            vlTOPp->top__DOT__my_bitty_core__DOT__Reg_2__DOT__reg_d_out 
                = vlTOPp->top__DOT__my_bitty_core__DOT__Reg_C__DOT__reg_d_out;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top__DOT__my_bitty_core__DOT__Reg_1__DOT__reg_d_out = 0U;
    } else {
        if (vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_en_1) {
            vlTOPp->top__DOT__my_bitty_core__DOT__Reg_1__DOT__reg_d_out 
                = vlTOPp->top__DOT__my_bitty_core__DOT__Reg_C__DOT__reg_d_out;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top__DOT__my_bitty_core__DOT__Reg_0__DOT__reg_d_out = 0U;
    } else {
        if (vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_en_0) {
            vlTOPp->top__DOT__my_bitty_core__DOT__Reg_0__DOT__reg_d_out 
                = vlTOPp->top__DOT__my_bitty_core__DOT__Reg_C__DOT__reg_d_out;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state = 0U;
    } else {
        if (vlTOPp->run) {
            vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state 
                = vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_next_state;
        }
    }
    vlTOPp->top__DOT__reg_top_out = ((IData)(vlTOPp->reset)
                                      ? 0U : (IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__reg_instruction_out));
    if (vlTOPp->reset) {
        vlTOPp->top__DOT__my_bitty_core__DOT__Reg_C__DOT__reg_d_out = 0U;
    } else {
        if (vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_en_c) {
            vlTOPp->top__DOT__my_bitty_core__DOT__Reg_C__DOT__reg_d_out 
                = (0xffffU & ((4U & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_sel))
                               ? ((2U & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_sel))
                                   ? ((1U & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_sel))
                                       ? (((IData)(vlTOPp->top__DOT__my_bitty_core__DOT__Reg_S__DOT__reg_d_out) 
                                           == (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myMux__DOT__reg_mux_out))
                                           ? 0U : (
                                                   ((IData)(vlTOPp->top__DOT__my_bitty_core__DOT__Reg_S__DOT__reg_d_out) 
                                                    > (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myMux__DOT__reg_mux_out))
                                                    ? 1U
                                                    : 2U))
                                       : ((0xfU >= 
                                           (0xfU & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myMux__DOT__reg_mux_out)))
                                           ? ((IData)(vlTOPp->top__DOT__my_bitty_core__DOT__Reg_S__DOT__reg_d_out) 
                                              >> (0xfU 
                                                  & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myMux__DOT__reg_mux_out)))
                                           : 0U)) : 
                                  ((1U & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_sel))
                                    ? ((0xfU >= (0xfU 
                                                 & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myMux__DOT__reg_mux_out)))
                                        ? ((IData)(vlTOPp->top__DOT__my_bitty_core__DOT__Reg_S__DOT__reg_d_out) 
                                           << (0xfU 
                                               & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myMux__DOT__reg_mux_out)))
                                        : 0U) : ((IData)(vlTOPp->top__DOT__my_bitty_core__DOT__Reg_S__DOT__reg_d_out) 
                                                 ^ (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myMux__DOT__reg_mux_out))))
                               : ((2U & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_sel))
                                   ? ((1U & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_sel))
                                       ? ((IData)(vlTOPp->top__DOT__my_bitty_core__DOT__Reg_S__DOT__reg_d_out) 
                                          | (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myMux__DOT__reg_mux_out))
                                       : ((IData)(vlTOPp->top__DOT__my_bitty_core__DOT__Reg_S__DOT__reg_d_out) 
                                          & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myMux__DOT__reg_mux_out)))
                                   : ((1U & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_sel))
                                       ? ((IData)(vlTOPp->top__DOT__my_bitty_core__DOT__Reg_S__DOT__reg_d_out) 
                                          - (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myMux__DOT__reg_mux_out))
                                       : ((IData)(vlTOPp->top__DOT__my_bitty_core__DOT__Reg_S__DOT__reg_d_out) 
                                          + (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myMux__DOT__reg_mux_out))))));
        }
    }
    vlTOPp->__Vtableidx1 = vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state;
    vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_next_state 
        = vlTOPp->__Vtable1_top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_next_state
        [vlTOPp->__Vtableidx1];
    vlTOPp->top_out = vlTOPp->top__DOT__reg_top_out;
    vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__reg_instruction_out 
        = ((IData)(vlTOPp->reset) ? 0U : (IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__my_memory__DOT__out_reg));
    if (vlTOPp->reset) {
        vlTOPp->top__DOT__my_bitty_core__DOT__Reg_S__DOT__reg_d_out = 0U;
    } else {
        if (vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_en_s) {
            vlTOPp->top__DOT__my_bitty_core__DOT__Reg_S__DOT__reg_d_out 
                = vlTOPp->top__DOT__my_bitty_core__DOT__myMux__DOT__reg_mux_out;
        }
    }
}

VL_INLINE_OPT void Vtop::_sequent__TOP__2(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__2\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__my_memory__DOT__out_reg 
        = vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__my_memory__DOT__memory_cell
        [vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__my_pc__DOT__reg_d_out];
}

VL_INLINE_OPT void Vtop::_combo__TOP__5(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_combo__TOP__5\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_en_6 = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((4U & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state))) {
            if ((2U & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_en_6 = 0U;
            } else {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state)))) {
                    if ((2U != (3U & (IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__reg_instruction_out)))) {
                        if ((0x8000U & (IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__reg_instruction_out))) {
                            if ((0x4000U & (IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__reg_instruction_out))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__reg_instruction_out) 
                                              >> 0xdU)))) {
                                    vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_en_6 = 1U;
                                }
                            }
                        }
                    }
                }
            }
        } else {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state)))) {
                    vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_en_6 = 0U;
                }
            }
        }
    }
    vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_en_2 = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((4U & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state))) {
            if ((2U & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_en_2 = 0U;
            } else {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state)))) {
                    if ((2U != (3U & (IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__reg_instruction_out)))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__reg_instruction_out) 
                                      >> 0xfU)))) {
                            if ((0x4000U & (IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__reg_instruction_out))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__reg_instruction_out) 
                                              >> 0xdU)))) {
                                    vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_en_2 = 1U;
                                }
                            }
                        }
                    }
                }
            }
        } else {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state)))) {
                    vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_en_2 = 0U;
                }
            }
        }
    }
    vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_en_0 = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((4U & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state))) {
            if ((2U & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_en_0 = 0U;
            } else {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state)))) {
                    if ((2U != (3U & (IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__reg_instruction_out)))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__reg_instruction_out) 
                                      >> 0xfU)))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__reg_instruction_out) 
                                          >> 0xeU)))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__reg_instruction_out) 
                                              >> 0xdU)))) {
                                    vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_en_0 = 1U;
                                }
                            }
                        }
                    }
                }
            }
        } else {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state)))) {
                    vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_en_0 = 0U;
                }
            }
        }
    }
    vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_en_c = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((4U & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state))) {
            if ((2U & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_en_c = 0U;
            }
        } else {
            if ((2U & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                if ((1U & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                    vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_en_c 
                        = ((0U == (3U & (IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__reg_instruction_out))) 
                           | ((1U == (3U & (IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__reg_instruction_out))) 
                              | (2U != (3U & (IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__reg_instruction_out)))));
                }
            } else {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state)))) {
                    vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_en_c = 0U;
                }
            }
        }
    }
    vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_en_1 = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((4U & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state))) {
            if ((2U & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_en_1 = 0U;
            } else {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state)))) {
                    if ((2U != (3U & (IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__reg_instruction_out)))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__reg_instruction_out) 
                                      >> 0xfU)))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__reg_instruction_out) 
                                          >> 0xeU)))) {
                                if ((0x2000U & (IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__reg_instruction_out))) {
                                    vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_en_1 = 1U;
                                }
                            }
                        }
                    }
                }
            }
        } else {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state)))) {
                    vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_en_1 = 0U;
                }
            }
        }
    }
    vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_en_3 = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((4U & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state))) {
            if ((2U & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_en_3 = 0U;
            } else {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state)))) {
                    if ((2U != (3U & (IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__reg_instruction_out)))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__reg_instruction_out) 
                                      >> 0xfU)))) {
                            if ((0x4000U & (IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__reg_instruction_out))) {
                                if ((0x2000U & (IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__reg_instruction_out))) {
                                    vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_en_3 = 1U;
                                }
                            }
                        }
                    }
                }
            }
        } else {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state)))) {
                    vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_en_3 = 0U;
                }
            }
        }
    }
    vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_en_4 = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((4U & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state))) {
            if ((2U & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_en_4 = 0U;
            } else {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state)))) {
                    if ((2U != (3U & (IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__reg_instruction_out)))) {
                        if ((0x8000U & (IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__reg_instruction_out))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__reg_instruction_out) 
                                          >> 0xeU)))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__reg_instruction_out) 
                                              >> 0xdU)))) {
                                    vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_en_4 = 1U;
                                }
                            }
                        }
                    }
                }
            }
        } else {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state)))) {
                    vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_en_4 = 0U;
                }
            }
        }
    }
    vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_en_5 = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((4U & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state))) {
            if ((2U & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_en_5 = 0U;
            } else {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state)))) {
                    if ((2U != (3U & (IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__reg_instruction_out)))) {
                        if ((0x8000U & (IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__reg_instruction_out))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__reg_instruction_out) 
                                          >> 0xeU)))) {
                                if ((0x2000U & (IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__reg_instruction_out))) {
                                    vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_en_5 = 1U;
                                }
                            }
                        }
                    }
                }
            }
        } else {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state)))) {
                    vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_en_5 = 0U;
                }
            }
        }
    }
    vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_en_7 = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((4U & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state))) {
            if ((2U & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_en_7 = 0U;
            } else {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state)))) {
                    if ((2U != (3U & (IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__reg_instruction_out)))) {
                        if ((0x8000U & (IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__reg_instruction_out))) {
                            if ((0x4000U & (IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__reg_instruction_out))) {
                                if ((0x2000U & (IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__reg_instruction_out))) {
                                    vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_en_7 = 1U;
                                }
                            }
                        }
                    }
                }
            }
        } else {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state)))) {
                    vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_en_7 = 0U;
                }
            }
        }
    }
    vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_sel = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((4U & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state))) {
            if ((2U & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_sel = 0U;
            }
        } else {
            if ((2U & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                if ((1U & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                    vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_sel 
                        = (7U & ((IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__reg_instruction_out) 
                                 >> 2U));
                }
            } else {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state)))) {
                    vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_sel = 0U;
                }
            }
        }
    }
    vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_imm_val = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((4U & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state))) {
            if ((2U & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_imm_val = 0U;
            }
        } else {
            if ((2U & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                if ((1U & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                    if ((0U != (3U & (IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__reg_instruction_out)))) {
                        if ((1U == (3U & (IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__reg_instruction_out)))) {
                            vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_imm_val 
                                = (0xffU & ((IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__reg_instruction_out) 
                                            >> 5U));
                        }
                    }
                }
            } else {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state)))) {
                    vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_imm_val = 0U;
                }
            }
        }
    }
    vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_mux_sel = 0xfU;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((4U & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state))) {
            if ((2U & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_mux_sel = 0xfU;
            }
        } else {
            if ((2U & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_mux_sel 
                    = ((1U & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state))
                        ? ((0U == (3U & (IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__reg_instruction_out)))
                            ? (7U & ((IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__reg_instruction_out) 
                                     >> 0xaU)) : ((1U 
                                                   == 
                                                   (3U 
                                                    & (IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__reg_instruction_out)))
                                                   ? 8U
                                                   : 
                                                  ((2U 
                                                    == 
                                                    (3U 
                                                     & (IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__reg_instruction_out)))
                                                    ? 
                                                   (7U 
                                                    & ((IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__reg_instruction_out) 
                                                       >> 0xaU))
                                                    : 
                                                   (7U 
                                                    & ((IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__reg_instruction_out) 
                                                       >> 0xaU)))))
                        : (7U & ((IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__reg_instruction_out) 
                                 >> 0xdU)));
            } else {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state)))) {
                    vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_mux_sel = 0xfU;
                }
            }
        }
    }
    vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_en_s = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((4U & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state))) {
            if ((2U & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_en_s = 0U;
            }
        } else {
            if ((2U & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state)))) {
                    vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_en_s = 1U;
                }
            } else {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state)))) {
                    vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_en_s = 0U;
                }
            }
        }
    }
    vlTOPp->top__DOT__my_bitty_core__DOT__myMux__DOT__reg_mux_out 
        = ((8U & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_mux_sel))
            ? ((4U & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_mux_sel))
                ? 0U : ((2U & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_mux_sel))
                         ? 0U : ((1U & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_mux_sel))
                                  ? 0U : (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_imm_val))))
            : ((4U & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_mux_sel))
                ? ((2U & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_mux_sel))
                    ? ((1U & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_mux_sel))
                        ? (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__Reg_7__DOT__reg_d_out)
                        : (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__Reg_6__DOT__reg_d_out))
                    : ((1U & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_mux_sel))
                        ? (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__Reg_5__DOT__reg_d_out)
                        : (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__Reg_4__DOT__reg_d_out)))
                : ((2U & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_mux_sel))
                    ? ((1U & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_mux_sel))
                        ? (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__Reg_3__DOT__reg_d_out)
                        : (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__Reg_2__DOT__reg_d_out))
                    : ((1U & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_mux_sel))
                        ? (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__Reg_1__DOT__reg_d_out)
                        : (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__Reg_0__DOT__reg_d_out)))));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__6(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__6\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->reset) {
        vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__my_pc__DOT__reg_d_out = 0U;
    } else {
        if (vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_done2) {
            vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__my_pc__DOT__reg_d_out 
                = vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__my_branch_logic__DOT__Reg_branch_logic_Out__DOT__reg_d_out;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__my_branch_logic__DOT__Reg_branch_logic_Out__DOT__reg_d_out = 0U;
    } else {
        if (vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_done1) {
            vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__my_branch_logic__DOT__Reg_branch_logic_Out__DOT__reg_d_out 
                = (0xffU & (IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__my_branch_logic__DOT__reg_new_pc));
        }
    }
}

VL_INLINE_OPT void Vtop::_combo__TOP__7(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_combo__TOP__7\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_done2 = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((4U & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state))) {
            vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_done2 
                = (1U & ((~ ((IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state) 
                             >> 1U)) & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state)));
        } else {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state)))) {
                    vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_done2 = 0U;
                }
            }
        }
    }
    vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_done1 = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((4U & (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state))) {
            vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_done1 
                = (1U & ((~ ((IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state) 
                             >> 1U)) & (~ (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state))));
        } else {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state)))) {
                    vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_done1 = 0U;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__my_branch_logic__DOT__reg_new_pc = 0U;
    } else {
        if (vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_done1) {
            vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__my_branch_logic__DOT__reg_new_pc 
                = (0xffffU & ((2U == (3U & (IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__my_memory__DOT__out_reg)))
                               ? ((0U == (3U & ((IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__my_memory__DOT__out_reg) 
                                                >> 2U)))
                                   ? ((0U == (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__Reg_C__DOT__reg_d_out))
                                       ? ((IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__my_pc__DOT__reg_d_out) 
                                          + (0xfffU 
                                             & ((IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__my_memory__DOT__out_reg) 
                                                >> 4U)))
                                       : ((IData)(1U) 
                                          + (IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__my_pc__DOT__reg_d_out)))
                                   : ((1U == (3U & 
                                              ((IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__my_memory__DOT__out_reg) 
                                               >> 2U)))
                                       ? ((1U == (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__Reg_C__DOT__reg_d_out))
                                           ? ((IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__my_pc__DOT__reg_d_out) 
                                              + (0xfffU 
                                                 & ((IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__my_memory__DOT__out_reg) 
                                                    >> 4U)))
                                           : ((IData)(1U) 
                                              + (IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__my_pc__DOT__reg_d_out)))
                                       : ((2U == (3U 
                                                  & ((IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__my_memory__DOT__out_reg) 
                                                     >> 2U)))
                                           ? ((2U == (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__Reg_C__DOT__reg_d_out))
                                               ? ((IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__my_pc__DOT__reg_d_out) 
                                                  + 
                                                  (0xfffU 
                                                   & ((IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__my_memory__DOT__out_reg) 
                                                      >> 4U)))
                                               : ((IData)(1U) 
                                                  + (IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__my_pc__DOT__reg_d_out)))
                                           : ((0U == (IData)(vlTOPp->top__DOT__my_bitty_core__DOT__Reg_C__DOT__reg_d_out))
                                               ? ((IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__my_pc__DOT__reg_d_out) 
                                                  + 
                                                  (0xfffU 
                                                   & ((IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__my_memory__DOT__out_reg) 
                                                      >> 4U)))
                                               : ((IData)(1U) 
                                                  + (IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__my_pc__DOT__reg_d_out))))))
                               : ((IData)(1U) + (IData)(vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__my_pc__DOT__reg_d_out))));
        }
    }
}

void Vtop::_eval(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((IData)(vlTOPp->reset) & (~ (IData)(vlTOPp->__Vclklast__TOP__reset))))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
    }
    vlTOPp->_combo__TOP__5(vlSymsp);
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((IData)(vlTOPp->reset) & (~ (IData)(vlTOPp->__Vclklast__TOP__reset))))) {
        vlTOPp->_sequent__TOP__6(vlSymsp);
    }
    vlTOPp->_combo__TOP__7(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__reset = vlTOPp->reset;
}

VL_INLINE_OPT QData Vtop::_change_request(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_change_request\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vtop::_change_request_1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_change_request_1\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vtop::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((run & 0xfeU))) {
        Verilated::overWidthError("run");}
}
#endif  // VL_DEBUG
