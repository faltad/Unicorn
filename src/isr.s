BITS			32
	
section .text
	
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
	
	jmp isr_jumper

%endmacro

isr_noerr 0 ; division by zero				FAULT
isr_noerr 1 ; debug exceptions				FAULT/TRAP
isr_noerr 2 ; intel reserved (non maskable interupt)	INTERUPT
isr_noerr 3 ; breakpoint				TRAP
isr_noerr 4 ; overflow					TRAP
isr_noerr 5 ; BOUND range exceeded			FAULT
isr_noerr 6 ; invalid opcode				FAULT
isr_noerr 7 ; coprocessor not available			FAULT
isr_err 8 ; double fault				ABORT
isr_noerr 9 ; coprocessor segment overrun		FAULT
isr_err 10 ; invalid tss				FAULT
isr_err 11 ; segment not present			FAULT
isr_err 12 ; stack exception				FAULT
isr_err 13 ; segfault					FAULT

global isr_14 ; page fault				FAULT
        
isr_14:

        push BYTE 14
        mov eax, cr2
        push eax ; Address that faulted
        jmp isr_jumper
        
isr_noerr 15 ; intel reserved
isr_noerr 16 ; corprocessor error			FAULT
isr_noerr 17 ; alignement check exception		FAULT
isr_noerr 18 ; machine check exception			ABORT
isr_noerr 19 ; SIMD floating-point exception		FAULT

;; 20-31 reserved					INTERUPT
;; 32-255 maskable interrupts (syscall)

isr_jumper:

        pushad

	mov ax, ds
	push eax

	mov ax, 0x10
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax

	call isr_handler

	pop eax

	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax

	popad
	add esp, 8
	sti			
	iret
	
