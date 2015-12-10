    .data

msg: .asciiz "Hola mundo!"

    .text

main:

    li $s1, -5

    li $v0, 1
    la $a0, ($s1)
    syscall


    li $v0, 4
    la $a0, msg
    syscall

    li $v0, 10
    syscall