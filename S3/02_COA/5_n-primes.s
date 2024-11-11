.data
msg: .string "Prime number: "
space: .string " "
newline: .string "\n"
num: .word 10

.text
li a1 2
li a2 10
lw a6 num

la a0 msg
li a7 4
ecall

loop:
    li t1 2
    
divisible:
    bge t1 a1 print_prime
    rem t4 a1 t1
    beqz t4 next_number
    addi t1 t1 1
    j divisible
    
print_prime:
    mv a0 a1
    li a7 1
    ecall
    la a0 space
    li a7 4
    ecall
    addi a2, a2, -1
    j next_number
    
next_number:
    addi a1 a1 1
    bgtz a2 loop
