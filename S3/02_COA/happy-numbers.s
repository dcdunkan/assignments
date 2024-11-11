.data
num: .word 17
strsuccess: .string " is a Happy Number"
strfail: .string " is Not a Happy Number"

.text
    lw x7 num
    li x2 10
    li x8 1
    li x9 9
loop:
    add x1 x7 x0
    sub x7 x7 x7
  
    split:
        div x3 x1 x2
        mul x4 x2 x3
        sub x5 x1 x4
        
        mul x6 x5 x5
        add x7 x7 x6
        
        div x1 x4 x2 
        bgt x1 x0 split
     
    bgt x7 x9 loop
    

    lw a0 num
    li a7 1
    ecall
    
    beq x7 x8 success
    bne x7 x8 fail
        
success:
    la a0 strsuccess
    li a7 4
    ecall
    jal end
    
fail:
    la a0 strfail
    li a7 4
    ecall
end:
    nop