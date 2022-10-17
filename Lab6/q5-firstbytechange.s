	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 12, 0	sdk_version 12, 1
	.globl	_addnum                         ## -- Begin function addnum
	.p2align	4, 0x90
_addnum:                                ## @addnum
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movl	%edi, -4(%rbp)
	movl	-4(%rbp), %eax
	addl	$255, %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_main                           ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$80, %rsp
	movl	$0, -4(%rbp)
	movl	%edi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movw	l___const.main.data(%rip), %ax
	movw	%ax, -58(%rbp)
	leaq	_addnum(%rip), %rax
	movq	%rax, -40(%rbp)
	movl	$10, %edi
	callq	*-40(%rbp)
	movl	%eax, -28(%rbp)
	movl	-28(%rbp), %esi
	movq	-40(%rbp), %rdx
	leaq	L_.str(%rip), %rdi
	movb	$0, %al
	callq	_printf
	xorl	%eax, %eax
	movl	%eax, %r9d
	movq	%r9, %rdi
	movl	$4096, %esi                     ## imm = 0x1000
	movl	$7, %edx
	movl	$4098, %ecx                     ## imm = 0x1002
	movl	$4294967295, %r8d               ## imm = 0xFFFFFFFF
	callq	_mmap
	movq	%rax, -48(%rbp)
	movq	-48(%rbp), %rsi
	leaq	L_.str.1(%rip), %rdi
	movb	$0, %al
	callq	_printf
	leaq	_addnum(%rip), %rsi
	movq	-48(%rbp), %rdi
	movl	$32, %edx
	movq	$-1, %rcx
	callq	___memcpy_chk
	movq	-48(%rbp), %rax
	movq	%rax, -40(%rbp)
	movl	$10, %edi
	callq	*-40(%rbp)
	movl	%eax, -28(%rbp)
	movl	-28(%rbp), %esi
	movq	-40(%rbp), %rdx
	leaq	L_.str.2(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movq	-48(%rbp), %rdi
	movl	$255, %esi
	callq	_index
	movq	%rax, -56(%rbp)
	movq	-56(%rbp), %rax
	movq	%rax, -72(%rbp)
	movq	-56(%rbp), %rax
	movsbl	(%rax), %esi
	leaq	L_.str.3(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movq	-56(%rbp), %rax
	movb	$100, (%rax)
	movq	-56(%rbp), %rax
	movsbl	(%rax), %esi
	leaq	L_.str.4(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	$10, %edi
	callq	*-40(%rbp)
	movl	%eax, -28(%rbp)
	movl	-28(%rbp), %esi
	leaq	L_.str.5(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	$10, %edi
	callq	*-40(%rbp)
	movl	%eax, -28(%rbp)
	movl	-28(%rbp), %esi
	leaq	L_.str.6(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	-28(%rbp), %esi
	leaq	L_.str.7(%rip), %rdi
	movb	$0, %al
	callq	_printf
	leaq	-58(%rbp), %rsi
	movq	-48(%rbp), %rdi
	movl	$2, %edx
	movq	$-1, %rcx
	callq	___memcpy_chk
	leaq	L_.str.8(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	$10, %edi
	callq	*-40(%rbp)
	movl	%eax, %ecx
	xorl	%eax, %eax
	movl	%ecx, -28(%rbp)
	addq	$80, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__const
l___const.main.data:                    ## @__const.main.data
	.ascii	"\017\013"

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"1: f(10)=%d f=%p\n\n"

L_.str.1:                               ## @.str.1
	.asciz	"code_buf %p\n"

L_.str.2:                               ## @.str.2
	.asciz	"2: f(10)=%d f=%p\n\n"

L_.str.3:                               ## @.str.3
	.asciz	"before *p=%hhx\n"

L_.str.4:                               ## @.str.4
	.asciz	"after *p=%hhx\n"

L_.str.5:                               ## @.str.5
	.asciz	"3: f(10)=%d\n\n"

L_.str.6:                               ## @.str.6
	.asciz	"4: f(10)=%d\n\n"

L_.str.7:                               ## @.str.7
	.asciz	"4: f(10)=%p\n\n"

L_.str.8:                               ## @.str.8
	.asciz	"before last call\n"

.subsections_via_symbols
