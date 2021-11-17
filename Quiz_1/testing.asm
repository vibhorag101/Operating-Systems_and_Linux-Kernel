extern printf

section .text
	global main

main:
    mov rax, 0x1234567812345678
    xor ax, 0x11
    mov rsi, rax
    call printf
    xor rax, 0x11
    mov rsi, rax
    call printf
