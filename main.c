#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "cpu.h"
#include "memory.h"

int main(){
    
    struct CPU cpu;
    uint8_t *memory = mem_create();
    cpu_init(&cpu, MEM_SIZE);
    

    // mov eax, 5
    memory[0] = 0xB8;
    memory[1] = 0x05;
    memory[2] = 0x00;
    memory[3] = 0x00;
    memory[4] = 0x00;
    
    // mov ecx, 3
    memory[5] = 0xB9;
    memory[6] = 0x03;
    memory[7] = 0x00;
    memory[8] = 0x00;
    memory[9] = 0x00;
    
    // mov ecx, eax
    memory[10] = 0x89;
    memory[11] = 0xC1;
    
    // add eax, imm
    memory[12] = 0x05;
    memory[13] = 0x05;
    memory[14] = 0x00;
    memory[15] = 0x00;
    memory[16] = 0x00;
    
    // HLT
    memory[12] = 0xF4;
    
    

    
    while(1){
        cpu_step(&cpu, memory);

        printf("EIP=%04X  EAX=%08X  ECX=%08X  |  FLAGS: ZF=%d SF=%d CF=%d OF=%d\n",
              cpu.eip,
              cpu.eax.e,
              cpu.ecx.e,
              cpu.flags.ZF,
              cpu.flags.SF,
              cpu.flags.CF,
              cpu.flags.OF);

        if(cpu.eip >= MEM_SIZE) break;
    }

    return 0;
}
