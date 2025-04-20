// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbitty_core.h for the primary calling header

#include "Vbitty_core.h"
#include "Vbitty_core__Syms.h"

//==========
CData/*1:0*/ Vbitty_core::__Vtable1_bitty_core__DOT__myControlUnit__DOT__reg_next_state[16];

VL_CTOR_IMP(Vbitty_core) {
    Vbitty_core__Syms* __restrict vlSymsp = __VlSymsp = new Vbitty_core__Syms(this, name());
    Vbitty_core* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vbitty_core::__Vconfigure(Vbitty_core__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vbitty_core::~Vbitty_core() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vbitty_core::_settle__TOP__2(Vbitty_core__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core::_settle__TOP__2\n"); );
    Vbitty_core* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Reg_Inst_Out = vlTOPp->bitty_core__DOT__Reg_Inst__DOT__reg_d_out;
    vlTOPp->Reg_S_Out = vlTOPp->bitty_core__DOT__Reg_S__DOT__reg_d_out;
    vlTOPp->Reg_C_Out = vlTOPp->bitty_core__DOT__Reg_C__DOT__reg_d_out;
    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_i = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((1U & (~ ((IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state) 
                      >> 1U)))) {
            if ((1U & (~ (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state)))) {
                vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_i = 1U;
            }
        }
    }
    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_s = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((1U & (~ ((IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state) 
                      >> 1U)))) {
            if ((1U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_s = 1U;
            }
        }
    }
    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_sel = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((2U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
            if ((1U & (~ (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state)))) {
                vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_sel 
                    = (7U & ((IData)(vlTOPp->instruction) 
                             >> 2U));
            }
        }
    }
    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_7 = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((2U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
            if ((1U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
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
    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_6 = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((2U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
            if ((1U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
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
    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_5 = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((2U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
            if ((1U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
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
    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_4 = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((2U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
            if ((1U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
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
    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_3 = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((2U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
            if ((1U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
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
    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_2 = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((2U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
            if ((1U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
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
    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_1 = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((2U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
            if ((1U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
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
    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_0 = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((2U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
            if ((1U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
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
    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_c = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((2U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
            if ((1U & (~ (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state)))) {
                vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_en_c 
                    = ((0U == (3U & (IData)(vlTOPp->instruction))) 
                       | (1U != (3U & (IData)(vlTOPp->instruction))));
            }
        }
    }
    vlTOPp->__Vtableidx1 = (((IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_run_prev) 
                             << 3U) | (((IData)(vlTOPp->run) 
                                        << 2U) | (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state)));
    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_next_state 
        = vlTOPp->__Vtable1_bitty_core__DOT__myControlUnit__DOT__reg_next_state
        [vlTOPp->__Vtableidx1];
    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_done = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((2U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
            if ((1U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_done = 1U;
            }
        }
    }
    vlTOPp->Reg_0_Out = vlTOPp->bitty_core__DOT__Reg_0__DOT__reg_d_out;
    vlTOPp->Reg_1_Out = vlTOPp->bitty_core__DOT__Reg_1__DOT__reg_d_out;
    vlTOPp->Reg_2_Out = vlTOPp->bitty_core__DOT__Reg_2__DOT__reg_d_out;
    vlTOPp->Reg_3_Out = vlTOPp->bitty_core__DOT__Reg_3__DOT__reg_d_out;
    vlTOPp->Reg_4_Out = vlTOPp->bitty_core__DOT__Reg_4__DOT__reg_d_out;
    vlTOPp->Reg_5_Out = vlTOPp->bitty_core__DOT__Reg_5__DOT__reg_d_out;
    vlTOPp->Reg_6_Out = vlTOPp->bitty_core__DOT__Reg_6__DOT__reg_d_out;
    vlTOPp->Reg_7_Out = vlTOPp->bitty_core__DOT__Reg_7__DOT__reg_d_out;
    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_mux_sel = 0xfU;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((2U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
            if ((1U & (~ (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state)))) {
                vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_mux_sel 
                    = ((0U == (3U & (IData)(vlTOPp->instruction)))
                        ? (7U & ((IData)(vlTOPp->instruction) 
                                 >> 0xaU)) : ((1U == 
                                               (3U 
                                                & (IData)(vlTOPp->instruction)))
                                               ? 8U
                                               : (7U 
                                                  & ((IData)(vlTOPp->instruction) 
                                                     >> 0xaU))));
            }
        } else {
            if ((1U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
                vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_mux_sel 
                    = (7U & ((IData)(vlTOPp->instruction) 
                             >> 0xdU));
            }
        }
    }
    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_imm_val = 0U;
    if (((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->run))) {
        if ((2U & (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state))) {
            if ((1U & (~ (IData)(vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state)))) {
                if ((0U != (3U & (IData)(vlTOPp->instruction)))) {
                    if ((1U == (3U & (IData)(vlTOPp->instruction)))) {
                        vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_imm_val 
                            = (0xffU & ((IData)(vlTOPp->instruction) 
                                        >> 5U));
                    }
                }
            }
        }
    }
    vlTOPp->done = vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_done;
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

void Vbitty_core::_eval_initial(Vbitty_core__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core::_eval_initial\n"); );
    Vbitty_core* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void Vbitty_core::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core::final\n"); );
    // Variables
    Vbitty_core__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vbitty_core* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vbitty_core::_eval_settle(Vbitty_core__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core::_eval_settle\n"); );
    Vbitty_core* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

void Vbitty_core::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    run = VL_RAND_RESET_I(1);
    instruction = VL_RAND_RESET_I(16);
    done = VL_RAND_RESET_I(1);
    Reg_Inst_Out = VL_RAND_RESET_I(16);
    Reg_S_Out = VL_RAND_RESET_I(16);
    Reg_C_Out = VL_RAND_RESET_I(16);
    Reg_0_Out = VL_RAND_RESET_I(16);
    Reg_1_Out = VL_RAND_RESET_I(16);
    Reg_2_Out = VL_RAND_RESET_I(16);
    Reg_3_Out = VL_RAND_RESET_I(16);
    Reg_4_Out = VL_RAND_RESET_I(16);
    Reg_5_Out = VL_RAND_RESET_I(16);
    Reg_6_Out = VL_RAND_RESET_I(16);
    Reg_7_Out = VL_RAND_RESET_I(16);
    bitty_core__DOT__myControlUnit__DOT__reg_state = VL_RAND_RESET_I(2);
    bitty_core__DOT__myControlUnit__DOT__reg_next_state = VL_RAND_RESET_I(2);
    bitty_core__DOT__myControlUnit__DOT__reg_run_prev = VL_RAND_RESET_I(1);
    bitty_core__DOT__myControlUnit__DOT__reg_en_s = VL_RAND_RESET_I(1);
    bitty_core__DOT__myControlUnit__DOT__reg_en_c = VL_RAND_RESET_I(1);
    bitty_core__DOT__myControlUnit__DOT__reg_en_i = VL_RAND_RESET_I(1);
    bitty_core__DOT__myControlUnit__DOT__reg_en_0 = VL_RAND_RESET_I(1);
    bitty_core__DOT__myControlUnit__DOT__reg_en_1 = VL_RAND_RESET_I(1);
    bitty_core__DOT__myControlUnit__DOT__reg_en_2 = VL_RAND_RESET_I(1);
    bitty_core__DOT__myControlUnit__DOT__reg_en_3 = VL_RAND_RESET_I(1);
    bitty_core__DOT__myControlUnit__DOT__reg_en_4 = VL_RAND_RESET_I(1);
    bitty_core__DOT__myControlUnit__DOT__reg_en_5 = VL_RAND_RESET_I(1);
    bitty_core__DOT__myControlUnit__DOT__reg_en_6 = VL_RAND_RESET_I(1);
    bitty_core__DOT__myControlUnit__DOT__reg_en_7 = VL_RAND_RESET_I(1);
    bitty_core__DOT__myControlUnit__DOT__reg_done = VL_RAND_RESET_I(1);
    bitty_core__DOT__myControlUnit__DOT__reg_sel = VL_RAND_RESET_I(3);
    bitty_core__DOT__myControlUnit__DOT__reg_mux_sel = VL_RAND_RESET_I(4);
    bitty_core__DOT__myControlUnit__DOT__reg_imm_val = VL_RAND_RESET_I(16);
    bitty_core__DOT__Reg_Inst__DOT__reg_d_out = VL_RAND_RESET_I(16);
    bitty_core__DOT__Reg_S__DOT__reg_d_out = VL_RAND_RESET_I(16);
    bitty_core__DOT__Reg_C__DOT__reg_d_out = VL_RAND_RESET_I(16);
    bitty_core__DOT__Reg_0__DOT__reg_d_out = VL_RAND_RESET_I(16);
    bitty_core__DOT__Reg_1__DOT__reg_d_out = VL_RAND_RESET_I(16);
    bitty_core__DOT__Reg_2__DOT__reg_d_out = VL_RAND_RESET_I(16);
    bitty_core__DOT__Reg_3__DOT__reg_d_out = VL_RAND_RESET_I(16);
    bitty_core__DOT__Reg_4__DOT__reg_d_out = VL_RAND_RESET_I(16);
    bitty_core__DOT__Reg_5__DOT__reg_d_out = VL_RAND_RESET_I(16);
    bitty_core__DOT__Reg_6__DOT__reg_d_out = VL_RAND_RESET_I(16);
    bitty_core__DOT__Reg_7__DOT__reg_d_out = VL_RAND_RESET_I(16);
    bitty_core__DOT__myMux__DOT__reg_mux_out = VL_RAND_RESET_I(16);
    __Vtableidx1 = 0;
    __Vtable1_bitty_core__DOT__myControlUnit__DOT__reg_next_state[0] = 1U;
    __Vtable1_bitty_core__DOT__myControlUnit__DOT__reg_next_state[1] = 2U;
    __Vtable1_bitty_core__DOT__myControlUnit__DOT__reg_next_state[2] = 3U;
    __Vtable1_bitty_core__DOT__myControlUnit__DOT__reg_next_state[3] = 0U;
    __Vtable1_bitty_core__DOT__myControlUnit__DOT__reg_next_state[4] = 0U;
    __Vtable1_bitty_core__DOT__myControlUnit__DOT__reg_next_state[5] = 2U;
    __Vtable1_bitty_core__DOT__myControlUnit__DOT__reg_next_state[6] = 3U;
    __Vtable1_bitty_core__DOT__myControlUnit__DOT__reg_next_state[7] = 0U;
    __Vtable1_bitty_core__DOT__myControlUnit__DOT__reg_next_state[8] = 1U;
    __Vtable1_bitty_core__DOT__myControlUnit__DOT__reg_next_state[9] = 2U;
    __Vtable1_bitty_core__DOT__myControlUnit__DOT__reg_next_state[10] = 3U;
    __Vtable1_bitty_core__DOT__myControlUnit__DOT__reg_next_state[11] = 0U;
    __Vtable1_bitty_core__DOT__myControlUnit__DOT__reg_next_state[12] = 1U;
    __Vtable1_bitty_core__DOT__myControlUnit__DOT__reg_next_state[13] = 2U;
    __Vtable1_bitty_core__DOT__myControlUnit__DOT__reg_next_state[14] = 3U;
    __Vtable1_bitty_core__DOT__myControlUnit__DOT__reg_next_state[15] = 0U;
}
