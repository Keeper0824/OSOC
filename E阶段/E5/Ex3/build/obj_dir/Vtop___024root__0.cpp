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

void Vtop___024root___eval_ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((4ULL & vlSelfRef.__VicoTriggered[0U])) {
        {
            // Inlined CFunc: _ico_sequent__TOP__0
            CData/*0:0*/ __Vinline_0__ico_sequent__TOP__0___VdfgRegularize_h6e95ff9d_0_4;
            __Vinline_0__ico_sequent__TOP__0___VdfgRegularize_h6e95ff9d_0_4 = 0;
            vlSelfRef.__VdfgRegularize_h6e95ff9d_0_5 
                = (IData)((2U == (6U & (IData)(vlSelfRef.func))));
            vlSelfRef.__VdfgRegularize_h6e95ff9d_0_7 
                = (IData)((4U == (6U & (IData)(vlSelfRef.func))));
            __Vinline_0__ico_sequent__TOP__0___VdfgRegularize_h6e95ff9d_0_4 
                = (IData)((0U == (6U & (IData)(vlSelfRef.func))));
            vlSelfRef.top__DOT__s0 = ((~ (IData)(vlSelfRef.func)) 
                                      & __Vinline_0__ico_sequent__TOP__0___VdfgRegularize_h6e95ff9d_0_4);
            vlSelfRef.top__DOT__s1 = ((IData)(vlSelfRef.func) 
                                      & __Vinline_0__ico_sequent__TOP__0___VdfgRegularize_h6e95ff9d_0_4);
        }
    }
    if ((3ULL & vlSelfRef.__VicoTriggered[0U])) {
        {
            // Inlined CFunc: _ico_comb__TOP__0
            vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0 
                = (0x0000000fU & ((~ (IData)(vlSelfRef.B)) 
                                  ^ (IData)(vlSelfRef.A)));
            vlSelfRef.top__DOT__xor_result = ((IData)(vlSelfRef.A) 
                                              ^ (IData)(vlSelfRef.B));
            vlSelfRef.top__DOT__and_result = ((IData)(vlSelfRef.A) 
                                              & (IData)(vlSelfRef.B));
            vlSelfRef.top__DOT__sub_unit__DOT__c1 = 
                (1U & ((~ (IData)(vlSelfRef.B)) | (IData)(vlSelfRef.A)));
            vlSelfRef.top__DOT__add_unit__DOT__c2 = 
                (1U & ((((IData)(vlSelfRef.A) >> 1U) 
                        & (((IData)(vlSelfRef.B) >> 1U) 
                           | (IData)(vlSelfRef.top__DOT__and_result))) 
                       | (((IData)(vlSelfRef.B) >> 1U) 
                          & (IData)(vlSelfRef.top__DOT__and_result))));
            vlSelfRef.top__DOT__sub_unit__DOT__c2 = 
                (1U & ((((IData)(vlSelfRef.A) >> 1U) 
                        & ((~ ((IData)(vlSelfRef.B) 
                               >> 1U)) | (IData)(vlSelfRef.top__DOT__sub_unit__DOT__c1))) 
                       | ((~ ((IData)(vlSelfRef.B) 
                              >> 1U)) & (IData)(vlSelfRef.top__DOT__sub_unit__DOT__c1))));
            vlSelfRef.top__DOT__add_unit__DOT__c3 = 
                (1U & ((((IData)(vlSelfRef.A) >> 2U) 
                        & (((IData)(vlSelfRef.B) >> 2U) 
                           | (IData)(vlSelfRef.top__DOT__add_unit__DOT__c2))) 
                       | (((IData)(vlSelfRef.B) >> 2U) 
                          & (IData)(vlSelfRef.top__DOT__add_unit__DOT__c2))));
            vlSelfRef.top__DOT__sub_unit__DOT__c3 = 
                (1U & ((((IData)(vlSelfRef.A) >> 2U) 
                        & ((~ ((IData)(vlSelfRef.B) 
                               >> 2U)) | (IData)(vlSelfRef.top__DOT__sub_unit__DOT__c2))) 
                       | ((~ ((IData)(vlSelfRef.B) 
                              >> 2U)) & (IData)(vlSelfRef.top__DOT__sub_unit__DOT__c2))));
            vlSelfRef.top__DOT__add_result = (((((IData)(vlSelfRef.top__DOT__add_unit__DOT__c3) 
                                                 ^ 
                                                 ((IData)(vlSelfRef.top__DOT__xor_result) 
                                                  >> 3U)) 
                                                << 3U) 
                                               | (4U 
                                                  & (((IData)(vlSelfRef.top__DOT__add_unit__DOT__c2) 
                                                      << 2U) 
                                                     ^ 
                                                     (0xfffffffcU 
                                                      & (IData)(vlSelfRef.top__DOT__xor_result))))) 
                                              | ((2U 
                                                  & (((IData)(vlSelfRef.top__DOT__and_result) 
                                                      << 1U) 
                                                     ^ 
                                                     (0xfffffffeU 
                                                      & (IData)(vlSelfRef.top__DOT__xor_result)))) 
                                                 | (1U 
                                                    & (IData)(vlSelfRef.top__DOT__xor_result))));
            vlSelfRef.top__DOT__sub_result = (((((IData)(vlSelfRef.top__DOT__sub_unit__DOT__c3) 
                                                 ^ 
                                                 ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0) 
                                                  >> 3U)) 
                                                << 3U) 
                                               | (4U 
                                                  & (((IData)(vlSelfRef.top__DOT__sub_unit__DOT__c2) 
                                                      << 2U) 
                                                     ^ 
                                                     (0xfffffffcU 
                                                      & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0))))) 
                                              | ((2U 
                                                  & (((IData)(vlSelfRef.top__DOT__sub_unit__DOT__c1) 
                                                      << 1U) 
                                                     ^ 
                                                     (0xfffffffeU 
                                                      & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0)))) 
                                                 | (1U 
                                                    & (~ (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0)))));
            vlSelfRef.__VdfgRegularize_h6e95ff9d_0_6 
                = ((IData)(vlSelfRef.top__DOT__xor_result) 
                   & ((IData)(vlSelfRef.A) ^ (IData)(vlSelfRef.top__DOT__sub_result)));
        }
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
    if ((7ULL & vlSelfRef.__VicoTriggered[0U])) {
        {
            // Inlined CFunc: _ico_comb__TOP__1
            vlSelfRef.carry = ((((((IData)(vlSelfRef.A) 
                                   >> 3U) & ((~ ((IData)(vlSelfRef.B) 
                                                 >> 3U)) 
                                             | (IData)(vlSelfRef.top__DOT__sub_unit__DOT__c3))) 
                                 | ((~ ((IData)(vlSelfRef.B) 
                                        >> 3U)) & (IData)(vlSelfRef.top__DOT__sub_unit__DOT__c3))) 
                                & (IData)(vlSelfRef.top__DOT__s1)) 
                               | (((((IData)(vlSelfRef.A) 
                                     >> 3U) & (((IData)(vlSelfRef.B) 
                                                >> 3U) 
                                               | (IData)(vlSelfRef.top__DOT__add_unit__DOT__c3))) 
                                   | (((IData)(vlSelfRef.B) 
                                       >> 3U) & (IData)(vlSelfRef.top__DOT__add_unit__DOT__c3))) 
                                  & (IData)(vlSelfRef.top__DOT__s0)));
            vlSelfRef.overflow = (((IData)(vlSelfRef.top__DOT__s0) 
                                   & ((~ ((IData)(vlSelfRef.top__DOT__xor_result) 
                                          >> 3U)) & 
                                      (((IData)(vlSelfRef.A) 
                                        ^ (IData)(vlSelfRef.top__DOT__add_result)) 
                                       >> 3U))) | (
                                                   ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_6) 
                                                    >> 3U) 
                                                   & (IData)(vlSelfRef.top__DOT__s1)));
            vlSelfRef.out = (0x0000000fU & (((- (IData)((IData)(vlSelfRef.top__DOT__s0))) 
                                             & (IData)(vlSelfRef.top__DOT__add_result)) 
                                            | (((- (IData)((IData)(vlSelfRef.top__DOT__s1))) 
                                                & (IData)(vlSelfRef.top__DOT__sub_result)) 
                                               | (((~ (IData)(vlSelfRef.A)) 
                                                   & (- (IData)(
                                                                ((~ (IData)(vlSelfRef.func)) 
                                                                 & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_5))))) 
                                                  | (((- (IData)(
                                                                 ((IData)(vlSelfRef.func) 
                                                                  & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_5)))) 
                                                      & (IData)(vlSelfRef.top__DOT__and_result)) 
                                                     | ((((IData)(vlSelfRef.A) 
                                                          | (IData)(vlSelfRef.B)) 
                                                         & (- (IData)(
                                                                      ((~ (IData)(vlSelfRef.func)) 
                                                                       & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_7))))) 
                                                        | (((IData)(vlSelfRef.top__DOT__xor_result) 
                                                            & (- (IData)(
                                                                         ((IData)(vlSelfRef.func) 
                                                                          & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_7))))) 
                                                           | (1U 
                                                              & (((- (IData)(
                                                                             (7U 
                                                                              == (IData)(vlSelfRef.func)))) 
                                                                  & (~ 
                                                                     (0U 
                                                                      != (IData)(vlSelfRef.top__DOT__xor_result)))) 
                                                                 | ((- (IData)((IData)(
                                                                                (6U 
                                                                                == (IData)(vlSelfRef.func))))) 
                                                                    & ((IData)(vlSelfRef.top__DOT__sub_unit__DOT__c3) 
                                                                       ^ 
                                                                       (((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_6) 
                                                                         ^ (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0)) 
                                                                        >> 3U))))))))))));
            vlSelfRef.zero = ((~ (0U != (IData)(vlSelfRef.out))) 
                              & ((IData)(vlSelfRef.top__DOT__s1) 
                                 | (IData)(vlSelfRef.top__DOT__s0)));
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 2> &triggers, const std::string &tag);
#endif  // VL_DEBUG

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
                                                        ((((IData)(vlSelfRef.func) 
                                                           != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__func__0)) 
                                                          << 2U) 
                                                         | ((((IData)(vlSelfRef.B) 
                                                              != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__B__0)) 
                                                             << 1U) 
                                                            | ((IData)(vlSelfRef.A) 
                                                               != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__A__0))))));
        vlSelfRef.__Vtrigprevexpr___TOP__A__0 = vlSelfRef.A;
        vlSelfRef.__Vtrigprevexpr___TOP__B__0 = vlSelfRef.B;
        vlSelfRef.__Vtrigprevexpr___TOP__func__0 = vlSelfRef.func;
        if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__VicoDidInit)))))) {
            vlSelfRef.__VicoDidInit = 1U;
            vlSelfRef.__VicoTriggered[0U] = (1ULL | vlSelfRef.__VicoTriggered[0U]);
            vlSelfRef.__VicoTriggered[0U] = (2ULL | vlSelfRef.__VicoTriggered[0U]);
            vlSelfRef.__VicoTriggered[0U] = (4ULL | vlSelfRef.__VicoTriggered[0U]);
        }
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
    __VicoExecute = Vtop___024root___trigger_anySet__ico(vlSelfRef.__VicoTriggered);
    if (__VicoExecute) {
        Vtop___024root___eval_ico(vlSelf);
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
            VL_FATAL_MT("/home/sun/Desktop/OSOC/E\351\230\266\346\256\265/E5/Ex3/vsrc/top.v", 1, "", "DIDNOTCONVERGE: Input combinational region did not converge after '--converge-limit' of 10000 tries");
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
    if (VL_UNLIKELY(((vlSelfRef.A & 0xf0U)))) {
        Verilated::overWidthError("A");
    }
    if (VL_UNLIKELY(((vlSelfRef.B & 0xf0U)))) {
        Verilated::overWidthError("B");
    }
    if (VL_UNLIKELY(((vlSelfRef.func & 0xf8U)))) {
        Verilated::overWidthError("func");
    }
}
#endif  // VL_DEBUG
