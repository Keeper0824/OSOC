// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__A__0 = vlSelfRef.A;
    vlSelfRef.__Vtrigprevexpr___TOP__B__0 = vlSelfRef.B;
    vlSelfRef.__Vtrigprevexpr___TOP__func__0 = vlSelfRef.func;
}

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_final\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("/home/sun/Desktop/OSOC/E\351\230\266\346\256\265/E5/Ex3/vsrc/top.v", 1, "", "DIDNOTCONVERGE: Settle region did not converge after '--converge-limit' of 10000 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        vlSelfRef.__VstlPhaseResult = Vtop___024root___eval_phase__stl(vlSelf);
        vlSelfRef.__VstlFirstIteration = 0U;
    } while (vlSelfRef.__VstlPhaseResult);
}

VL_ATTR_COLD bool Vtop___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vtop___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__stl\n"); );
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

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_4;
    __VdfgRegularize_h6e95ff9d_0_4 = 0;
    // Body
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_5 = (IData)(
                                                       (2U 
                                                        == 
                                                        (6U 
                                                         & (IData)(vlSelfRef.func))));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_7 = (IData)(
                                                       (4U 
                                                        == 
                                                        (6U 
                                                         & (IData)(vlSelfRef.func))));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0 = (0x0000000fU 
                                                & ((~ (IData)(vlSelfRef.B)) 
                                                   ^ (IData)(vlSelfRef.A)));
    __VdfgRegularize_h6e95ff9d_0_4 = (IData)((0U == 
                                              (6U & (IData)(vlSelfRef.func))));
    vlSelfRef.top__DOT__xor_result = ((IData)(vlSelfRef.A) 
                                      ^ (IData)(vlSelfRef.B));
    vlSelfRef.top__DOT__and_result = ((IData)(vlSelfRef.A) 
                                      & (IData)(vlSelfRef.B));
    vlSelfRef.top__DOT__sub_unit__DOT__c1 = (1U & (
                                                   (~ (IData)(vlSelfRef.B)) 
                                                   | (IData)(vlSelfRef.A)));
    vlSelfRef.top__DOT__s0 = ((~ (IData)(vlSelfRef.func)) 
                              & (IData)(__VdfgRegularize_h6e95ff9d_0_4));
    vlSelfRef.top__DOT__s1 = ((IData)(vlSelfRef.func) 
                              & (IData)(__VdfgRegularize_h6e95ff9d_0_4));
    vlSelfRef.top__DOT__add_unit__DOT__c2 = (1U & (
                                                   (((IData)(vlSelfRef.A) 
                                                     >> 1U) 
                                                    & (((IData)(vlSelfRef.B) 
                                                        >> 1U) 
                                                       | (IData)(vlSelfRef.top__DOT__and_result))) 
                                                   | (((IData)(vlSelfRef.B) 
                                                       >> 1U) 
                                                      & (IData)(vlSelfRef.top__DOT__and_result))));
    vlSelfRef.top__DOT__sub_unit__DOT__c2 = (1U & (
                                                   (((IData)(vlSelfRef.A) 
                                                     >> 1U) 
                                                    & ((~ 
                                                        ((IData)(vlSelfRef.B) 
                                                         >> 1U)) 
                                                       | (IData)(vlSelfRef.top__DOT__sub_unit__DOT__c1))) 
                                                   | ((~ 
                                                       ((IData)(vlSelfRef.B) 
                                                        >> 1U)) 
                                                      & (IData)(vlSelfRef.top__DOT__sub_unit__DOT__c1))));
    vlSelfRef.top__DOT__add_unit__DOT__c3 = (1U & (
                                                   (((IData)(vlSelfRef.A) 
                                                     >> 2U) 
                                                    & (((IData)(vlSelfRef.B) 
                                                        >> 2U) 
                                                       | (IData)(vlSelfRef.top__DOT__add_unit__DOT__c2))) 
                                                   | (((IData)(vlSelfRef.B) 
                                                       >> 2U) 
                                                      & (IData)(vlSelfRef.top__DOT__add_unit__DOT__c2))));
    vlSelfRef.top__DOT__sub_unit__DOT__c3 = (1U & (
                                                   (((IData)(vlSelfRef.A) 
                                                     >> 2U) 
                                                    & ((~ 
                                                        ((IData)(vlSelfRef.B) 
                                                         >> 2U)) 
                                                       | (IData)(vlSelfRef.top__DOT__sub_unit__DOT__c2))) 
                                                   | ((~ 
                                                       ((IData)(vlSelfRef.B) 
                                                        >> 2U)) 
                                                      & (IData)(vlSelfRef.top__DOT__sub_unit__DOT__c2))));
    vlSelfRef.top__DOT__add_result = (((((IData)(vlSelfRef.top__DOT__add_unit__DOT__c3) 
                                         ^ ((IData)(vlSelfRef.top__DOT__xor_result) 
                                            >> 3U)) 
                                        << 3U) | (4U 
                                                  & (((IData)(vlSelfRef.top__DOT__add_unit__DOT__c2) 
                                                      << 2U) 
                                                     ^ 
                                                     (0xfffffffcU 
                                                      & (IData)(vlSelfRef.top__DOT__xor_result))))) 
                                      | ((2U & (((IData)(vlSelfRef.top__DOT__and_result) 
                                                 << 1U) 
                                                ^ (0xfffffffeU 
                                                   & (IData)(vlSelfRef.top__DOT__xor_result)))) 
                                         | (1U & (IData)(vlSelfRef.top__DOT__xor_result))));
    vlSelfRef.carry = ((((((IData)(vlSelfRef.A) >> 3U) 
                          & ((~ ((IData)(vlSelfRef.B) 
                                 >> 3U)) | (IData)(vlSelfRef.top__DOT__sub_unit__DOT__c3))) 
                         | ((~ ((IData)(vlSelfRef.B) 
                                >> 3U)) & (IData)(vlSelfRef.top__DOT__sub_unit__DOT__c3))) 
                        & (IData)(vlSelfRef.top__DOT__s1)) 
                       | (((((IData)(vlSelfRef.A) >> 3U) 
                            & (((IData)(vlSelfRef.B) 
                                >> 3U) | (IData)(vlSelfRef.top__DOT__add_unit__DOT__c3))) 
                           | (((IData)(vlSelfRef.B) 
                               >> 3U) & (IData)(vlSelfRef.top__DOT__add_unit__DOT__c3))) 
                          & (IData)(vlSelfRef.top__DOT__s0)));
    vlSelfRef.top__DOT__sub_result = (((((IData)(vlSelfRef.top__DOT__sub_unit__DOT__c3) 
                                         ^ ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0) 
                                            >> 3U)) 
                                        << 3U) | (4U 
                                                  & (((IData)(vlSelfRef.top__DOT__sub_unit__DOT__c2) 
                                                      << 2U) 
                                                     ^ 
                                                     (0xfffffffcU 
                                                      & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0))))) 
                                      | ((2U & (((IData)(vlSelfRef.top__DOT__sub_unit__DOT__c1) 
                                                 << 1U) 
                                                ^ (0xfffffffeU 
                                                   & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0)))) 
                                         | (1U & (~ (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0)))));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_6 = ((IData)(vlSelfRef.top__DOT__xor_result) 
                                                & ((IData)(vlSelfRef.A) 
                                                   ^ (IData)(vlSelfRef.top__DOT__sub_result)));
    vlSelfRef.overflow = (((IData)(vlSelfRef.top__DOT__s0) 
                           & ((~ ((IData)(vlSelfRef.top__DOT__xor_result) 
                                  >> 3U)) & (((IData)(vlSelfRef.A) 
                                              ^ (IData)(vlSelfRef.top__DOT__add_result)) 
                                             >> 3U))) 
                          | (((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_6) 
                              >> 3U) & (IData)(vlSelfRef.top__DOT__s1)));
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

VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__stl
        vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                          & vlSelfRef.__VstlTriggered[0U]) 
                                         | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vtop___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        {
            // Inlined CFunc: _eval_stl
            if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
                Vtop___024root___stl_sequent__TOP__0(vlSelf);
                {
                    // Inlined CFunc: __Vm_traceActivitySetAll
                    vlSelfRef.__Vm_traceActivity[0U] = 1U;
                    vlSelfRef.__Vm_traceActivity[1U] = 1U;
                }
            }
        }
    }
    return (__VstlExecute);
}

bool Vtop___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 2> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 2> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @( A)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @( B)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @( func)\n");
    }
    if ((1U & (IData)(triggers[1U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 64 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->A = 0;
    vlSelf->B = 0;
    vlSelf->func = 0;
    vlSelf->out = 0;
    vlSelf->zero = 0;
    vlSelf->overflow = 0;
    vlSelf->carry = 0;
    vlSelf->top__DOT__s0 = 0;
    vlSelf->top__DOT__s1 = 0;
    vlSelf->top__DOT__add_result = 0;
    vlSelf->top__DOT__sub_result = 0;
    vlSelf->top__DOT__and_result = 0;
    vlSelf->top__DOT__xor_result = 0;
    vlSelf->top__DOT__sub_unit__DOT__c1 = 0;
    vlSelf->top__DOT__sub_unit__DOT__c2 = 0;
    vlSelf->top__DOT__sub_unit__DOT__c3 = 0;
    vlSelf->top__DOT__add_unit__DOT__c2 = 0;
    vlSelf->top__DOT__add_unit__DOT__c3 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_0 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_5 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_6 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_7 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__A__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__B__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__func__0 = 0;
    vlSelf->__VicoDidInit = 0;
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
