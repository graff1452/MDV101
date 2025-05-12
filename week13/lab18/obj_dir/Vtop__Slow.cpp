// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"
#include "Vtop__Syms.h"

//==========
CData/*2:0*/ Vtop::__Vtable1_top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_next_state[8];

VL_CTOR_IMP(Vtop) {
    Vtop__Syms* __restrict vlSymsp = __VlSymsp = new Vtop__Syms(this, name());
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vtop::__Vconfigure(Vtop__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vtop::~Vtop() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vtop::_settle__TOP__3(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_settle__TOP__3\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top_out = vlTOPp->top__DOT__reg_top_out;
    vlTOPp->__Vtableidx1 = vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state;
    vlTOPp->top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_next_state 
        = vlTOPp->__Vtable1_top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_next_state
        [vlTOPp->__Vtableidx1];
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

void Vtop::_initial__TOP__4(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_initial__TOP__4\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    WData/*543:0*/ __Vtemp1[17];
    // Body
    __Vtemp1[0U] = 0x2e747874U;
    __Vtemp1[1U] = 0x696f6e73U;
    __Vtemp1[2U] = 0x72756374U;
    __Vtemp1[3U] = 0x696e7374U;
    __Vtemp1[4U] = 0x746f722fU;
    __Vtemp1[5U] = 0x6e657261U;
    __Vtemp1[6U] = 0x382f6765U;
    __Vtemp1[7U] = 0x6c616231U;
    __Vtemp1[8U] = 0x6b31332fU;
    __Vtemp1[9U] = 0x2f776565U;
    __Vtemp1[0xaU] = 0x56313031U;
    __Vtemp1[0xbU] = 0x702f4d44U;
    __Vtemp1[0xcU] = 0x736b746fU;
    __Vtemp1[0xdU] = 0x6e2f4465U;
    __Vtemp1[0xeU] = 0x2f7a6861U;
    __Vtemp1[0xfU] = 0x686f6d65U;
    __Vtemp1[0x10U] = 0x2fU;
    VL_READMEM_N(true, 16, 256, 0, VL_CVT_PACK_STR_NW(17, __Vtemp1)
                 , vlTOPp->top__DOT__my_instuction_fetch_unit__DOT__my_memory__DOT__memory_cell
                 , 0, ~0ULL);
}

void Vtop::_eval_initial(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_initial\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__reset = vlTOPp->reset;
    vlTOPp->_initial__TOP__4(vlSymsp);
}

void Vtop::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::final\n"); );
    // Variables
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vtop::_eval_settle(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_settle\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
}

void Vtop::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    run = VL_RAND_RESET_I(1);
    top_out = VL_RAND_RESET_I(16);
    top__DOT__reg_top_out = VL_RAND_RESET_I(16);
    top__DOT__my_instuction_fetch_unit__DOT__reg_instruction_out = VL_RAND_RESET_I(16);
    top__DOT__my_instuction_fetch_unit__DOT__my_pc__DOT__reg_d_out = VL_RAND_RESET_I(8);
    top__DOT__my_instuction_fetch_unit__DOT__my_memory__DOT__out_reg = VL_RAND_RESET_I(16);
    { int __Vi0=0; for (; __Vi0<256; ++__Vi0) {
            top__DOT__my_instuction_fetch_unit__DOT__my_memory__DOT__memory_cell[__Vi0] = VL_RAND_RESET_I(16);
    }}
    top__DOT__my_instuction_fetch_unit__DOT__my_branch_logic__DOT__reg_new_pc = VL_RAND_RESET_I(16);
    top__DOT__my_instuction_fetch_unit__DOT__my_branch_logic__DOT__Reg_branch_logic_Out__DOT__reg_d_out = VL_RAND_RESET_I(8);
    top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_state = VL_RAND_RESET_I(3);
    top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_next_state = VL_RAND_RESET_I(3);
    top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_en_s = VL_RAND_RESET_I(1);
    top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_en_c = VL_RAND_RESET_I(1);
    top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_en_0 = VL_RAND_RESET_I(1);
    top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_en_1 = VL_RAND_RESET_I(1);
    top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_en_2 = VL_RAND_RESET_I(1);
    top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_en_3 = VL_RAND_RESET_I(1);
    top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_en_4 = VL_RAND_RESET_I(1);
    top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_en_5 = VL_RAND_RESET_I(1);
    top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_en_6 = VL_RAND_RESET_I(1);
    top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_en_7 = VL_RAND_RESET_I(1);
    top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_done1 = VL_RAND_RESET_I(1);
    top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_done2 = VL_RAND_RESET_I(1);
    top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_sel = VL_RAND_RESET_I(3);
    top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_mux_sel = VL_RAND_RESET_I(4);
    top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_imm_val = VL_RAND_RESET_I(16);
    top__DOT__my_bitty_core__DOT__Reg_S__DOT__reg_d_out = VL_RAND_RESET_I(16);
    top__DOT__my_bitty_core__DOT__Reg_C__DOT__reg_d_out = VL_RAND_RESET_I(16);
    top__DOT__my_bitty_core__DOT__Reg_0__DOT__reg_d_out = VL_RAND_RESET_I(16);
    top__DOT__my_bitty_core__DOT__Reg_1__DOT__reg_d_out = VL_RAND_RESET_I(16);
    top__DOT__my_bitty_core__DOT__Reg_2__DOT__reg_d_out = VL_RAND_RESET_I(16);
    top__DOT__my_bitty_core__DOT__Reg_3__DOT__reg_d_out = VL_RAND_RESET_I(16);
    top__DOT__my_bitty_core__DOT__Reg_4__DOT__reg_d_out = VL_RAND_RESET_I(16);
    top__DOT__my_bitty_core__DOT__Reg_5__DOT__reg_d_out = VL_RAND_RESET_I(16);
    top__DOT__my_bitty_core__DOT__Reg_6__DOT__reg_d_out = VL_RAND_RESET_I(16);
    top__DOT__my_bitty_core__DOT__Reg_7__DOT__reg_d_out = VL_RAND_RESET_I(16);
    top__DOT__my_bitty_core__DOT__myMux__DOT__reg_mux_out = VL_RAND_RESET_I(16);
    __Vtableidx1 = 0;
    __Vtable1_top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_next_state[0] = 1U;
    __Vtable1_top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_next_state[1] = 2U;
    __Vtable1_top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_next_state[2] = 3U;
    __Vtable1_top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_next_state[3] = 4U;
    __Vtable1_top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_next_state[4] = 5U;
    __Vtable1_top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_next_state[5] = 3U;
    __Vtable1_top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_next_state[6] = 0U;
    __Vtable1_top__DOT__my_bitty_core__DOT__myControlUnit__DOT__reg_next_state[7] = 0U;
}
