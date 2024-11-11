.data
str: .string "AxEe"
vowels: .string "AEIOU"

.text
la a1 str
la a2 vowels
mv x3 zero

loop:
    lb x1 0(a1)
    beqz x1 print_and_exit
    la a2 vowels
    
    inner_loop:
        lb x2 0(a2)
        beqz x2 continue_outer_loop
    
        li x8 96
        ble x1 x8 compare # If it's a small letter:
        addi x1 x1 -32 # Make it a upper case letter for calculation.
        
        compare:
            bne x1 x2 continue_inner_loop
            addi x3 x3 1
    
    continue_inner_loop:
        addi a2 a2 1
        j inner_loop
        
continue_outer_loop:
    addi a1 a1 1
    j loop

print_and_exit:
    mv a0 x3
    li a7 1
    ecall
