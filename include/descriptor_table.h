/*
** descriptor_table.h for Unicorn in /home/faltad/projets/Unicorn/include
** 
** Made by Faltad
** Login   <faltad@gmail.com>
** 
** Started on  Thu Jul  1 22:37:43 2010 Faltad
** Last update Fri Jul  2 22:39:14 2010 Faltad
*/


#ifndef __DESCRIPTOR_TABLE_H_
#define __DESCRIPTOR_TABLE_H_

#include "types.h"

typedef struct			s_gdt_entry
{
   ushort limit_low;
   ushort base_low;
   uchar  base_middle;
   uchar  access;
   uchar  granularity;
   uchar  base_high;
} __attribute__ ((packed))	t_gdt_entry;

typedef struct			s_gdtptr
{
   ushort			limit;
   uint				base;
} __attribute__ ((packed))	t_gdtptr;


#endif
