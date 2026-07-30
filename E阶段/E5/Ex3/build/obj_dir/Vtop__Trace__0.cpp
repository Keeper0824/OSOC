// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_fst_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp);

void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0\n"); );
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vtop___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 0);
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        bufp->chgCData(oldp+0,(vlSelfRef.top__DOT__add_result),4);
        bufp->chgCData(oldp+1,(vlSelfRef.top__DOT__sub_result),4);
        bufp->chgCData(oldp+2,(vlSelfRef.top__DOT__and_result),4);
        bufp->chgCData(oldp+3,(vlSelfRef.top__DOT__xor_result),4);
        bufp->chgCData(oldp+4,((1U & ((IData)(vlSelfRef.top__DOT__sub_unit__DOT__c3) 
                                      ^ (((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_6) 
                                          ^ (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0)) 
                                         >> 3U)))),4);
        bufp->chgCData(oldp+5,((1U & (~ (0U != (IData)(vlSelfRef.top__DOT__xor_result))))),4);
        bufp->chgBit(oldp+6,((1U & ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_6) 
                                    >> 3U))));
        bufp->chgBit(oldp+7,((1U & ((IData)(vlSelfRef.top__DOT__sub_unit__DOT__c3) 
                                    ^ (((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_6) 
                                        ^ (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0)) 
                                       >> 3U)))));
        bufp->chgBit(oldp+8,((1U & (~ (0U != (IData)(vlSelfRef.top__DOT__xor_result))))));
        bufp->chgBit(oldp+9,((1U & (IData)(vlSelfRef.top__DOT__and_result))));
        bufp->chgBit(oldp+10,(vlSelfRef.top__DOT__add_unit__DOT__c2));
        bufp->chgBit(oldp+11,(vlSelfRef.top__DOT__add_unit__DOT__c3));
        bufp->chgBit(oldp+12,((1U & (IData)(vlSelfRef.top__DOT__xor_result))));
        bufp->chgBit(oldp+13,((1U & ((IData)(vlSelfRef.top__DOT__and_result) 
                                     ^ ((IData)(vlSelfRef.top__DOT__xor_result) 
                                        >> 1U)))));
        bufp->chgBit(oldp+14,((1U & ((IData)(vlSelfRef.top__DOT__add_unit__DOT__c2) 
                                     ^ ((IData)(vlSelfRef.top__DOT__xor_result) 
                                        >> 2U)))));
        bufp->chgBit(oldp+15,(((IData)(vlSelfRef.top__DOT__add_unit__DOT__c3) 
                               ^ ((IData)(vlSelfRef.top__DOT__xor_result) 
                                  >> 3U))));
        bufp->chgBit(oldp+16,(vlSelfRef.top__DOT__sub_unit__DOT__c1));
        bufp->chgBit(oldp+17,(vlSelfRef.top__DOT__sub_unit__DOT__c2));
        bufp->chgBit(oldp+18,(vlSelfRef.top__DOT__sub_unit__DOT__c3));
        bufp->chgBit(oldp+19,((1U & (~ (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0)))));
        bufp->chgBit(oldp+20,((1U & ((IData)(vlSelfRef.top__DOT__sub_unit__DOT__c1) 
                                     ^ ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0) 
                                        >> 1U)))));
        bufp->chgBit(oldp+21,((1U & ((IData)(vlSelfRef.top__DOT__sub_unit__DOT__c2) 
                                     ^ ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0) 
                                        >> 2U)))));
        bufp->chgBit(oldp+22,(((IData)(vlSelfRef.top__DOT__sub_unit__DOT__c3) 
                               ^ ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0) 
                                  >> 3U))));
    }
    bufp->chgCData(oldp+23,(vlSelfRef.A),4);
    bufp->chgCData(oldp+24,(vlSelfRef.B),4);
    bufp->chgCData(oldp+25,(vlSelfRef.func),3);
    bufp->chgCData(oldp+26,(vlSelfRef.out),4);
    bufp->chgBit(oldp+27,(vlSelfRef.zero));
    bufp->chgBit(oldp+28,(vlSelfRef.overflow));
    bufp->chgBit(oldp+29,(vlSelfRef.carry));
    bufp->chgBit(oldp+30,(vlSelfRef.top__DOT__s0));
    bufp->chgBit(oldp+31,(vlSelfRef.top__DOT__s1));
    bufp->chgBit(oldp+32,(((~ (IData)(vlSelfRef.func)) 
                           & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_5))));
    bufp->chgBit(oldp+33,(((IData)(vlSelfRef.func) 
                           & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_5))));
    bufp->chgBit(oldp+34,(((~ (IData)(vlSelfRef.func)) 
                           & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_7))));
    bufp->chgBit(oldp+35,(((IData)(vlSelfRef.func) 
                           & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_7))));
    bufp->chgBit(oldp+36,((IData)((6U == (IData)(vlSelfRef.func)))));
    bufp->chgBit(oldp+37,((7U == (IData)(vlSelfRef.func))));
    bufp->chgBit(oldp+38,((1U & ((((IData)(vlSelfRef.A) 
                                   >> 3U) & (((IData)(vlSelfRef.B) 
                                              >> 3U) 
                                             | (IData)(vlSelfRef.top__DOT__add_unit__DOT__c3))) 
                                 | (((IData)(vlSelfRef.B) 
                                     >> 3U) & (IData)(vlSelfRef.top__DOT__add_unit__DOT__c3))))));
    bufp->chgBit(oldp+39,((1U & ((((IData)(vlSelfRef.A) 
                                   >> 3U) & ((~ ((IData)(vlSelfRef.B) 
                                                 >> 3U)) 
                                             | (IData)(vlSelfRef.top__DOT__sub_unit__DOT__c3))) 
                                 | ((~ ((IData)(vlSelfRef.B) 
                                        >> 3U)) & (IData)(vlSelfRef.top__DOT__sub_unit__DOT__c3))))));
    bufp->chgCData(oldp+40,((0x0000000fU & (~ (IData)(vlSelfRef.A)))),4);
    bufp->chgCData(oldp+41,(((IData)(vlSelfRef.A) | (IData)(vlSelfRef.B))),4);
    bufp->chgBit(oldp+42,((1U & ((~ ((IData)(vlSelfRef.top__DOT__xor_result) 
                                     >> 3U)) & (((IData)(vlSelfRef.A) 
                                                 ^ (IData)(vlSelfRef.top__DOT__add_result)) 
                                                >> 3U)))));
    bufp->chgCData(oldp+43,(vlSelfRef.A),4);
    bufp->chgCData(oldp+44,(vlSelfRef.B),4);
    bufp->chgBit(oldp+45,((1U & (IData)(vlSelfRef.A))));
    bufp->chgBit(oldp+46,((1U & (IData)(vlSelfRef.B))));
    bufp->chgBit(oldp+47,((1U & ((IData)(vlSelfRef.A) 
                                 >> 1U))));
    bufp->chgBit(oldp+48,((1U & ((IData)(vlSelfRef.B) 
                                 >> 1U))));
    bufp->chgBit(oldp+49,((1U & ((IData)(vlSelfRef.A) 
                                 >> 2U))));
    bufp->chgBit(oldp+50,((1U & ((IData)(vlSelfRef.B) 
                                 >> 2U))));
    bufp->chgBit(oldp+51,((1U & ((IData)(vlSelfRef.A) 
                                 >> 3U))));
    bufp->chgBit(oldp+52,((1U & ((IData)(vlSelfRef.B) 
                                 >> 3U))));
    bufp->chgCData(oldp+53,((0x0000000fU & (~ (IData)(vlSelfRef.B)))),4);
    bufp->chgBit(oldp+54,((1U & (~ (IData)(vlSelfRef.B)))));
    bufp->chgBit(oldp+55,((1U & (~ ((IData)(vlSelfRef.B) 
                                    >> 1U)))));
    bufp->chgBit(oldp+56,((1U & (~ ((IData)(vlSelfRef.B) 
                                    >> 2U)))));
    bufp->chgBit(oldp+57,((1U & (~ ((IData)(vlSelfRef.B) 
                                    >> 3U)))));
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
