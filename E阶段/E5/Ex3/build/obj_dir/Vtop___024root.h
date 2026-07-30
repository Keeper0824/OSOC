// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(A,3,0);
    VL_IN8(B,3,0);
    VL_IN8(func,2,0);
    VL_OUT8(out,3,0);
    VL_OUT8(zero,0,0);
    VL_OUT8(overflow,0,0);
    VL_OUT8(carry,0,0);
    CData/*0:0*/ top__DOT__s0;
    CData/*0:0*/ top__DOT__s1;
    CData/*3:0*/ top__DOT__add_result;
    CData/*3:0*/ top__DOT__sub_result;
    CData/*3:0*/ top__DOT__and_result;
    CData/*3:0*/ top__DOT__xor_result;
    CData/*0:0*/ top__DOT__sub_unit__DOT__c1;
    CData/*0:0*/ top__DOT__sub_unit__DOT__c2;
    CData/*0:0*/ top__DOT__sub_unit__DOT__c3;
    CData/*0:0*/ top__DOT__add_unit__DOT__c2;
    CData/*0:0*/ top__DOT__add_unit__DOT__c3;
    CData/*3:0*/ __VdfgRegularize_h6e95ff9d_0_0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_5;
    CData/*3:0*/ __VdfgRegularize_h6e95ff9d_0_6;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_7;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VstlPhaseResult;
    CData/*3:0*/ __Vtrigprevexpr___TOP__A__0;
    CData/*3:0*/ __Vtrigprevexpr___TOP__B__0;
    CData/*2:0*/ __Vtrigprevexpr___TOP__func__0;
    CData/*0:0*/ __VicoDidInit;
    CData/*0:0*/ __VicoPhaseResult;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 2> __VicoTriggered;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;

    // INTERNAL VARIABLES
    Vtop__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* namep);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
