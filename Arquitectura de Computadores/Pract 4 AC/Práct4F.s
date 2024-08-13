	.data 

A:      .float 1.0, 2.0, 3.0 ,4.0 ,5.0 ,6.0 ,7.0 ,8.0 ,9.0
B:      .float 2

	.text 
main:
	add r1,r0,r0
	addi r3,r0,A
	lf f5,B
loop:
	addi r2,r0,#9
	lf f4,0(r3)

	multf f4,f4,f5

	sf 0(r3),f4

	addi r1,r1,#1
	subi r2,r1,#9
	addi r3,r3,#4
	bnez r2,loop
	nop
	trap 6
