/*
 * A kernel panic with a backtrace of what was called
 * before beeing raised.
 *
 * Use assembly contexts to retrace the execution list
 * using prolog/epilogs.
 *
 * Also dump registers before beeing used.
 */

#include "libc.h"
#include "multiboot.h"
#include "screen.h"

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
      kprintf("#\t\t(%d) %X\n", i, current->ret);
      current = current->prev;
    }

  kprintf("#\t/backtrace\n");
}

static void		tracereg(registers_t *regs)
{
  kprintf("#\tregisters\n");
  PRINT_REG("eax", regs->eax);
  PRINT_REG("ebx", regs->ebx);
  PRINT_REG("ecx", regs->ecx);
  PRINT_REG("edx", regs->edx);
  PRINT_REG("esi", regs->esi);
  PRINT_REG("edi", regs->edi); 
  PRINT_REG("ebp", regs->ebp);
  PRINT_REG("esp", regs->esp);
  kprintf("#\t/registers\n");
}

void		kpanic(const char * message, registers_t regs)
{

  kprintf("#\tKernel panic: %s\n", message);
  tracereg(&regs);
  backtrace();
}
