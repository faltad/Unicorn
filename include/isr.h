#ifndef __ISR_H_
#define __ISR_H_

/* used not to mess up register while calling functions */
typedef struct reg_s reg_s;
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

void	isr_handler(reg_s regs);

#endif
