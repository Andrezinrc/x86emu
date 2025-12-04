#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cpu.h"
#include "memory.h"

void cpu_init(struct CPU *cpu, uint32_t mem_size) {
    memset(cpu, 0, sizeof(struct CPU));
    cpu->esp.e = mem_size - 4;
    cpu->eip = 0;
}

void update_ZF_SF(struct CPU *cpu, uint32_t res){
    cpu->flags.ZF = (res == 0);
    cpu->flags.SF = (res >> 31) & 1;
}

void cpu_step(struct CPU *cpu, uint8_t *memory) {
    uint8_t opcode = mem_read8(memory, cpu->eip);

    switch (opcode) {

        case 0xB8: { // MOV EAX, imm32
            uint32_t imm = mem_read32(memory, cpu->eip + 1);
            cpu->eax.e = imm;
            cpu->eip += 5;
            break;
        }

        case 0xB9: { // MOV ECX, imm32
            uint32_t imm = mem_read32(memory, cpu->eip + 1);
            cpu->ecx.e = imm;
            cpu->eip += 5;
            break;
        }
        
        case 0x89: { // MOV r/m32, r32
            uint8_t modrm = mem_read8(memory, cpu->eip + 1);
            if(modrm == 0xC1){
                cpu->ecx.e = cpu->eax.e;
                cpu->eip += 2;
                break;
            } else {
                printf("MOV com modrm nao suportado. %02X\n", modrm);
                exit(1);
            }
        }
        
        case 0x05: { // ADD EAX, imm32
            uint32_t imm = mem_read32(memory, cpu->eip + 1);
            uint32_t a = cpu->eax.e;
            uint32_t res = a + imm;
            cpu->eax.e = res;
            update_ZF_SF(cpu, res);
            cpu->eip += 5;
            break;
        }
        
        
        
        case 0xF4: {
            printf("Encerrando.\n");
            exit(1);
        }
        
        
        default:
            printf("Opcode desconhecido em EIP=0x%08X: 0x%02X\n",
                   cpu->eip, opcode);
            exit(1);
    }
}

