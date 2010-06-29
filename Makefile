##
## Makefile for os in /home/faltad/projets/os
## 
## Made by Faltad
## Login   <faltad@gmail.com>
## 
## Started on  Tue Jun 29 21:56:34 2010 Faltad
## Last update Tue Jun 29 23:26:44 2010 Faltad
##

TOP_DIR		=	.

include			$(TOP_DIR)/Makefile.inc

all:
	$(MAKE) $(SRC_DIR)
	$(MAKE) $(IMG_DIR)

clean:
	$(MAKE) $(SRC_DIR) clean
	$(MAKE) $(IMG_DIR) clean

re: clean all

run:
	@echo "------"
	@echo "For grub : type :"
	@echo ""
	@echo -n "kernel 200+"
	@echo `cat $(KERNEL) | wc -c`/512 | bc
	@echo "boot"
	@echo "-----"
	qemu -fda $(GRUB_IMG)

