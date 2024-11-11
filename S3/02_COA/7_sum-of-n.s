.data
n: .word 10
msg: .string "Sum of natural numbers upto n: "

.text
lw a2 n
li x1 1
li x2 0

la a0 msg
li a7 4
ecall

loop:
    add x2 x2 x1
    addi x1 x1 1
    
    addi a2 a2 -1
    bne a2 x0 loop
    
end:
    mv a0 x2
    li a7 1
    ecall
    
    nop
