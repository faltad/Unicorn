#include "sys.h"
#include "libc.h"

/* this code has not fully been tested yet :( */

/* structure of one idt entry */
struct			idt_entry_s
{
  unsigned short	base_low;
  unsigned short	sel;
  unsigned char		zero;		/* unused? */
  unsigned char		flags;
  unsigned short	base_high;
} __attribute__((packed));

/* base structure to tell the processor where to
   find our idt entries */
struct			idt_ptr_s
{
  unsigned short	limit;
  unsigned int          base;
} __attribute__((packed));

static struct idt_entry_s	idt_array[0xff];
static struct idt_ptr_s		idt_p;

/* initialize an idt entry */
void		idt_set_gate(unsigned char idx, unsigned long base, 
			     unsigned short sel, unsigned char flags)
{
  idt_array[idx].base_low = (base & 0xFFFF);
  idt_array[idx].base_high = (base >> 16) & 0xFFFF;
  idt_array[idx].flags = flags;
  idt_array[idx].sel = sel;
}

/* initialize idt's to 0 and lidt them */
void		idt_setup(void)
{
  idt_p.limit = sizeof(idt_array);
  idt_p.base = (unsigned int) & idt_array;
  memset(&idt_array, 0, sizeof(idt_array));
  __asm__("lidt %0" :: "m" (idt_p));
}
