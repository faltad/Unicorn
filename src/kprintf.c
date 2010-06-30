/*
** kprintf.c for Unicorn in /home/faltad/projets/Unicorn/src
** 
** Made by Faltad
** Login   <faltad@gmail.com>
** 
** Started on  Wed Jun 30 21:06:44 2010 Faltad
** Last update Wed Jun 30 23:25:33 2010 Faltad
*/

#define IS_NUM(x) (x >= '0' && x <= '9')

#include "libc.h"
#include "screen.h"

static void	get_arg(char c, va_list *ap, int flag)
{
   if (c == '%')
      kputchar('%');
   else if (c == 'd')
      putnbr(va_arg(*ap, int));
   else if (c == 's')
      kputs(va_arg(*ap, char *));
   else if (c == 'x')
   {
      if (flag & FLAG_ALTERNATE)
	 kputs("0x");
      putnbr_base(va_arg(*ap, int), "0123456789abcdef");
   }
   else if (c == 'X')
   {
      if (flag & FLAG_ALTERNATE)
	 kputs("0x");
      putnbr_base(va_arg(*ap, int), "0123456789ABCDEF");
   }
   else if (c == 'b')
   {
      if (flag & FLAG_ALTERNATE)
	 kputs("0b");
      putnbr_base(va_arg(*ap, int), "01");
   }
   else if (c == 'p')
   {
      kputs("0b");
      putnbr_base(va_arg(*ap, int), "0123456789abcdef");
   }
}

static int	is_flag(char c, int *flag)
{
   if (c == '#')
      *flag |= FLAG_ALTERNATE;
   else
      return 0;
   return 1;
}

static int     	get_padding(int *i, char *s, int *flag)
{
   int		nb;

   nb = 0;
   while (IS_NUM(s[*i]) || is_flag(s[*i], flag))
   {
      if (IS_NUM(s[*i]))
      {
	 nb *= 10;
	 nb += s[*i] - '0';
      }
      (*i)++;
   }
   return nb;
}

int		kprintf(char *str, ...)
{
   va_list	ap;
   int		i = 0;
   int		pad;
   int		flag = 0;

   va_start(ap, str);
   while (str[i])
   {
      if (str[i] == '%')
      {
	 i++;
	 pad = get_padding(&i, str, &flag);
	 while (pad-- > 0)
	    kputchar(' ');
	 get_arg(str[i], &ap, flag);
      }
      else
	 kputchar(str[i]);
      i++;
   }
   va_end(ap);
   return 0;
}
