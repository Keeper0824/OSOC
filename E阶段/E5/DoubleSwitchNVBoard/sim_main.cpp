#include "Vtop.h"
#include "verilated.h"
#include "verilated_fst_c.h"
#include <nvboard.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void nvboard_bind_all_pins(Vtop* top);

int main(int argc, char **argv) {
  VerilatedContext *contextp = new VerilatedContext;
  contextp->commandArgs(argc, argv);
  Vtop dut{contextp};
  
  VerilatedFstC *tfp = new VerilatedFstC;
  contextp->traceEverOn(true);
  dut.trace(tfp, 0);
  tfp->open("wave.fst");
  nvboard_bind_all_pins(&dut);
  nvboard_init();
   
    
  while (!contextp->gotFinish()) {
        nvboard_update();
        dut.eval();        
        tfp->dump(contextp->time()); // dump wave
    	contextp->timeInc(1);
  }

    dut.final();
    tfp->close();
    nvboard_quit();
  delete tfp;
  delete contextp;
  return 0;
}
