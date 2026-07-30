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
        bufp->chgSData(oldp+0,(vlSelfRef.top__DOT__buffer),10);
        bufp->chgCData(oldp+1,(vlSelfRef.top__DOT__count),4);
        bufp->chgCData(oldp+2,(vlSelfRef.top__DOT__ps2_clk_sync),3);
        bufp->chgCData(oldp+3,(vlSelfRef.top__DOT__out),8);
        bufp->chgCData(oldp+4,(vlSelfRef.top__DOT__recv_count),8);
        bufp->chgCData(oldp+5,(vlSelfRef.top__DOT__scan_to_ascii),8);
        bufp->chgBit(oldp+6,(vlSelfRef.top__DOT__key_down));
        bufp->chgBit(oldp+7,(vlSelfRef.top__DOT__break_pending));
        bufp->chgBit(oldp+8,((IData)((4U == (6U & (IData)(vlSelfRef.top__DOT__ps2_clk_sync))))));
    }
    bufp->chgBit(oldp+9,(vlSelfRef.clk));
    bufp->chgBit(oldp+10,(vlSelfRef.ps2_clk));
    bufp->chgBit(oldp+11,(vlSelfRef.ps2_data));
    bufp->chgBit(oldp+12,(vlSelfRef.resetn));
    bufp->chgCData(oldp+13,(vlSelfRef.seg0),8);
    bufp->chgCData(oldp+14,(vlSelfRef.seg1),8);
    bufp->chgCData(oldp+15,(vlSelfRef.seg2),8);
    bufp->chgCData(oldp+16,(vlSelfRef.seg3),8);
    bufp->chgCData(oldp+17,(vlSelfRef.seg4),8);
    bufp->chgCData(oldp+18,(vlSelfRef.seg5),8);
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
