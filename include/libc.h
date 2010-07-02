/*
** libc.h for  in /home/faltad/projets/Unicorn/src
** 
** Made by Faltad
** Login   <faltad@gmail.com>
** 
** Started on  Wed Jun 30 00:51:39 2010 Faltad
** Last update Wed Jun 30 23:11:17 2010 Faltad
*/

#ifndef __LIBC_H_
#define __LIBC_H_

#define IS_NUM(x) (x >= '0' && x <= '9')

void	*memset(void *s, int c, int n);
void	*memcpy(char *dest, const char *src, int n);
int	strlen(char *s);
void	putnbr_base(int nb, char *base);
void	putnbr(int nb);

/* kprintf */

#define FLAG_ALTERNATE	0x1
int		kprintf(char *str, ...);

/* save the initial EBP position to be able to stop tracing function stack */
#define	KPANIC_INIT()					\
  extern unsigned int	kpanic_kmain_ebp;		\
  __asm__("movl %%ebp, %0" : "=r" (kpanic_kmain_ebp));

/* kpanic */
void		kpanic(const char *);

typedef __builtin_va_list va_list;

#define va_start(ap, start) __builtin_va_start((ap), (start))
#define va_arg(ap, type) __builtin_va_arg((ap), type)
#define va_end(ap) __builtin_va_end((ap));

#endif
