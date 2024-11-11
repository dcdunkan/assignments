.data
string: .string "Laptop"

.text
la a1 string

forward_loop:
    lb t1 0(a1) # Load the current character
    addi a1 a1 1
    bnez t1 forward_loop
    addi a1 a1 -1

backward_loop:
    addi a1 a1 -1
    lb t1 0(a1) # Load the character

# Print the character
mv a0 t1
li a7 11
ecall
bnez t1 backward_loop
