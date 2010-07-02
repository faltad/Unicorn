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

  kprintf("---------- backtrace\n");

  /* mov DWORD [current], ebp */
  __asm__("movl %%ebp, %0"
	  : "=r" (current));

  /* need something better to stop tracing */
  for (i = 0; i < 10; ++i)
    {
      kprintf("(%d) 0x%p\n", i, current->ret);
      current = current->prev;
    }

  kprintf("---------- /backtrace\n");
}

void		kpanic(const char * message)
{
  kprintf("Kernel panic: %s\n", message);
  backtrace();
  /* tracereg(); @todo */
  
  /* mxs: Not sure if this is good, as any interupt might occur
   * I think we need a flag or something to disable handling
   * of interrupts.
   */
  for (;;);
}
