#include "Vtop.h"
#include "verilated.h"
#include "verilated_fst_c.h"
#include <nvboard.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void nvboard_bind_all_pins(Vtop* top);

void single_cycle(Vtop* top) {
  top->clk = 0; top->eval();
  top->clk = 1; top->eval();
}



int main(int argc, char **argv) {
  VerilatedContext *contextp = new VerilatedContext;
  contextp->commandArgs(argc, argv);
  Vtop dut{contextp};

  nvboard_bind_all_pins(&dut);
  nvboard_init();
   
  //reset(&dut,10); 
  while (!contextp->gotFinish()) {
        nvboard_update();
        single_cycle(&dut);
        dut.eval();        
  }
  dut.final();
  nvboard_quit();
  delete contextp;
  return 0;
}
