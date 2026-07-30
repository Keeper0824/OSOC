// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

bool Vtop___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

extern const VlWide<16>/*511:0*/ Vtop__ConstPool__CONST_hce3fdb3f_0;
extern const VlWide<256>/*8191:0*/ Vtop__ConstPool__CONST_h748d1cc0_0;

void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*3:0*/ __Vdly__top__DOT__pc;
    __Vdly__top__DOT__pc = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__R__v0;
    __VdlyVal__top__DOT__R__v0 = 0;
    CData/*1:0*/ __VdlyDim0__top__DOT__R__v0;
    __VdlyDim0__top__DOT__R__v0 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__R__v0;
    __VdlySet__top__DOT__R__v0 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__R__v1;
    __VdlyVal__top__DOT__R__v1 = 0;
    CData/*1:0*/ __VdlyDim0__top__DOT__R__v1;
    __VdlyDim0__top__DOT__R__v1 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__R__v1;
    __VdlySet__top__DOT__R__v1 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__R__v2;
    __VdlySet__top__DOT__R__v2 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__R__v3;
    __VdlySet__top__DOT__R__v3 = 0;
    // Body
    __Vdly__top__DOT__pc = vlSelfRef.top__DOT__pc;
    __VdlySet__top__DOT__R__v0 = 0U;
    __VdlySet__top__DOT__R__v1 = 0U;
    __VdlySet__top__DOT__R__v2 = 0U;
    __VdlySet__top__DOT__R__v3 = 0U;
    if (vlSelfRef.resetn) {
        if ((0x00000080U & (IData)(vlSelfRef.top__DOT__inst))) {
            if ((0x00000040U & (IData)(vlSelfRef.top__DOT__inst))) {
                __Vdly__top__DOT__pc = (0x0000000fU 
                                        & ((vlSelfRef.top__DOT__R[0U] 
                                            != vlSelfRef.top__DOT__R
                                            [(3U & (IData)(vlSelfRef.top__DOT__inst))])
                                            ? ((IData)(vlSelfRef.top__DOT__inst) 
                                               >> 2U)
                                            : ((IData)(1U) 
                                               + (IData)(vlSelfRef.top__DOT__pc))));
            } else {
                __Vdly__top__DOT__pc = (0x0000000fU 
                                        & ((IData)(1U) 
                                           + (IData)(vlSelfRef.top__DOT__pc)));
                __VdlyVal__top__DOT__R__v0 = (0x0000000fU 
                                              & (IData)(vlSelfRef.top__DOT__inst));
                __VdlyDim0__top__DOT__R__v0 = (3U & 
                                               ((IData)(vlSelfRef.top__DOT__inst) 
                                                >> 4U));
                __VdlySet__top__DOT__R__v0 = 1U;
            }
        } else {
            __Vdly__top__DOT__pc = (0x0000000fU & ((IData)(1U) 
                                                   + (IData)(vlSelfRef.top__DOT__pc)));
            if ((0x00000040U & (IData)(vlSelfRef.top__DOT__inst))) {
                vlSelfRef.top__DOT__out = vlSelfRef.top__DOT__R
                    [(3U & (IData)(vlSelfRef.top__DOT__inst))];
            } else {
                __VdlyVal__top__DOT__R__v1 = (0x000000ffU 
                                              & ((IData)(vlSelfRef.top__DOT__R
                                                         [
                                                         (3U 
                                                          & ((IData)(vlSelfRef.top__DOT__inst) 
                                                             >> 2U))]) 
                                                 + (IData)(vlSelfRef.top__DOT__R
                                                           [
                                                           (3U 
                                                            & (IData)(vlSelfRef.top__DOT__inst))])));
                __VdlyDim0__top__DOT__R__v1 = (3U & 
                                               ((IData)(vlSelfRef.top__DOT__inst) 
                                                >> 4U));
                __VdlySet__top__DOT__R__v1 = 1U;
            }
        }
    } else {
        __Vdly__top__DOT__pc = 0U;
        __VdlySet__top__DOT__R__v2 = 1U;
        vlSelfRef.top__DOT__out = 0U;
        __VdlySet__top__DOT__R__v3 = 1U;
    }
    vlSelfRef.top__DOT__pc = __Vdly__top__DOT__pc;
    if (__VdlySet__top__DOT__R__v0) {
        vlSelfRef.top__DOT__R[__VdlyDim0__top__DOT__R__v0] 
            = __VdlyVal__top__DOT__R__v0;
    }
    if (__VdlySet__top__DOT__R__v1) {
        vlSelfRef.top__DOT__R[__VdlyDim0__top__DOT__R__v1] 
            = __VdlyVal__top__DOT__R__v1;
    }
    if (__VdlySet__top__DOT__R__v2) {
        vlSelfRef.top__DOT__R[0U] = 0x0aU;
    }
    if (__VdlySet__top__DOT__R__v3) {
        vlSelfRef.top__DOT__R[1U] = 0U;
        vlSelfRef.top__DOT__R[2U] = 0U;
        vlSelfRef.top__DOT__R[3U] = 0U;
    }
    vlSelfRef.top__DOT__inst = (0x000000ffU & Vtop__ConstPool__CONST_hce3fdb3f_0
                                [(0x07ffffffU & (IData)(vlSelfRef.top__DOT__pc))]);
    vlSelfRef.seg0 = (0x000000ffU & Vtop__ConstPool__CONST_h748d1cc0_0
                      [(0x000000ffU & VL_MODDIV_III(8, (IData)(vlSelfRef.top__DOT__out), (IData)(0x0aU)))]);
    vlSelfRef.seg1 = (0x000000ffU & Vtop__ConstPool__CONST_h748d1cc0_0
                      [(0x000000ffU & VL_DIV_III(8, (IData)(vlSelfRef.top__DOT__out), (IData)(0x0aU)))]);
}

void Vtop___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vtop___024root___eval_phase__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__act
        vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                        ((IData)(vlSelfRef.clk) 
                                                         & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0)))));
        vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vtop___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

void Vtop___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vtop___024root___eval_phase__nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtop___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        {
            // Inlined CFunc: _eval_nba
            if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
                Vtop___024root___nba_sequent__TOP__0(vlSelf);
                vlSelfRef.__Vm_traceActivity[1U] = 1U;
            }
        }
        Vtop___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("/home/sun/Desktop/OSOC/E\351\230\266\346\256\265/E5/sCPU/vsrc/top.v", 1, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 10000 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("/home/sun/Desktop/OSOC/E\351\230\266\346\256\265/E5/sCPU/vsrc/top.v", 1, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 10000 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactPhaseResult = Vtop___024root___eval_phase__act(vlSelf);
        } while (vlSelfRef.__VactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = Vtop___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");
    }
    if (VL_UNLIKELY(((vlSelfRef.resetn & 0xfeU)))) {
        Verilated::overWidthError("resetn");
    }
}
#endif  // VL_DEBUG
