always @(posedge clk or negedge rstn) begin
  if (!rstn) a = 1'b0;
  else a = 1;
end

always @(posedge clk) begin
  $display("a = %d", a);//race condition
end

always @(posedge clk or negedge rstn) begin
  if (!rstn) a = 1'b0;
  else a = 1;
  $display("a = %d", a);//new
end

always @(posedge clk or negedge rstn) begin
  if (!rstn) a = 1'b0;
  else a <= 1;
end

always @(posedge clk) begin
  $display("a = %d", a);//old
end

always @(posedge clk or negedge rstn) begin
  if (!rstn)
    a = 1'b0;
  else
    a = 1'b1;
end

always @(posedge clk) begin
  $strobe("a = %d", a); //read and output new a
end

iverilog //event
verilator //cycle
yosys hierarchy -check -top xxx
dump 
proc opt fsm memory
techmap   splitnets -ports   opt -full
dfflibmap -liberty cell.lib   read_liberty -lib cell.lib  abc -liberty cell.lib
write_verilog netlist.v
stat -liberty cell.lib


尝试查阅NAND2X1H7L, NAND2X2H7L和NAND2X4H7L的相关属性, 对比其面积和功耗.
0.8 1.4 2.4
    area : 1.12;
    cell_footprint : "NAND2X1H7L";
    cell_leakage_power : 0.434974;
    
        area : 1.96;
    cell_footprint : "NAND2X2H7L";
    cell_leakage_power : 0.750363;
    
        area : 3.36;
    cell_footprint : "NAND2X4H7L";
    cell_leakage_power : 1.50065;
    
    
尝试查阅ICsprout55中的相关文件, 了解一个二输入与非门的尺寸以及一个I/O单元的尺寸, 并对比它们.
        area : 3.08;
    cell_footprint : "NAND2X6H7L";
    cell_leakage_power : 1.66701;
    
    MACRO NAND2X6H7L
  CLASS CORE ;
  ORIGIN 0 0 ;
  FOREIGN NAND2X6H7L 0 0 ;
  SIZE 2.2 BY 1.4 ;s
    
    
		cell_leakage_power : 0.000000e+00;
		area : 8450.000000;
		pad_cell : true;
		
		MACRO P65_1233_PBMUX
  CLASS PAD ;
  ORIGIN 0 20 ;
  FOREIGN P65_1233_PBMUX 0 -20 ;
  SIZE 65 BY 130 ;
  
  
以ADDHX1H7L为例, 尝试从标准单元库的相关文件中找到这个标准单元的面积和晶体管结构. 假设某标准单元库不提供半加器的标准单元, 需要通过若干基本逻辑门的标准单元来搭建半加器, 请计算此时所需的面积和晶体管数量.
    area : 5.6;
    cell_footprint : "ADDHX1H7L";
    cell_leakage_power : 4.01715;
    .SUBCKT ADDHX1H7L A B CO S VDD VSS
*.PININFO A:I B:I CO:O S:O VDD:B VSS:B
XI13 BN B net45 net_25 VDD VSS / TG pl=6E-08 pw=3.4E-07 nl=6E-08 nw=2.4E-07
XXI12 B BN net034 net_25 VDD VSS / TG pl=6E-08 pw=3.4E-07 nl=6E-08 nw=2.4E-07
XI12 A VDD VSS net45 / INV pl=6E-08 pw=3.4E-07 nl=6E-08 nw=2.4E-07
XI14 net_25 VDD VSS S / INV pl=6E-08 pw=3.4E-07 nl=6E-08 nw=2.4E-07
XXI11 net45 VDD VSS net034 / INV pl=6E-08 pw=2.8E-07 nl=6E-08 nw=2E-07
XI9 B VDD VSS BN / INV pl=6E-08 pw=3.4E-07 nl=6E-08 nw=2.4E-07
XI11 net_7 VDD VSS CO / INV pl=6E-08 pw=3.4E-07 nl=6E-08 nw=2.4E-07
XI10 B A VDD VSS net_7 / NAND2 pl=6E-08 pw=2E-07 nl=6E-08 nw=2E-07
.ENDS
    
    
    area : 2.8;
    cell_footprint : "XOR2X1H7L";
    cell_leakage_power : 2.12759;
    .SUBCKT XOR2X1H7L A B VDD VSS Y
*.PININFO A:I B:I Y:O VDD:B VSS:B
XI0 AN A BN net19 VDD VSS / TG pl=6e-08 pw=1.9e-07 nl=6e-08 nw=1.5e-07
XI5 net19 VDD VSS Y / INV pl=6e-08 pw=2.7e-07 nl=6e-08 nw=2.1e-07
XI1 B VDD VSS BN / INV pl=6e-08 pw=1.9e-07 nl=6e-08 nw=1.5e-07
XI4 A VDD VSS AN / INV pl=6e-08 pw=1.9e-07 nl=6e-08 nw=1.5e-07
XI3 BN A AN VDD VSS net19 / TSINV pl=6e-08 pw=1.9e-07 nl=6e-08 nw=1.5e-07
.ENDS
    
    area : 1.68;
    cell_footprint : "AND2X1H7L";
    cell_leakage_power : 0.698496;
    .SUBCKT AND2X1H7L A B VDD VSS Y
*.PININFO A:I B:I Y:O VDD:B VSS:B
MMN0 net26 B net6 VSS nm1p2_lvt_lp W=150n L=60n m=1
MMN1 net6 A VSS VSS nm1p2_lvt_lp W=150n L=60n m=1
MPM0 net26 B VDD VDD pm1p2_lvt_lp W=190n L=60n m=1
MMP0 net26 A VDD VDD pm1p2_lvt_lp W=190n L=60n m=1
XXI2 net26 VDD VSS Y / INV pl=6e-08 pw=2.7e-07 nl=6e-08 nw=2.1e-07
.ENDS
  
  
标准单元库通常提供不同尺寸的填充单元, 用于填充芯片中没有摆放标准单元的空白位置. 以ICsprout55为例, 尝试在相关文件中找到最小填充单元的尺寸, 这个尺寸和标准单元的SITE属性有什么关联? 为什么?  
MACRO FILLER1H7L
  CLASS CORE ;
  ORIGIN 0 0 ;
  FOREIGN FILLER1H7L 0 0 ;
  SIZE 0.2 BY 1.4 ;
  SYMMETRY X Y ;
  SITE core7 ;
  PIN VDD
    DIRECTION INOUT ;
    USE POWER ;
    SHAPE ABUTMENT ;
    PORT
      LAYER MET1 ;
        RECT 0 1.32 0.2 1.48 ;
    END
  END VDD
  PIN VSS
    DIRECTION INOUT ;
    USE GROUND ;
    SHAPE ABUTMENT ;
    PORT
      LAYER MET1 ;
        RECT 0 -0.08 0.2 0.08 ;
    END
  END VSS
END FILLER1H7L

h7 core7
FILLER2H7L h7 core7   SIZE 0.4 BY 1.4 ;



