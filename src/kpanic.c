/*
 * A kernel panic with a backtrace of what was called
 * before beeing raised.
 *
 * Use assembly contexts to retrace the execution list
 * which are stored in ebp.  
 */

#include "multiboot.h"
#include "screen.h"
#include "libc.h"

void kmain(unsigned long, struct mb_partial_info *);

/* frame pushed on stack after each function call */
struct frame_s
{
  void *	prev;	/* pointer to previous called frame */
  void *	ret;	/* return address of the frame */
} __attribute__((packed));

/* print a trace of latest called c-function */
static void	backtrace(void)
{
  struct frame_s *	current;
  int			i;

  kprintf("#\tbacktrace\n");

  /* mov DWORD [current], ebp */
  __asm__("movl %%ebp, %0"
	  : "=r" (current));

  /* need something better to stop tracing */
  for (i = 0; i < 5; ++i)
    {
      kprintf("#\t\t(%d) 0x%p\n", i, current->ret);
      current = current->prev;
    }

  kprintf("#\t/backtrace\n");
}

/* store register to dst and print its content */
#define	PRINT_REG(reg, dst) \
  __asm__("movl %%"reg",%0" : "=r" (dst));	\
  kprintf("#\t\t> %s: 0x%p\n", reg, dst);

/* trace several registers */
static void	tracereg(void)
{
  unsigned int	reg;

  kprintf("#\tregisters\n");
  PRINT_REG("eax", reg);
  PRINT_REG("ebx", reg);
  PRINT_REG("ecx", reg);
  PRINT_REG("edx", reg);
  PRINT_REG("esi", reg);
  PRINT_REG("edi", reg); 
  PRINT_REG("ebp", reg);
  PRINT_REG("esp", reg);
  kprintf("#\t/registers\n");
}

void		kpanic(const char * message)
{
  kprintf("#\tKernel panic: %s\n", message);
  tracereg();
  backtrace();

  /* mxs: Not sure if this is good, as any interupt might occur
   * I think we need a flag or something to disable handling
   * of interrupts.
   */
  for (;;);
}
