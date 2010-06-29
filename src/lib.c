/*
** lib.c for unicorn in /home/faltad/projets/Unicorn/src
** 
** Made by Faltad
** Login   <faltad@gmail.com>
** 
** Started on  Wed Jun 30 00:47:04 2010 Faltad
** Last update Wed Jun 30 00:54:27 2010 Faltad
*/

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
   int	n = 0;

   while (*s++);
   return n;
}
