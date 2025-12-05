BITS 32

    mov eax, 5
    add eax, 10
    cmp eax, 15
    jne fim

    add eax, 20

fim:
    nop
    hlt
