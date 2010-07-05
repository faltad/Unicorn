/* a place for definitions related to system */

#ifndef __SYS_UNICORN__
#define __SYS_UNICORN__

/* save a register */
#define	SAVE_REG(reg, dst)  __asm__("movl %%"reg",%0" : "=r" (dst))

/* print content of a saved register */
#define	PRINT_REG(reg, dst) kprintf("#\t\t> %s: %#x\n", reg, dst, dst)

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


/*
** registers save when an interruption occurs
*/
typedef struct registers registers_t;
struct			registers
{

  /*
  ** Data segment selector
  */
  uint			ds;

  /*
  ** Pushed by pushad.
  */
  uint			edi;
  uint			esi;
  uint			ebp;
  uint			esp;
  uint			ebx;
  uint			edx;
  uint			ecx;
  uint			eax;

  /*
  ** Interrupt number and error code (if applicable)
  */
  uint			int_no;
  uint			err_code;

  /*
  **Pushed by the processor automatically.
  */
  uint			eip;
  uint			cs;
  uint			eflags;
  uint			useresp;
  uint			ss;
} __attribute__((packed)); 

void	isr_handler(struct registers regs);

#endif /* __SYS_H__ */
