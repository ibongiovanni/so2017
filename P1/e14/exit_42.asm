; Commands for compiling and running:
; nasm -f elf exit_42.asm
; ld -m elf_i386 -s -nostdlib -o exit_42 exit_42.o
; ./exit_42
; echo $?

BITS 32
GLOBAL _start
SECTION .text
_start:
	mov eax, 1	;set syscall number 1 (EXIT)
	mov ebx, 42 ;argument of exit
	int 0x80	;do the syscall
