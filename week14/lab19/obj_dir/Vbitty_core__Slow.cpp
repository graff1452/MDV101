// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbitty_core.h for the primary calling header

#include "Vbitty_core.h"
#include "Vbitty_core__Syms.h"

//==========
CData/*2:0*/ Vbitty_core::__Vtable1_bitty_core__DOT__myControlUnit__DOT__reg_next_state[8];

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

void Vbitty_core::_settle__TOP__3(Vbitty_core__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core::_settle__TOP__3\n"); );
    Vbitty_core* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->last_alu_result = vlTOPp->bitty_core__DOT__Reg_C__DOT__reg_d_out;
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
    vlTOPp->__Vtableidx1 = vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_state;
    vlTOPp->bitty_core__DOT__myControlUnit__DOT__reg_next_state 
        = vlTOPp->__Vtable1_bitty_core__DOT__myControlUnit__DOT__reg_next_state
        [vlTOPp->__Vtableidx1];
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
    vlTOPp->Reg_0_Out = vlTOPp->bitty_core__DOT__Reg_0__DOT__reg_d_out;
    vlTOPp->Reg_1_Out = vlTOPp->bitty_core__DOT__Reg_1__DOT__reg_d_out;
    vlTOPp->Reg_2_Out = vlTOPp->bitty_core__DOT__Reg_2__DOT__reg_d_out;
    vlTOPp->Reg_3_Out = vlTOPp->bitty_core__DOT__Reg_3__DOT__reg_d_out;
    vlTOPp->Reg_4_Out = vlTOPp->bitty_core__DOT__Reg_4__DOT__reg_d_out;
    vlTOPp->Reg_5_Out = vlTOPp->bitty_core__DOT__Reg_5__DOT__reg_d_out;
    vlTOPp->Reg_6_Out = vlTOPp->bitty_core__DOT__Reg_6__DOT__reg_d_out;
    vlTOPp->Reg_7_Out = vlTOPp->bitty_core__DOT__Reg_7__DOT__reg_d_out;
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

void Vbitty_core::_eval_initial(Vbitty_core__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core::_eval_initial\n"); );
    Vbitty_core* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__reset = vlTOPp->reset;
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
    vlTOPp->_settle__TOP__3(vlSymsp);
}

void Vbitty_core::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    run = VL_RAND_RESET_I(1);
    instruction = VL_RAND_RESET_I(16);
    done1 = VL_RAND_RESET_I(1);
    done2 = VL_RAND_RESET_I(1);
    Reg_0_Out = VL_RAND_RESET_I(16);
    Reg_1_Out = VL_RAND_RESET_I(16);
    Reg_2_Out = VL_RAND_RESET_I(16);
    Reg_3_Out = VL_RAND_RESET_I(16);
    Reg_4_Out = VL_RAND_RESET_I(16);
    Reg_5_Out = VL_RAND_RESET_I(16);
    Reg_6_Out = VL_RAND_RESET_I(16);
    Reg_7_Out = VL_RAND_RESET_I(16);
    last_alu_result = VL_RAND_RESET_I(16);
    bitty_core__DOT__myControlUnit__DOT__reg_state = VL_RAND_RESET_I(3);
    bitty_core__DOT__myControlUnit__DOT__reg_next_state = VL_RAND_RESET_I(3);
    bitty_core__DOT__myControlUnit__DOT__reg_en_s = VL_RAND_RESET_I(1);
    bitty_core__DOT__myControlUnit__DOT__reg_en_c = VL_RAND_RESET_I(1);
    bitty_core__DOT__myControlUnit__DOT__reg_en_0 = VL_RAND_RESET_I(1);
    bitty_core__DOT__myControlUnit__DOT__reg_en_1 = VL_RAND_RESET_I(1);
    bitty_core__DOT__myControlUnit__DOT__reg_en_2 = VL_RAND_RESET_I(1);
    bitty_core__DOT__myControlUnit__DOT__reg_en_3 = VL_RAND_RESET_I(1);
    bitty_core__DOT__myControlUnit__DOT__reg_en_4 = VL_RAND_RESET_I(1);
    bitty_core__DOT__myControlUnit__DOT__reg_en_5 = VL_RAND_RESET_I(1);
    bitty_core__DOT__myControlUnit__DOT__reg_en_6 = VL_RAND_RESET_I(1);
    bitty_core__DOT__myControlUnit__DOT__reg_en_7 = VL_RAND_RESET_I(1);
    bitty_core__DOT__myControlUnit__DOT__reg_done1 = VL_RAND_RESET_I(1);
    bitty_core__DOT__myControlUnit__DOT__reg_done2 = VL_RAND_RESET_I(1);
    bitty_core__DOT__myControlUnit__DOT__reg_sel = VL_RAND_RESET_I(3);
    bitty_core__DOT__myControlUnit__DOT__reg_mux_sel = VL_RAND_RESET_I(4);
    bitty_core__DOT__myControlUnit__DOT__reg_imm_val = VL_RAND_RESET_I(16);
    bitty_core__DOT__myControlUnit__DOT__reg_en_register_memory = VL_RAND_RESET_I(1);
    bitty_core__DOT__myControlUnit__DOT__reg_mux2_sel = VL_RAND_RESET_I(1);
    bitty_core__DOT__myControlUnit__DOT__reg_en_m = VL_RAND_RESET_I(1);
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
    bitty_core__DOT__Reg_M__DOT__reg_d_out = VL_RAND_RESET_I(16);
    bitty_core__DOT__myMux__DOT__reg_mux_out = VL_RAND_RESET_I(16);
    bitty_core__DOT__myMux2__DOT__reg_mux2_out = VL_RAND_RESET_I(16);
    bitty_core__DOT__myRegisterMemory__DOT__reg_out = VL_RAND_RESET_I(16);
    { int __Vi0=0; for (; __Vi0<8; ++__Vi0) {
            bitty_core__DOT__myRegisterMemory__DOT__memory_cell[__Vi0] = VL_RAND_RESET_I(16);
    }}
    __Vtableidx1 = 0;
    __Vtable1_bitty_core__DOT__myControlUnit__DOT__reg_next_state[0] = 1U;
    __Vtable1_bitty_core__DOT__myControlUnit__DOT__reg_next_state[1] = 2U;
    __Vtable1_bitty_core__DOT__myControlUnit__DOT__reg_next_state[2] = 3U;
    __Vtable1_bitty_core__DOT__myControlUnit__DOT__reg_next_state[3] = 4U;
    __Vtable1_bitty_core__DOT__myControlUnit__DOT__reg_next_state[4] = 5U;
    __Vtable1_bitty_core__DOT__myControlUnit__DOT__reg_next_state[5] = 6U;
    __Vtable1_bitty_core__DOT__myControlUnit__DOT__reg_next_state[6] = 1U;
    __Vtable1_bitty_core__DOT__myControlUnit__DOT__reg_next_state[7] = 0U;
    __Vdlyvdim0__bitty_core__DOT__myRegisterMemory__DOT__memory_cell__v0 = 0;
    __Vdlyvval__bitty_core__DOT__myRegisterMemory__DOT__memory_cell__v0 = VL_RAND_RESET_I(16);
    __Vdlyvset__bitty_core__DOT__myRegisterMemory__DOT__memory_cell__v0 = 0;
}
