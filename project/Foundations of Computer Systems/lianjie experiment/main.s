	.file	"main.c"
# GNU C17 (Ubuntu 11.4.0-1ubuntu1~22.04) version 11.4.0 (x86_64-linux-gnu)
#	compiled by GNU C version 11.4.0, GMP version 6.2.1, MPFR version 4.1.0, MPC version 1.2.1, isl version isl-0.24-GMP

# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed: -mtune=generic -march=x86-64 -fasynchronous-unwind-tables -fstack-protector-strong -fstack-clash-protection -fcf-protection
	.text
	.globl	init_gv1
	.data
	.align 4
	.type	init_gv1, @object
	.size	init_gv1, 4
init_gv1:
	.long	10
	.globl	uninit_gv2
	.bss
	.align 4
	.type	uninit_gv2, @object
	.size	uninit_gv2, 4
uninit_gv2:
	.zero	4
	.globl	init_gstr1
	.data
	.align 8
	.type	init_gstr1, @object
	.size	init_gstr1, 12
init_gstr1:
	.string	"U202490042"
	.zero	1
	.globl	uninit_gstr2
	.bss
	.align 8
	.type	uninit_gstr2, @object
	.size	uninit_gstr2, 12
uninit_gstr2:
	.zero	12
	.globl	init_garr1
	.data
	.align 8
	.type	init_garr1, @object
	.size	init_garr1, 12
init_garr1:
	.long	11
	.long	12
	.long	13
	.globl	uninit_garr2
	.bss
	.align 8
	.type	uninit_garr2, @object
	.size	uninit_garr2, 12
uninit_garr2:
	.zero	12
	.globl	init_gp1
	.section	.data.rel.local,"aw"
	.align 8
	.type	init_gp1, @object
	.size	init_gp1, 8
init_gp1:
	.quad	init_gv1
	.globl	init_gp2
	.align 8
	.type	init_gp2, @object
	.size	init_gp2, 8
init_gp2:
	.quad	uninit_gv2
	.globl	uninit_gp2
	.bss
	.align 8
	.type	uninit_gp2, @object
	.size	uninit_gp2, 8
uninit_gp2:
	.zero	8
	.globl	init_gfp1
	.section	.data.rel,"aw"
	.align 8
	.type	init_gfp1, @object
	.size	init_gfp1, 8
init_gfp1:
	.quad	fadd
	.globl	uninit_gfp2
	.bss
	.align 8
	.type	uninit_gfp2, @object
	.size	uninit_gfp2, 8
uninit_gfp2:
	.zero	8
	.globl	gv
	.data
	.align 4
	.type	gv, @object
	.size	gv, 4
gv:
	.long	6
	.section	.rodata
	.align 8
.LC0:
	.string	"auto x = %d , static count =%d\n"
	.text
	.globl	fcount
	.type	fcount, @function
fcount:
.LFB0:
	.cfi_startproc
	endbr64	
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
# main.c:28:     int x = 0;
	movl	$0, -4(%rbp)	#, x
# main.c:30:     x++;
	addl	$1, -4(%rbp)	#, x
# main.c:31:     count++;
	movl	count.0(%rip), %eax	# count, count.0_1
	addl	$1, %eax	#, _2
	movl	%eax, count.0(%rip)	# _2, count
# main.c:32:     printf("auto x = %d , static count =%d\n", x, count);
	movl	count.0(%rip), %edx	# count, count.1_3
	movl	-4(%rbp), %eax	# x, tmp85
	movl	%eax, %esi	# tmp85,
	leaq	.LC0(%rip), %rax	#, tmp86
	movq	%rax, %rdi	# tmp86,
	movl	$0, %eax	#,
	call	printf@PLT	#
# main.c:33: }
	nop	
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE0:
	.size	fcount, .-fcount
	.type	fsub, @function
fsub:
.LFB1:
	.cfi_startproc
	endbr64	
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$80, %rsp	#,
	movl	%edi, -68(%rbp)	# x, x
	movl	%esi, -72(%rbp)	# y, y
# main.c:36: {
	movq	%fs:40, %rax	# MEM[(<address-space-1> long unsigned int *)40B], tmp93
	movq	%rax, -8(%rbp)	# tmp93, D.2575
	xorl	%eax, %eax	# tmp93
# main.c:38:     char fmt[] = "static fsub : uninit_gv2 = %d \n";
	movabsq	$7358991095698650227, %rax	#, tmp96
	movabsq	$7959303350470735219, %rdx	#,
	movq	%rax, -48(%rbp)	# tmp96, fmt
	movq	%rdx, -40(%rbp)	#, fmt
	movabsq	$3636207408820874857, %rax	#, tmp97
	movabsq	$2850364258794784, %rdx	#,
	movq	%rax, -32(%rbp)	# tmp97, fmt
	movq	%rdx, -24(%rbp)	#, fmt
# main.c:39:     uninit_gp2 = &uninit_gv2;
	leaq	uninit_gv2(%rip), %rax	#, tmp86
	movq	%rax, uninit_gp2(%rip)	# tmp86, uninit_gp2
# main.c:40:     *uninit_gp2 = 12;
	movq	uninit_gp2(%rip), %rax	# uninit_gp2, uninit_gp2.2_1
# main.c:40:     *uninit_gp2 = 12;
	movl	$12, (%rax)	#, *uninit_gp2.2_1
# main.c:41:     printf(fmt, uninit_gv2);
	movl	uninit_gv2(%rip), %edx	# uninit_gv2, uninit_gv2.3_2
	leaq	-48(%rbp), %rax	#, tmp87
	movl	%edx, %esi	# uninit_gv2.3_2,
	movq	%rax, %rdi	# tmp87,
	movl	$0, %eax	#,
	call	printf@PLT	#
# main.c:42:     result = x - y;
	movl	-68(%rbp), %eax	# x, tmp91
	subl	-72(%rbp), %eax	# y, tmp90
	movl	%eax, -52(%rbp)	# tmp90, result
# main.c:43:     return result;
	movl	-52(%rbp), %eax	# result, _11
# main.c:44: }
	movq	-8(%rbp), %rdx	# D.2575, tmp94
	subq	%fs:40, %rdx	# MEM[(<address-space-1> long unsigned int *)40B], tmp94
	je	.L4	#,
	call	__stack_chk_fail@PLT	#
.L4:
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE1:
	.size	fsub, .-fsub
	.section	.rodata
.LC1:
	.string	"display init_gstr1 : %s \n"
.LC2:
	.string	"sum = %d \n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	endbr64	
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
# main.c:48:     check_gcc_condition(init_gstr1); // 检查学号与条件编译是否一致
	leaq	init_gstr1(%rip), %rax	#, tmp87
	movq	%rax, %rdi	# tmp87,
	call	check_gcc_condition@PLT	#
# main.c:49:     fcount();
	movl	$0, %eax	#,
	call	fcount	#
# main.c:50:     fcount();
	movl	$0, %eax	#,
	call	fcount	#
# main.c:51:     __asm__ __volatile__(".rept 2 \n nop \n .endr \n"); // 改写源程序，将 5 换成学号的最后1位
#APP
# 51 "main.c" 1
	.rept 2 
 nop 
 .endr 

# 0 "" 2
# main.c:53:     int lv1 = 15;
#NO_APP
	movl	$15, -12(%rbp)	#, lv1
# main.c:54:     int lv2 = 17;
	movl	$17, -8(%rbp)	#, lv2
# main.c:55:     int sum = 0;
	movl	$0, -4(%rbp)	#, sum
# main.c:56:     sum = lv1 + lv2;
	movl	-12(%rbp), %edx	# lv1, tmp92
	movl	-8(%rbp), %eax	# lv2, tmp93
	addl	%edx, %eax	# tmp92, tmp91
	movl	%eax, -4(%rbp)	# tmp91, sum
# main.c:57:     init_gv1 = 20;
	movl	$20, init_gv1(%rip)	#, init_gv1
# main.c:58:     uninit_gv2 = init_gv1;
	movl	init_gv1(%rip), %eax	# init_gv1, init_gv1.4_1
	movl	%eax, uninit_gv2(%rip)	# init_gv1.4_1, uninit_gv2
# main.c:59:     strcpy(uninit_gstr2, "MaJunHao"); // 请换成自己的姓名拼音
	movabsq	$8025775650202345805, %rax	#, tmp104
	movq	%rax, uninit_gstr2(%rip)	# tmp104, MEM <char[1:9]> [(void *)&uninit_gstr2]
	movb	$0, 8+uninit_gstr2(%rip)	#, MEM <char[1:9]> [(void *)&uninit_gstr2]
# main.c:61:     extern_int = 21;
	movl	$21, extern_int(%rip)	#, extern_int
# main.c:62:     printf("display init_gstr1 : %s \n", init_gstr1);
	leaq	init_gstr1(%rip), %rax	#, tmp94
	movq	%rax, %rsi	# tmp94,
	leaq	.LC1(%rip), %rax	#, tmp95
	movq	%rax, %rdi	# tmp95,
	movl	$0, %eax	#,
	call	printf@PLT	#
# main.c:63:     sum = fadd(init_gv1, lv1);
	movl	init_gv1(%rip), %eax	# init_gv1, init_gv1.5_2
	movl	-12(%rbp), %edx	# lv1, tmp96
	movl	%edx, %esi	# tmp96,
	movl	%eax, %edi	# init_gv1.5_2,
	call	fadd@PLT	#
	movl	%eax, -4(%rbp)	# tmp97, sum
# main.c:64:     sum = fsub(50, 30);
	movl	$30, %esi	#,
	movl	$50, %edi	#,
	call	fsub	#
	movl	%eax, -4(%rbp)	# tmp98, sum
# main.c:65:     sum = init_gfp1(50, 30);
	movq	init_gfp1(%rip), %rax	# init_gfp1, init_gfp1.6_3
	movl	$30, %esi	#,
	movl	$50, %edi	#,
	call	*%rax	# init_gfp1.6_3
	movl	%eax, -4(%rbp)	# tmp99, sum
# main.c:66:     printf("sum = %d \n", sum);
	movl	-4(%rbp), %eax	# sum, tmp100
	movl	%eax, %esi	# tmp100,
	leaq	.LC2(%rip), %rax	#, tmp101
	movq	%rax, %rdi	# tmp101,
	movl	$0, %eax	#,
	call	printf@PLT	#
# main.c:67:     return 0;
	movl	$0, %eax	#, _25
# main.c:68: }
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.local	count.0
	.comm	count.0,4,4
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
