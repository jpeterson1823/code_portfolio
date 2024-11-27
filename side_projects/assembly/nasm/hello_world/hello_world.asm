section .data
    hello:      db "Hello world!", 10   ; "Hello world!" plus a linefeed
    helloLen:   equ $-hello             ; lenth of hello world str

section .text
    global _start

_start:
    mov eax,4           ; system call for write (sys_write)
    mov ebx,1           ; File descriptor 1 - standard output
    mov ecx,hello       ; Put the offset of hello in ecx
    mov edx,helloLen    ; helloLen is const, no need to evaluate

    int 80h             ; call kernel

    mov eax,1           ; system call for exit
    mov ebx, 0          ; exit with return code 0 (no error)
    int 80h
