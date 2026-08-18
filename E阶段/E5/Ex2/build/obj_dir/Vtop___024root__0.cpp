// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

bool Vtop___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 2> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__ico\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((2U > n));
    return (0U);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 2> &triggers, const std::string &tag);
#endif  // VL_DEBUG
extern const VlUnpacked<CData/*2:0*/, 512> Vtop__ConstPool__TABLE_h4d437d01_0;
extern const VlUnpacked<CData/*1:0*/, 512> Vtop__ConstPool__TABLE_hd5d8a076_0;
extern const VlUnpacked<IData/*31:0*/, 512> Vtop__ConstPool__TABLE_h79bd449d_0;
extern const VlWide<8>/*255:0*/ Vtop__ConstPool__CONST_h557f92b2_0;

bool Vtop___024root___eval_phase__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VicoExecute;
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__ico
        vlSelfRef.__VicoTriggered[0U] = (QData)((IData)(
                                                        ((((IData)(vlSelfRef.en) 
                                                           != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__en__0)) 
                                                          << 1U) 
                                                         | ((IData)(vlSelfRef.x) 
                                                            != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__x__0)))));
        vlSelfRef.__Vtrigprevexpr___TOP__x__0 = vlSelfRef.x;
        vlSelfRef.__Vtrigprevexpr___TOP__en__0 = vlSelfRef.en;
        if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__VicoDidInit)))))) {
            vlSelfRef.__VicoDidInit = 1U;
            vlSelfRef.__VicoTriggered[0U] = (1ULL | vlSelfRef.__VicoTriggered[0U]);
            vlSelfRef.__VicoTriggered[0U] = (2ULL | vlSelfRef.__VicoTriggered[0U]);
        }
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
    __VicoExecute = Vtop___024root___trigger_anySet__ico(vlSelfRef.__VicoTriggered);
    if (__VicoExecute) {
        {
            // Inlined CFunc: _eval_ico
            if ((3ULL & vlSelfRef.__VicoTriggered[0U])) {
                {
                    // Inlined CFunc: _ico_comb__TOP__0
                    SData/*8:0*/ __Vinline_0__eval_ico___Vinline_1__ico_comb__TOP__0___Vtableidx1;
                    __Vinline_0__eval_ico___Vinline_1__ico_comb__TOP__0___Vtableidx1 = 0;
                    vlSelfRef.led4 = ((IData)(vlSelfRef.en) 
                                      & (0U != (IData)(vlSelfRef.x)));
                    __Vinline_0__eval_ico___Vinline_1__ico_comb__TOP__0___Vtableidx1 
                        = (((IData)(vlSelfRef.x) << 1U) 
                           | (IData)(vlSelfRef.en));
                    vlSelfRef.y = Vtop__ConstPool__TABLE_h4d437d01_0
                        [__Vinline_0__eval_ico___Vinline_1__ico_comb__TOP__0___Vtableidx1];
                    if ((2U & Vtop__ConstPool__TABLE_hd5d8a076_0
                         [__Vinline_0__eval_ico___Vinline_1__ico_comb__TOP__0___Vtableidx1])) {
                        vlSelfRef.top__DOT__i = Vtop__ConstPool__TABLE_h79bd449d_0
                            [__Vinline_0__eval_ico___Vinline_1__ico_comb__TOP__0___Vtableidx1];
                    }
                    vlSelfRef.seg0 = ((IData)(vlSelfRef.led4)
                                       ? (0x000000ffU 
                                          & Vtop__ConstPool__CONST_h557f92b2_0
                                          [(0x07ffffffU 
                                            & (IData)(vlSelfRef.y))])
                                       : 0x000000ffU);
                }
            }
        }
    }
    return (__VicoExecute);
}

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VicoIterCount;
    // Body
    __VicoIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
            VL_FATAL_MT("/home/sun/Desktop/OSOC/E\351\230\266\346\256\265/E5/Ex2/vsrc/top.v", 1, "", "DIDNOTCONVERGE: Input combinational region did not converge after '--converge-limit' of 10000 tries");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        vlSelfRef.__VicoPhaseResult = Vtop___024root___eval_phase__ico(vlSelf);
    } while (vlSelfRef.__VicoPhaseResult);
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.en & 0xfeU)))) {
        Verilated::overWidthError("en");
    }
}
#endif  // VL_DEBUG
