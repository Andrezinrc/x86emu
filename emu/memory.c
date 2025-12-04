#include "memory.h"
#include <stdlib.h>
#include <string.h>

uint8_t* mem_create() {
    uint8_t *mem = malloc(MEM_SIZE);
    memset(mem, 0, MEM_SIZE);
    return mem;
}

void mem_destroy(uint8_t *mem) {
    free(mem);
}

uint8_t mem_read8(uint8_t *mem, uint32_t addr) {
    return mem[addr];
}

uint32_t mem_read32(uint8_t *mem, uint32_t addr) {
    return mem[addr] |
          (mem[addr+1] << 8) |
          (mem[addr+2] << 16) |
          (mem[addr+3] << 24);
}

void mem_write8(uint8_t *mem, uint32_t addr, uint8_t val) {
    mem[addr] = val;
}



void mem_write32(uint8_t *mem, uint32_t addr, uint32_t val) {
    mem[addr]     =  val        & 0xFF;
    mem[addr + 1] = (val >> 8)  & 0xFF;
    mem[addr + 2] = (val >> 16) & 0xFF;
    mem[addr + 3] = (val >> 24) & 0xFF;
}
