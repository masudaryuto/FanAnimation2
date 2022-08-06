	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 12, 0	sdk_version 12, 3
	.globl	_newView                        ## -- Begin function newView
	.p2align	4, 0x90
_newView:                               ## @newView
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	$0, -8(%rbp)
	movl	$96, %edi
	callq	_malloc
	movq	%rax, -8(%rbp)
	cmpq	$0, -8(%rbp)
	jne	LBB0_2
## %bb.1:
	movl	$1, %edi
	callq	_exit
LBB0_2:
	movq	-8(%rbp), %rax
	movq	$0, (%rax)
	movq	-8(%rbp), %rax
	movq	$0, 8(%rax)
	movq	-8(%rbp), %rax
	movq	$0, 16(%rax)
	movq	-8(%rbp), %rax
	movl	$1, 24(%rax)
	movq	-8(%rbp), %rax
	movl	$1, 28(%rax)
	movq	-8(%rbp), %rax
	leaq	_createFan(%rip), %rcx
	movq	%rcx, 32(%rax)
	movq	-8(%rbp), %rax
	leaq	_createBell(%rip), %rcx
	movq	%rcx, 40(%rax)
	movq	-8(%rbp), %rax
	leaq	_setModel(%rip), %rcx
	movq	%rcx, 48(%rax)
	movq	-8(%rbp), %rax
	leaq	_setController(%rip), %rcx
	movq	%rcx, 56(%rax)
	movq	-8(%rbp), %rax
	leaq	_moveFan(%rip), %rcx
	movq	%rcx, 64(%rax)
	movq	-8(%rbp), %rax
	leaq	_moveBell(%rip), %rcx
	movq	%rcx, 72(%rax)
	movq	-8(%rbp), %rax
	leaq	_soundFan(%rip), %rcx
	movq	%rcx, 80(%rax)
	movq	-8(%rbp), %rax
	leaq	_soundBell(%rip), %rcx
	movq	%rcx, 88(%rax)
	movq	-8(%rbp), %rax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_createFan                      ## -- Begin function createFan
	.p2align	4, 0x90
_createFan:                             ## @createFan
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	$1, 24(%rax)
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_createBell                     ## -- Begin function createBell
	.p2align	4, 0x90
_createBell:                            ## @createBell
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	$1, 24(%rax)
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_setModel                       ## -- Begin function setModel
	.p2align	4, 0x90
_setModel:                              ## @setModel
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	$1, 24(%rax)
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_setController                  ## -- Begin function setController
	.p2align	4, 0x90
_setController:                         ## @setController
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	$1, 24(%rax)
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_moveFan                        ## -- Begin function moveFan
	.p2align	4, 0x90
_moveFan:                               ## @moveFan
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	$1, 24(%rax)
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_moveBell                       ## -- Begin function moveBell
	.p2align	4, 0x90
_moveBell:                              ## @moveBell
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	$1, 24(%rax)
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_soundFan                       ## -- Begin function soundFan
	.p2align	4, 0x90
_soundFan:                              ## @soundFan
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	$1, 24(%rax)
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_soundBell                      ## -- Begin function soundBell
	.p2align	4, 0x90
_soundBell:                             ## @soundBell
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	$1, 24(%rax)
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
.subsections_via_symbols
