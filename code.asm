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
    lea rdi,[inps]
    call printf

    xor eax,eax
    lea rdi,[string]
    lea rsi,[stri]
    call scanf

    lea rdi,[outn]
    mov rsi,[x]
    xor eax,eax
    call printf
    
    xor eax,eax
    lea rdi,[outs]
    lea rsi,[stri]
    call printf

    add rsp, 16 
    leave               
    ret

section .data
    inpn: db "Enter number: ",0
    outn: db "the number is: %d ",10,0
    outs: db "the string is: %s ",10,0
    inps: db "Enter String: ",0
    integer: db "%d",0
    string: db "%s",0
    stri times 100 db 0

section .bss
    x resb 4
