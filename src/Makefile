##
## Makefile for unicorn in /home/faltad/projets/Unicorn/src
## 
## Made by Faltad
## Login   <faltad@gmail.com>
## 
## Started on  Tue Jun 29 22:40:12 2010 Faltad
## Last update Wed Jun 30 00:51:21 2010 Faltad
##

TOP_DIR	=	..

SRC	=	kmain.c\
		screen.c\
		lib.c

include		$(TOP_DIR)/Makefile.inc

all: $(OBJ)
	$(AS) -f elf boot.s
	$(LD) -T link.ld boot.o $(OBJ) -o $(KERNEL)
	cp $(KERNEL) $(TOP_DIR)
clean:
	rm -rf *.o

re: clean all