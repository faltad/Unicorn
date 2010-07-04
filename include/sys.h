/* a place for definitions related to system */

#ifndef __SYS_UNICORN__
#define __SYS_UNICORN__


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

/* structure of one idt entry */
struct			idt_entry_s
{
  ushort		base_low;
  ushort		sel;
  uchar			zero;		/* unused? */
  uchar			flags;
  ushort		base_high;
} __attribute__((packed));

/* base structure to tell the processor where to
   find our idt entries */
struct			idt_ptr_s
{
  ushort		limit;
  uint		        base;
} __attribute__((packed));

void		idt_setup(void);
void		init_gdt(void);

#endif /* __SYS_H__ */
