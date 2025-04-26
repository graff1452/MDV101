// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vcounter.h for the primary calling header

#ifndef _VCOUNTER___024UNIT_H_
#define _VCOUNTER___024UNIT_H_  // guard

#include "verilated.h"
#include "Vcounter__Dpi.h"

//==========

class Vcounter__Syms;

//----------

VL_MODULE(Vcounter___024unit) {
  public:
    
    // INTERNAL VARIABLES
  private:
    Vcounter__Syms* __VlSymsp;  // Symbol table
  public:
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vcounter___024unit);  ///< Copying not allowed
  public:
    Vcounter___024unit(const char* name = "TOP");
    ~Vcounter___024unit();
    
    // INTERNAL METHODS
    void __Vconfigure(Vcounter__Syms* symsp, bool first);
    void __Vdpiimwrap_notify_counter_reached_nine_TOP____024unit();
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
