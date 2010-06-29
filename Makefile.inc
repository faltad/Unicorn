## Makefile.inc for os in /home/projets/os/img
## 
## Made by Faltad
## Login   <faltad@gmail.com>
## 
## Started on  Tue Jun 29 00:22:40 2010 Faltad
## Last update Tue Jun 29 23:15:31 2010 Faltad
##

CC		=	gcc
AS		=	nasm
MAKE		=	make -C

KERNEL		=	unicorn-kernel.bin
GRUB_IMG	=	unicorn.img

SRC_DIR		=	src/
IMG_DIR		=	img/
INCLUDE_PATH	=	$(TOP_DIR)/include/

CFLAGS		=	-W -Wall -I $(INCLUDE_PATH) -Wshadow

OBJ		=	$(SRC:.c=.o)
