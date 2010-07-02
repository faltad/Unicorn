/*
** kmain.c for os in /home/projets/os/src
** 
** Made by Faltad
** Login   <faltad@gmail.com>
** 
** Started on  Tue Jun 29 00:06:12 2010 Faltad
** Last update Wed Jun 30 23:27:28 2010 Faltad
*/

#include "multiboot.h"
#include "screen.h"
#include "libc.h"

/* temporary code to test kpanic() */
static void	crash(void)
{
  static int	i = 0;

  ++i;
  if (i < 10)
    crash();
  else
    kpanic("crash");
}

void	kmain(unsigned long magic, struct mb_partial_info *mbd)
{
  if (magic == MULTI_BOOT_MAGIC_CHECK)
    {      
      clear_screen();
      kprintf("Test from Unicorn !\nLow mem : %d high mem : %d\n",
	      mbd->low_mem, mbd->high_mem);
      kprintf("Test : %20#x %0#b %2b %d\n", 10, 10, 10, 0);

      crash();
    }
}
