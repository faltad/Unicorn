/*
** kmain.c for os in /home/projets/os/src
** 
** Made by Faltad
** Login   <faltad@gmail.com>
** 
** Started on  Tue Jun 29 00:06:12 2010 Faltad
** Last update Sun Jul  4 21:47:08 2010 Faltad
*/

#include "multiboot.h"
#include "screen.h"
#include "libc.h"
#include "sys.h"

/* temporary code to test kpanic() */
static void	crash(void)
{
  static int	i = 0;

  ++i;
  if (i < 5)
    crash();
  else
    kpanic("crash");
}

void		kmain(unsigned long magic, struct mb_partial_info *mbd)
{
  if (magic == MULTI_BOOT_MAGIC_CHECK)
    {
      /* must be called in kmain, to have a correct EBP value */
      KPANIC_INIT();
      idt_setup();
      clear_screen();
      
      kprintf("Test from Unicorn !\nLow mem : %d high mem : %d\n",
	      mbd->low_mem, mbd->high_mem);
      init_gdt();
      kprintf("Test : %20#x %0#b %2b %d\n", 10, 10, 10, 0);
      crash();
    }
}
