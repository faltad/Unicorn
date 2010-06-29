/*
** kmain.c for os in /home/projets/os/src
** 
** Made by Faltad
** Login   <faltad@gmail.com>
** 
** Started on  Tue Jun 29 00:06:12 2010 Faltad
** Last update Wed Jun 30 00:55:37 2010 Faltad
*/

#include "multiboot.h"
#include "screen.h"

void	kmain(unsigned long magic, struct mb_partial_info *mbd)
{
   clear_screen();
   kputs("Test from Unicorn !");
}
