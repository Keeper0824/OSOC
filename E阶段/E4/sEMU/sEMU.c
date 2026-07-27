#include <stdint.h>
#include<stdio.h>

uint8_t PC = 0;
uint8_t R[4];
uint8_t M[16] = {
    0x90, // 地址0：li     r1, 0
    0xa0, // 地址1：li     r2, 0
    0xb1, // 地址2：li     r3, 1
    0x17, // 地址3：add    r1, r1, r3
    0x29, // 地址4：add    r2, r2, r1
    0xcd, // 地址5：bner0  3, r1
    0x42, // 地址6：out    r2
    0xdf, // 地址7：bner0  7, r3
};

void inst_cycle()
{
	uint8_t ins=M[PC];
	uint8_t opcode=(ins>>6)&3;
	switch(opcode){
	case 0:
		R[(ins>>4)&3]=R[(ins>>2)&3]+R[(ins>>0)&3];
		break;
	case 1:
		printf("sum = %u\n", (unsigned)R[(ins>>0)&3]);
		break;
	case 2:
		R[(ins>>4)&3]=ins&0x0f;
		break;
	case 3:
		if (R[0]!=R[(ins>>0)&3]) {
			PC=(ins>>2)&0x0f;
			return;
		}
		break;
		}
		
	PC=(PC+1)&0x0f;
}

int main(int argc,char* argv[])
{

R[0]=(uint8_t)strtoul(argv[1], NULL, 10);;
for (int i = 0; i < 100; i++) {
    inst_cycle();
}

//printf("sum = %u\n", (unsigned)R[2]);
	return 0;
}
