##
## Makefile for unicorn in /home/faltad/projets/Unicorn/src
## 
## Made by Faltad
## Login   <faltad@gmail.com>
## 
## Started on  Tue Jun 29 22:40:12 2010 Faltad
## Last update Wed Jun 30 23:24:25 2010 Faltad
##

TOP_DIR	=	..

SRC	=	kmain.c\
		screen.c\
		lib.c\
		kprintf.c\
		kpanic.c\
		idt.c

include		$(TOP_DIR)/Makefile.inc

all: $(OBJ)
	$(AS) $(ASFLAGS) boot.s
	$(LD) $(LDFLAGS) -T link.ld boot.o $(OBJ) -o $(KERNEL)
	cp $(KERNEL) $(TOP_DIR)
clean:
	$(RM) *.o

re: clean all
