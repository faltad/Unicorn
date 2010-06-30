## Makefile.inc for os in /home/projets/os/img
## 
## Made by Faltad
## Login   <faltad@gmail.com>
## 
## Started on  Tue Jun 29 00:22:40 2010 Faltad
## Last update Wed Jun 30 23:23:58 2010 Faltad
##

CC		=	gcc
LD		=	ld
AS		=	nasm
MAKE		=	make -C
RM		=	rm -rf

KERNEL		=	unicorn-kernel.bin
GRUB_IMG	=	unicorn.img

SRC_DIR		=	src/
IMG_DIR		=	img/
INCLUDE_PATH	=	$(TOP_DIR)/include/

ASFLAGS		=	-f elf32
CFLAGS		=	-W -Wall -I $(INCLUDE_PATH) -Wshadow -m32
LDFLAGS		=	-m elf_i386

OBJ		=	$(SRC:.c=.o)
