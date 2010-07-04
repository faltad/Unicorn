
extern isr_handler

;;; This macro registers a new ISR without error handling
;;; We push 0x0 for a default error value
        
%macro isr_noerr 1

global isr_%1
        
isr_%1:
        
	cli
        push BYTE 0x0
        push BYTE %1

        jmp isr_jumper

%endmacro

	
;;; This macro registers a new ISR with error handling

%macro isr_err 1

global isr_%1

isr_%1:
	
	cli
	push BYTE %1
	
	jump isr_jumper

%endmacro

	
isr_noerr 0 ; division by zero
isr_noerr 1 ; debug exceptions
isr_noerr 2 ; intel reserved (non maskable interupt)
isr_noerr 3 ; breakpoint
isr_noerr 4 ; overflow
isr_noerr 5 ; bounds check
isr_noerr 6 ; invalid opcode
isr_noerr 7 ; coprocessor not available
isr_err 8 ; double fault
isr_noerr 9 ; coprocessor segment overrun
isr_err 10 ; invalid tss
isr_err 11 ; segment not present
isr_err 12 ; stack exception
isr_err 13 ; triple fault

global isr_14 ; page fault
        
isr_14:

        push BYTE 14
        mov eax, cr2
        push eax ; Address that faulted
        jmp isr_jumper
        
isr_noerr 15 ; intel reserved
isr_noerr 16 ; corprocessor error
isr_noerr 17 ; alignement check exception
isr_noerr 18 ; machine check exception

;; 19-31 reserved

isr_jumper:
        
        pusha
        push ds
        push es
        push fs
        push gs
        
        mov ax, 0x10
        mov ds, ax
        mov es, ax
        mov fs, ax
        mov gs, ax
        mov eax, esp
        push eax
        mov eax, isr_handler
        call eax
        pop eax

        pop gs
        pop fs
        pop es
        pop ds
        popa
        add esp, 8 ; error + id previously pop
        iret
