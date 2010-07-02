/*
** descriptor_table.h for Unicorn in /home/faltad/projets/Unicorn/include
** 
** Made by Faltad
** Login   <faltad@gmail.com>
** 
** Started on  Thu Jul  1 22:37:43 2010 Faltad
** Last update Fri Jul  2 21:55:35 2010 Faltad
*/


#ifndef __DESCRIPTOR_TABLE_H_
#define __DESCRIPTOR_TABLE_H_

#include "types.h"

typedef struct			s_gdt_entry
{
   ushort lim0_15;    
   ushort base0_15;
   uchar base16_23;
   uchar acces;
   uchar lim16_19 : 4;
   uchar other : 4;
   uchar base24_31;
} __attribute__ ((packed))	t_gdt_entry;

typedef struct			s_gdtptr
{
   ushort			limit;
   uint				base;
} __attribute__ ((packed))	t_gdtptr;

#define GDTADDR			0x0

#endif
