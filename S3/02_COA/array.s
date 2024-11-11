.data
arr: .word 5 10 3 2 6 1 8 4
len: .word 8
msg: .string "Sum of array: "

.text
la a1 arr
lw a2 len
addi x5 zero 0

loop:
    lw x6 0(a1)
    add x5 x5 x6
    addi a2 a2 -1
    addi a1 a1 4
    bne a2 zero loop
    
end:
    la a0, msg
    li a7, 4
    ecall
    
    mv a0, x5
    li a7, 1
    ecall
    
    nop