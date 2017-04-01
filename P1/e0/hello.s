	.file	"hello.c"
	.globl	g
	.data
	.align 4
	.type	g, @object
	.size	g, 4
g:
	.long	1000
	.globl	g2
	.align 4
	.type	g2, @object
	.size	g2, 4
g2:
	.long	2000
	.section	.rodata
.LC0:
	.string	"World!"
.LC1:
	.string	"Hello %s\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$.LC0, %esi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.1-2ubuntu1~16.04) 5.4.1 20160904"
	.section	.note.GNU-stack,"",@progbits
