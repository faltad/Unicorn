##
## Makefile for os in /home/projets/os/img
## 
## Made by Faltad
## Login   <faltad@gmail.com>
## 
## Started on  Tue Jun 29 00:20:34 2010 Faltad
## Last update Tue Jun 29 21:44:36 2010 Faltad
##

include ../Makefile.inc

all:
	cat stage1 stage2 pad ../src/$(KERNEL) > ../$(GRUB_IMG)

clean:
	rm ../$(GRUB_IMG)

re: clean all