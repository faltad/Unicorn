/*
** lib.c for unicorn in /home/faltad/projets/Unicorn/src
** 
** Made by Faltad
** Login   <faltad@gmail.com>
** 
** Started on  Wed Jun 30 00:47:04 2010 Faltad
** Last update Wed Jun 30 23:12:53 2010 Faltad
*/

#include "screen.h"

void	*memset(void *s, int c, int n)
{
   int	i;

   for (i = 0; i < n; i++)
      *(char *)s++ = c;
   return s - n;
}

void	*memcpy(void *dest, const void *src, int n)
{
   int	i;

   for (i = 0; i < n; i++)
      *(char *)dest++ = *(char *)src++;
   return dest - n;
}

int	strlen(char *s)
{
   char	*p = s;

   while (*s)
      s++;
   return s - p;
}

/* We should replace kputchar with putc later */

void	putnbr_base(int nb, char *base)
{
   if (nb < 0)
   {
      kputchar('-');
      nb *= -1;
   }
   if (nb < strlen(base))
      kputchar(base[nb]);
   else
   {
      putnbr_base(nb / strlen(base), base);
      kputchar(base[nb % strlen(base)]);
   }
}

void	putnbr(int nb)
{
   putnbr_base(nb, "0123456789");
}
