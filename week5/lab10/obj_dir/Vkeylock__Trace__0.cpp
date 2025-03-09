// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vkeylock__Syms.h"


void Vkeylock___024root__trace_chg_0_sub_0(Vkeylock___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vkeylock___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkeylock___024root__trace_chg_0\n"); );
    // Init
    Vkeylock___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vkeylock___024root*>(voidSelf);
    Vkeylock__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vkeylock___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vkeylock___024root__trace_chg_0_sub_0(Vkeylock___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vkeylock__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkeylock___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgBit(oldp+0,(vlSelf->clk));
    bufp->chgBit(oldp+1,(vlSelf->reset));
    bufp->chgCData(oldp+2,(vlSelf->digit),4);
    bufp->chgBit(oldp+3,(vlSelf->locked));
    bufp->chgCData(oldp+4,(vlSelf->keylock__DOT__current_state),3);
    bufp->chgCData(oldp+5,(vlSelf->keylock__DOT__next_state),3);
}

void Vkeylock___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkeylock___024root__trace_cleanup\n"); );
    // Init
    Vkeylock___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vkeylock___024root*>(voidSelf);
    Vkeylock__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
