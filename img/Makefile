##
## Makefile for os in /home/projets/os/img
## 
## Made by Faltad
## Login   <faltad@gmail.com>
## 
## Started on  Tue Jun 29 00:20:34 2010 Faltad
## Last update Wed Jun 30 23:24:14 2010 Faltad
##

TOP_DIR	=	..

include ../Makefile.inc

all:
	cat stage1 stage2 pad $(TOP_DIR)/$(KERNEL) > $(TOP_DIR)/$(GRUB_IMG)

clean:
	$(RM) ../$(GRUB_IMG)

re: clean all