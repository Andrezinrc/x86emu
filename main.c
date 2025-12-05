#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "cpu.h"
#include "memory.h"
#include "disasm.h"



int main(){
    
    struct CPU cpu;
    uint8_t *memory = mem_create();
    cpu_init(&cpu, MEM_SIZE);
    
    
    FILE* f = fopen("test.bin", "rb");
    if(!f){
        perror("Erro abrindo binário");
       exit(1);
    }
    
    fread(memory, 1, 65536, f);
    fclose(f);
    
    
    while(1){
        cpu_step(&cpu, memory);
        disassemble(memory, cpu.eip);
        //print_state(&cpu);
   
        if(cpu.eip >= MEM_SIZE || memory[cpu.eip] == 0xF4) break; 
    }

    return 0;
}

