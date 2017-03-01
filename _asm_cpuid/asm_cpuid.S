section .text
    global _start
_start:
    mov	   eax, 0
    cpuid
    mov rax, 60
    mov rdi, 0
    syscall
