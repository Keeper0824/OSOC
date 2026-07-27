	.file	"a.c"
	.option pic
	.text
	.align	1
	.globl	main
	.type	main, @function
main:
	addi	sp,sp,-32
	sd	ra,24(sp)
	sd	s0,16(sp)
	addi	s0,sp,32
	li	a5,10
	sw	a5,-32(s0)
	li	a5,20
	sw	a5,-28(s0)
	li	a0,40
	call	malloc@plt
	mv	a5,a0
	sd	a5,-24(s0)
	ld	a0,-24(s0)
	call	free@plt
	ld	a5,-24(s0)
	sw	zero,0(a5)
	li	a5,0
	mv	a0,a5
	ld	ra,24(sp)
	ld	s0,16(sp)
	addi	sp,sp,32
	jr	ra
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
