
;; This is the place where all begin
;; This code jump from Grub to the kernel

;; Multiboot header define
;; See http://www.gnu.org/software/grub/manual/multiboot/html_node/index.html
;; for more explanations

BITS			32

MULTI_ALIGN_MOD		equ 1<<0
MULTI_MEMINFO_MOD	equ 1<<1
MULTI_FLAG		equ MULTI_MEMINFO_MOD | MULTI_ALIGN_MOD
MULTI_MAGIC		equ 0x1BADB002
MULTI_CHECKSUM		equ -(MULTI_FLAG + MULTI_MAGIC)

global	kstart
extern	kmain

;; Kernel Stack size

STACKSIZE		equ 0x4000

section .text

	align	4
	dd	MULTI_MAGIC
	dd	MULTI_FLAG
	dd	MULTI_CHECKSUM
kstart:
	mov esp, kernel_stack + STACKSIZE
	push ebx
	push eax
	call kmain
	cli
	hlt

section .bss
	align	32
	
kernel_stack:
	
	resb 	STACKSIZE

	
