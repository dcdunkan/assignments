.data
n: .word 5
nums: .word 5 4 3 2 1
space: .string " "

.text
lw a1 n
lw a2 n
addi a2 a2 -1
la a4 nums

li x6 0

outloop:
    bge x6 a1 end
    li x2 0
    la a3 nums
    
    inloop:
        bge x2 a2 outnext
        lw x4 4(a3)
        lw x3 0(a3)
        bge x3 x4 swap
        jal innext

    swap:
        sw x4 0(a3)
        sw x3 4(a3)

    innext:
        addi a3 a3 4
        addi x2 x2 1
        j inloop

outnext:
    addi x6 x6 1
    j outloop

end:
    lw x5 n
    printloop:
        lw x7 0(a4)
        mv a0 x7
        li a7 1
        ecall

        la a0 space
        li a7 4
        ecall
    
        addi a4 a4 4 
        addi x5 x5 -1   
        bgt x5 x0 printloop

        li a7 10
        ecall
