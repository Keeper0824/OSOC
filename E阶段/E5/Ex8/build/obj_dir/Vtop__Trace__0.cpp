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
        bufp->chgSData(oldp+0,((0x000003ffU & (((IData)(vlSelfRef.top__DOT__my_vga_ctrl__DOT__x_cnt) 
                                                - (IData)(0x0091U)) 
                                               & (- (IData)((IData)(vlSelfRef.top__DOT__my_vga_ctrl__DOT__h_valid)))))),10);
        bufp->chgSData(oldp+1,(vlSelfRef.top__DOT__v_addr),10);
        bufp->chgIData(oldp+2,(vlSelfRef.top__DOT__vga_data),24);
        bufp->chgSData(oldp+3,(vlSelfRef.top__DOT__my_vga_ctrl__DOT__x_cnt),10);
        bufp->chgSData(oldp+4,(vlSelfRef.top__DOT__my_vga_ctrl__DOT__y_cnt),10);
        bufp->chgBit(oldp+5,(vlSelfRef.top__DOT__my_vga_ctrl__DOT__h_valid));
        bufp->chgBit(oldp+6,(vlSelfRef.top__DOT__my_vga_ctrl__DOT__v_valid));
    }
    bufp->chgBit(oldp+7,(vlSelfRef.clk));
    bufp->chgBit(oldp+8,(vlSelfRef.rst));
    bufp->chgBit(oldp+9,(vlSelfRef.VGA_HSYNC));
    bufp->chgBit(oldp+10,(vlSelfRef.VGA_VSYNC));
    bufp->chgBit(oldp+11,(vlSelfRef.VGA_BLANK_N));
    bufp->chgCData(oldp+12,(vlSelfRef.VGA_R),8);
    bufp->chgCData(oldp+13,(vlSelfRef.VGA_G),8);
    bufp->chgCData(oldp+14,(vlSelfRef.VGA_B),8);
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
