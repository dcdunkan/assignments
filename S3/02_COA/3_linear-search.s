.data
n: .word 7
arr: .word 10 20 30 40 50 60 70
key: .word 50
msg_found: .string "Found the number at index: "
msg_not_found: .string "Couldn't find the number"

.text
la a1 arr
lw a2 key
lw a3 n

mv x1 a3

loop:
    lw a4 0(a1)
    beq a4 a2 found
    addi a1 a1 4
    
    addi x1 x1 -1
    bnez x1 loop

not_found:
    la a0 msg_not_found
    li a7 4
    ecall
    j exit

found:
    sub x2 a3 x1
    
    la a0 msg_found
    li a7 4
    ecall
    
    mv a0 x2
    li a7 1
    ecall

exit:
    li a7 10
    ecall
