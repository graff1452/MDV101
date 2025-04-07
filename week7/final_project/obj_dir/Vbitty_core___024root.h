// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vbitty_core.h for the primary calling header

#ifndef VERILATED_VBITTY_CORE___024ROOT_H_
#define VERILATED_VBITTY_CORE___024ROOT_H_  // guard

#include "verilated.h"


class Vbitty_core__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vbitty_core___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(run,0,0);
    VL_OUT8(done,0,0);
    CData/*0:0*/ bitty_core__DOT__myControlUnit__DOT__reg_run_prev;
    CData/*0:0*/ bitty_core__DOT__myControlUnit__DOT__reg_en_s;
    CData/*0:0*/ bitty_core__DOT__myControlUnit__DOT__reg_en_c;
    CData/*0:0*/ bitty_core__DOT__myControlUnit__DOT__reg_en_i;
    CData/*0:0*/ bitty_core__DOT__myControlUnit__DOT__reg_en_0;
    CData/*0:0*/ bitty_core__DOT__myControlUnit__DOT__reg_en_1;
    CData/*0:0*/ bitty_core__DOT__myControlUnit__DOT__reg_en_2;
    CData/*0:0*/ bitty_core__DOT__myControlUnit__DOT__reg_en_3;
    CData/*0:0*/ bitty_core__DOT__myControlUnit__DOT__reg_en_4;
    CData/*0:0*/ bitty_core__DOT__myControlUnit__DOT__reg_en_5;
    CData/*0:0*/ bitty_core__DOT__myControlUnit__DOT__reg_en_6;
    CData/*0:0*/ bitty_core__DOT__myControlUnit__DOT__reg_en_7;
    CData/*1:0*/ bitty_core__DOT__myControlUnit__DOT__reg_state;
    CData/*1:0*/ bitty_core__DOT__myControlUnit__DOT__reg_next_state;
    CData/*2:0*/ bitty_core__DOT__myControlUnit__DOT__reg_sel;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __VactContinue;
    VL_IN16(instruction,15,0);
    VL_OUT16(Reg_Inst_Out,15,0);
    VL_OUT16(Reg_S_Out,15,0);
    VL_OUT16(Reg_C_Out,15,0);
    VL_OUT16(Reg_0_Out,15,0);
    VL_OUT16(Reg_1_Out,15,0);
    VL_OUT16(Reg_2_Out,15,0);
    VL_OUT16(Reg_3_Out,15,0);
    VL_OUT16(Reg_4_Out,15,0);
    VL_OUT16(Reg_5_Out,15,0);
    VL_OUT16(Reg_6_Out,15,0);
    VL_OUT16(Reg_7_Out,15,0);
    SData/*15:0*/ bitty_core__DOT__Reg_Inst__DOT__reg_d_out;
    SData/*15:0*/ bitty_core__DOT__Reg_S__DOT__reg_d_out;
    SData/*15:0*/ bitty_core__DOT__Reg_C__DOT__reg_d_out;
    SData/*15:0*/ bitty_core__DOT__Reg_0__DOT__reg_d_out;
    SData/*15:0*/ bitty_core__DOT__Reg_1__DOT__reg_d_out;
    SData/*15:0*/ bitty_core__DOT__Reg_2__DOT__reg_d_out;
    SData/*15:0*/ bitty_core__DOT__Reg_3__DOT__reg_d_out;
    SData/*15:0*/ bitty_core__DOT__Reg_4__DOT__reg_d_out;
    SData/*15:0*/ bitty_core__DOT__Reg_5__DOT__reg_d_out;
    SData/*15:0*/ bitty_core__DOT__Reg_6__DOT__reg_d_out;
    SData/*15:0*/ bitty_core__DOT__Reg_7__DOT__reg_d_out;
    SData/*15:0*/ bitty_core__DOT__myMux__DOT__in_8;
    SData/*15:0*/ bitty_core__DOT__myMux__DOT__in_9;
    SData/*15:0*/ bitty_core__DOT__myMux__DOT__reg_mux_out;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vbitty_core__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vbitty_core___024root(Vbitty_core__Syms* symsp, const char* v__name);
    ~Vbitty_core___024root();
    VL_UNCOPYABLE(Vbitty_core___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
