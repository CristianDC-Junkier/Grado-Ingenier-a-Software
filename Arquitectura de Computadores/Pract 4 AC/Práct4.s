	.data 

A:      .word 1, 2, 3 ,4 ,5 ,6 ,7 ,8 ,9
B:      .word 2

	.text 
main:
	add r1,r0,r0
	addi r3,r0,A
	lw r5,B
loop:
	addi r2,r0,#9
	lw r4,0(r3)

	mult r4,r4,r5

	sw 0(r3),r4

	addi r1,r1,#1
	subi r2,r1,#9
	addi r3,r3,#4
	bnez r2,loop
	nop
	trap 6
