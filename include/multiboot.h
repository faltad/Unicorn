/*
** multiboot.h for os in /home/projets/os/include
** 
** Made by Faltad
** Login   <faltad@gmail.com>
** 
** Started on  Tue Jun 29 00:10:10 2010 Faltad
** Last update Tue Jun 29 00:10:54 2010 Faltad
*/

/* Multiboot structure */

struct mb_partial_info
{
   unsigned long flags;
   unsigned long low_mem;
   unsigned long high_mem;
   unsigned long boot_device;
   unsigned long cmdline;
};
   
