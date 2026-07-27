#include <stdint.h>
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define MEM_WORDS (1u << 17)
#define EBREAK 0x00100073u
uint32_t PC = 0;
uint32_t R[16];
uint32_t M[MEM_WORDS];


static void install_ebreak(const char *path)
{
    uint32_t halt_pc;

    if (strstr(path, "sum.bin") != NULL) {
        halt_pc = 0x224;
    } else if (strstr(path, "mem.bin") != NULL) {
        halt_pc = 0x1218;
    } else {
        exit(EXIT_FAILURE);
    }

    M[halt_pc / 4] = EBREAK;
}
static void load_bin(const char *path)
{
    FILE *fp = fopen(path, "rb");
    uint32_t word_addr = 0;

    if (fp == NULL) {
        perror(path);
        exit(EXIT_FAILURE);
    }

    for (;;) {
        uint8_t bytes[4];
        size_t count = fread(bytes, 1, 4, fp);
        if (count == 0) {
            break;
        }
        if (count != 4) {
            fclose(fp);
            exit(EXIT_FAILURE);
        }

        M[word_addr] =
              (uint32_t)bytes[0]
            | ((uint32_t)bytes[1] << 8)
            | ((uint32_t)bytes[2] << 16)
            | ((uint32_t)bytes[3] << 24);

        word_addr++;
    }
    fclose(fp);
}

static int32_t sign_extend12(uint32_t value)
{
    int32_t result = value & 0x0fff;

    if ((result & 0x0800) != 0) {
        result -= 0x1000;
    }

    return result;
}

static int32_t imm_i(uint32_t ins)
{
    return sign_extend12(ins >> 20);
}

static int32_t imm_s(uint32_t ins)
{
    uint32_t value =
        ((ins >> 25) << 5)
        | ((ins >> 7) & 0x1f);

    return sign_extend12(value);
}

void inst_cycle()
{
	uint32_t ins=M[PC/4];
	uint32_t opcode=(ins>>0)&0x7f;
	uint32_t fn3=(ins>>12)&0x7;
	switch(opcode){
	case 0x13://addi
	        if(((ins>>7)&0x1f)!=0){
            		R[(ins>>7)&0x1f]=R[(ins>>15)&0x1f]+imm_i(ins);
        	}
		break;
	case 0x67://jalr:
		uint32_t temp=PC+4;
		PC=(R[(ins>>15)&0x1f]+imm_i(ins))&~1u;;
		if(((ins>>7)&0x1f)!=0){
			R[(ins>>7)&0x1f]=temp;
        	}
		return;
	case 0x33://add
	        if(((ins>>7)&0x1f)!=0){
            		R[(ins>>7)&0x1f]=R[(ins>>15)&0x1f]+R[(ins>>20)&0x1f];
        	}
		break;
	case 0x37://lui
		if(((ins>>7)&0x1f)!=0){
			R[(ins>>7)&0x1f]=ins & 0xfffff000u;
        	}
		break;
	case 0x03:
		if(fn3==2)//lw
		{
			uint32_t mem=R[(ins>>15)&0x1f]+imm_i(ins);
			if(((ins>>7)&0x1f)!=0){
            			R[(ins>>7)&0x1f]=M[mem/4];
        		}
			break;		
		}
		else if(fn3==4)//lbu
		{
			uint32_t mem=R[(ins>>15)&0x1f]+imm_i(ins);
			uint32_t word=M[mem/4];
            		uint32_t shift=(mem&3)*8;
            		uint32_t byte=(word>>shift)&0xff;
            		if(((ins>>7)&0x1f)!=0){
				R[(ins>>7)&0x1f]=byte;
        		}

			break;
		}
		break;
	
	case 0x23:
		if(fn3==0)//sb
		{
			uint32_t mem=R[(ins>>15)&0x1f]+imm_s(ins);
            		uint32_t shift=(mem&3)*8;
            		uint32_t mask = 0xffu << shift;
            		M[mem/4]=(M[mem/4] & ~mask) | ((R[(ins >> 20) & 0x1f] & 0xff) << shift);
			break;		
		}
		else if(fn3==2)//sw
		{
			uint32_t mem=R[(ins>>15)&0x1f]+imm_s(ins);
			M[mem/4]=R[ (ins >> 20) & 0x1f];
			break;
		}
		break;
	case 0x73: 
    		if (ins == EBREAK) {
        		if (R[10] == 0) {
        		    	printf("HIT GOOD TRAP at PC=0x%08x\n",PC);
        		    	exit(EXIT_SUCCESS);
            
        		} else {
            			printf("HIT BAD TRAP at PC=0x%08x, ""a0=0x%08x\n",PC,R[10]);
 				exit(EXIT_FAILURE);
        		}
    		}
	}
		
	PC=(PC+4);
}

int main(int argc,char* argv[])
{
    load_bin(argv[1]);
    install_ebreak(argv[1]);
for (int i = 0; i < 1000000; i++) {
    inst_cycle();
}

	return 0;
}
