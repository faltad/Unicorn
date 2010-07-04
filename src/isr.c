
#include "isr.h"
#include "screen.h"
#include "libc.h"

void	isr_handler(reg_s regs)
{
  kputs("received interrupt\n");
  kprintf("eax %d", regs.r_eax);
}
