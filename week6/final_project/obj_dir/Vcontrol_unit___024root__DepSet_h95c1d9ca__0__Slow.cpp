// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcontrol_unit.h for the primary calling header

#include "Vcontrol_unit__pch.h"
#include "Vcontrol_unit__Syms.h"
#include "Vcontrol_unit___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vcontrol_unit___024root___dump_triggers__stl(Vcontrol_unit___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vcontrol_unit___024root___eval_triggers__stl(Vcontrol_unit___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcontrol_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_unit___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.set(0U, (IData)(vlSelf->__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vcontrol_unit___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
