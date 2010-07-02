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

/* initialised in kmain() context with initial ebp value */
unsigned int	kpanic_kmain_ebp = 0;

/* frame pushed on stack after each function call */
struct frame_s
{
  void *	prev;	/* pointer to previous called frame */
  void *	ret;	/* return address of the frame */
} __attribute__((packed));

/* used not to mess up register while calling functions */
struct reg_s
{
  int		r_eax;
  int		r_ebx;
  int		r_ecx;
  int		r_edx;
  int		r_esi;
  int		r_edi;
  int		r_ebp;
  int		r_esp;
};

/* print a trace of latest called c-function */
static void		backtrace(void)
{
  struct frame_s *	current;
  int			i;

  kprintf("#\tbacktrace\n");

  /* mov DWORD [current], ebp */
  __asm__("movl %%ebp, %0"
	  : "=r" (current));

  /* we stop tracing when arriving to kmain() or when more than 5 functions */
  for (i = 0; (unsigned int) current != kpanic_kmain_ebp && i < 5; ++i)
    {
      kprintf("#\t\t(%d) 0x%p\n", i, current->ret);
      current = current->prev;
    }

  kprintf("#\t/backtrace\n");
}

/* print content of a saved register */
#define	PRINT_REG(reg, dst) kprintf("#\t\t> %s: 0x%p [%b]\n", reg, dst, dst);

static void		tracereg(struct reg_s * regs)
{
  kprintf("#\tregisters\n");
  PRINT_REG("eax", regs->r_eax);
  PRINT_REG("ebx", regs->r_ebx);
  PRINT_REG("ecx", regs->r_ecx);
  PRINT_REG("edx", regs->r_edx);
  PRINT_REG("esi", regs->r_esi);
  PRINT_REG("edi", regs->r_edi); 
  PRINT_REG("ebp", regs->r_ebp);
  PRINT_REG("esp", regs->r_esp);
  kprintf("#\t/registers\n");
}

/* save a register */
#define	SAVE_REG(reg, dst)  __asm__("movl %%"reg",%0" : "=r" (dst));

void		kpanic(const char * message)
{
  struct reg_s		regs;

  /* done before any operation that would change them */
  SAVE_REG("eax", regs.r_eax);
  SAVE_REG("ebx", regs.r_ebx);
  SAVE_REG("ecx", regs.r_ecx);
  SAVE_REG("edx", regs.r_edx);
  SAVE_REG("esi", regs.r_esi);
  SAVE_REG("edi", regs.r_edi);
  /* probably useless, as modified by the call to kpanic */
  SAVE_REG("ebp", regs.r_ebp);
  SAVE_REG("esp", regs.r_esp);

  kprintf("#\tKernel panic: %s\n", message);
  tracereg(&regs);
  backtrace();

  /* mxs: Not sure if this is good, as any interupt might occur
   * I think we need a flag or something to disable handling
   * of interrupts.
   */
  for (;;);
}
