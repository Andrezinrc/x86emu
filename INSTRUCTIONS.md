# adr86 Instruction Set

### General
- mov eax, imm32  (0xB8)
- mov ecx, imm32  (0xB9)

### Arithmetic
- add eax, ecx    (0x01 C8)
- sub eax, ecx    (0x29 C8)
- add eax, imm8   (0x83 C0 ib)
- sub eax, imm8   (0x83 E8 ib)

### Logic
- xor eax, eax    (0x31 C0)

### Control Flow
- cmp eax, ecx    (0x39 C8)
- cmp eax, imm8   (0x83 F8 ib)
- jne rel8        (0x75 cb)
- jmp rel8        (0xEB cb)

### Misc
- nop             (0x90)
- clc             (0xF8)
- hlt             (0xF4)
