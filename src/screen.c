/*
** screen.c for unicorn in /home/faltad/projets/Unicorn/src
** 
** Made by Faltad
** Login   <faltad@gmail.com>
** 
** Started on  Tue Jun 29 23:31:52 2010 Faltad
** Last update Wed Jun 30 00:56:39 2010 Faltad
*/

#include "libc.h"
#include "screen.h"

char	__kposY = 0;
char	__kposX = 0;
char	__kattr	= 0x07;

void	kputs(char *s)
{
   while (*s != '\0')
   {
      kputchar(*s);
      s++;
   }
}

void	clear_screen(void)
{
   char	*videoram = (char *)__VIDEORAM;

   memset(videoram, 0, COLS * 25);
}

void	kputchar(char c)
{
   char	*videoram = (char *)__VIDEORAM;

   *(videoram + __kposY * COLS + __kposX * 2)  = c;
   *(videoram + __kposY * COLS + __kposX * 2 + 1)  = __kattr;
   __kposX++;
   if (__kposX >= COLS / 2)
   {
      __kposX = 0;
      __kposY++;
   }
}
