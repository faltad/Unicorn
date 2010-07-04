##
## Makefile for unicorn in /home/faltad/projets/Unicorn/src
## 
## Made by Faltad
## Login   <faltad@gmail.com>
## 
## Started on  Tue Jun 29 22:40:12 2010 Faltad
## Last update Sun Jul  4 21:55:10 2010 Faltad
##

TOP_DIR	=	..

SRC	=	kmain.c\
		screen.c\
		lib.c\
		kprintf.c\
		kpanic.c\
		isr.c\
		system.c

include		$(TOP_DIR)/Makefile.inc

all: $(OBJ)
	$(AS) $(ASFLAGS) boot.s
	$(AS) $(ASFLAGS) isr.s
	$(LD) $(LDFLAGS) -T link.ld boot.o isr.o $(OBJ) -o $(KERNEL)
	cp $(KERNEL) $(TOP_DIR)
clean:
	$(RM) *.o

re: clean all
