/*
** kmain.c for os in /home/projets/os/src
** 
** Made by Faltad
** Login   <faltad@gmail.com>
** 
** Started on  Tue Jun 29 00:06:12 2010 Faltad
** Last update Wed Jun 30 11:15:09 2010 Faltad
*/

#include "multiboot.h"
#include "screen.h"

void	kmain(unsigned long magic, struct mb_partial_info *mbd)
{
   if (magic == MULTI_BOOT_MAGIC_CHECK)
   {
      clear_screen();
      kputs("Test from Unicorn !\n");
      kputs("low mem : ");
      putnbr(mbd->low_mem);
      kputs(" high mem : ");
      putnbr(mbd->high_mem);
      kputs("\n");
   }
}
