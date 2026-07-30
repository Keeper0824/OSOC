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

extern const VlWide<16>/*511:0*/ Vtop__ConstPool__CONST_he06e20c7_0;
extern const VlWide<256>/*8191:0*/ Vtop__ConstPool__CONST_h73018547_0;

void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*2:0*/ __Vdly__top__DOT__ps2_clk_sync;
    __Vdly__top__DOT__ps2_clk_sync = 0;
    CData/*0:0*/ __Vdly__top__DOT__break_pending;
    __Vdly__top__DOT__break_pending = 0;
    CData/*0:0*/ __Vdly__top__DOT__key_down;
    __Vdly__top__DOT__key_down = 0;
    CData/*3:0*/ __Vdly__top__DOT__count;
    __Vdly__top__DOT__count = 0;
    // Body
    __Vdly__top__DOT__ps2_clk_sync = vlSelfRef.top__DOT__ps2_clk_sync;
    __Vdly__top__DOT__break_pending = vlSelfRef.top__DOT__break_pending;
    __Vdly__top__DOT__count = vlSelfRef.top__DOT__count;
    __Vdly__top__DOT__key_down = vlSelfRef.top__DOT__key_down;
    __Vdly__top__DOT__ps2_clk_sync = ((6U & ((IData)(vlSelfRef.top__DOT__ps2_clk_sync) 
                                             << 1U)) 
                                      | (IData)(vlSelfRef.ps2_clk));
    if (vlSelfRef.resetn) {
        if ((IData)((4U == (6U & (IData)(vlSelfRef.top__DOT__ps2_clk_sync))))) {
            if ((0x0aU == (IData)(vlSelfRef.top__DOT__count))) {
                if ((((~ (IData)(vlSelfRef.top__DOT__buffer)) 
                      & (IData)(vlSelfRef.ps2_data)) 
                     & VL_REDXOR_32((0x000001ffU & 
                                     ((IData)(vlSelfRef.top__DOT__buffer) 
                                      >> 1U))))) {
                    if ((0xf0U == (0x000000ffU & ((IData)(vlSelfRef.top__DOT__buffer) 
                                                  >> 1U)))) {
                        __Vdly__top__DOT__break_pending = 1U;
                        __Vdly__top__DOT__key_down = 0U;
                    } else if (vlSelfRef.top__DOT__break_pending) {
                        __Vdly__top__DOT__break_pending = 0U;
                    } else if ((1U & (~ (IData)(vlSelfRef.top__DOT__key_down)))) {
                        vlSelfRef.top__DOT__recv_count 
                            = (0x000000ffU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.top__DOT__recv_count)));
                        vlSelfRef.top__DOT__out = (0x000000ffU 
                                                   & ((IData)(vlSelfRef.top__DOT__buffer) 
                                                      >> 1U));
                        __Vdly__top__DOT__key_down = 1U;
                    }
                }
                __Vdly__top__DOT__count = 0U;
            } else {
                if ((9U >= (IData)(vlSelfRef.top__DOT__count))) {
                    vlSelfRef.top__DOT__buffer = ((
                                                   (~ 
                                                    ((IData)(1U) 
                                                     << (IData)(vlSelfRef.top__DOT__count))) 
                                                   & (IData)(vlSelfRef.top__DOT__buffer)) 
                                                  | (0x03ffU 
                                                     & ((IData)(vlSelfRef.ps2_data) 
                                                        << (IData)(vlSelfRef.top__DOT__count))));
                }
                __Vdly__top__DOT__count = (0x0000000fU 
                                           & ((IData)(1U) 
                                              + (IData)(vlSelfRef.top__DOT__count)));
            }
        }
    } else {
        vlSelfRef.top__DOT__recv_count = 0U;
        __Vdly__top__DOT__count = 0U;
        vlSelfRef.top__DOT__buffer = 0U;
        vlSelfRef.top__DOT__out = 0U;
    }
    vlSelfRef.top__DOT__ps2_clk_sync = __Vdly__top__DOT__ps2_clk_sync;
    vlSelfRef.top__DOT__break_pending = __Vdly__top__DOT__break_pending;
    vlSelfRef.top__DOT__count = __Vdly__top__DOT__count;
    vlSelfRef.top__DOT__key_down = __Vdly__top__DOT__key_down;
    vlSelfRef.seg4 = (0x000000ffU & Vtop__ConstPool__CONST_he06e20c7_0
                      [(0x0000000fU & (IData)(vlSelfRef.top__DOT__recv_count))]);
    vlSelfRef.seg5 = (0x000000ffU & Vtop__ConstPool__CONST_he06e20c7_0
                      [(0x0000000fU & ((IData)(vlSelfRef.top__DOT__recv_count) 
                                       >> 4U))]);
    vlSelfRef.top__DOT__scan_to_ascii = (0x000000ffU 
                                         & Vtop__ConstPool__CONST_h73018547_0
                                         [(0x07ffffffU 
                                           & (IData)(vlSelfRef.top__DOT__out))]);
    if (vlSelfRef.top__DOT__key_down) {
        vlSelfRef.seg0 = (0x000000ffU & Vtop__ConstPool__CONST_he06e20c7_0
                          [(0x0000000fU & (IData)(vlSelfRef.top__DOT__out))]);
        vlSelfRef.seg1 = (0x000000ffU & Vtop__ConstPool__CONST_he06e20c7_0
                          [(0x0000000fU & ((IData)(vlSelfRef.top__DOT__out) 
                                           >> 4U))]);
        vlSelfRef.seg2 = (0x000000ffU & Vtop__ConstPool__CONST_he06e20c7_0
                          [(0x0000000fU & (IData)(vlSelfRef.top__DOT__scan_to_ascii))]);
        vlSelfRef.seg3 = (0x000000ffU & Vtop__ConstPool__CONST_he06e20c7_0
                          [(0x0000000fU & ((IData)(vlSelfRef.top__DOT__scan_to_ascii) 
                                           >> 4U))]);
    } else {
        vlSelfRef.seg0 = 0x000000ffU;
        vlSelfRef.seg1 = 0x000000ffU;
        vlSelfRef.seg2 = 0xffU;
        vlSelfRef.seg3 = 0xffU;
    }
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
            VL_FATAL_MT("/home/sun/Desktop/OSOC/E\351\230\266\346\256\265/E5/Ex7/vsrc/top.v", 1, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 10000 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("/home/sun/Desktop/OSOC/E\351\230\266\346\256\265/E5/Ex7/vsrc/top.v", 1, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 10000 tries");
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
    if (VL_UNLIKELY(((vlSelfRef.ps2_clk & 0xfeU)))) {
        Verilated::overWidthError("ps2_clk");
    }
    if (VL_UNLIKELY(((vlSelfRef.ps2_data & 0xfeU)))) {
        Verilated::overWidthError("ps2_data");
    }
    if (VL_UNLIKELY(((vlSelfRef.resetn & 0xfeU)))) {
        Verilated::overWidthError("resetn");
    }
}
#endif  // VL_DEBUG
