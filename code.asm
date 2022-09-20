global main
extern printf, scanf

section .text
main:
    push rbp           
    mov  rbp, rsp 
    sub rsp, 16   

    xor eax,eax
    lea rdi,[inpn]
    call printf

    xor eax,eax
    lea rdi,[integer]
    lea rsi,[x]
    call scanf

    xor eax,eax
    lea rdi,[outn]
    lea rsi,[x]
    call printf

    xor eax,eax
    lea rdi,[inps]
    call printf

    xor eax,eax
    lea rdi,[string]
    lea rsi,[str]
    call scanf

    xor eax,eax
    lea rdi,[outs]
    lea rsi,[str]
    call printf

    add rsp, 16 
    leave               
    ret

section .data
    inpn: db "Enter number: ",0
    outn: db "the number is: %d ",0
    outs: db "the string is: %s ",0
    inps: db "Enter String: ",0
    integer: db "%d",0
    string: db "%s",0
    str times 100 db 0

section .bss
    x resb 4