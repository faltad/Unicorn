/*
** screen.c for unicorn in /home/faltad/projets/Unicorn/src
** 
** Made by Faltad
** Login   <faltad@gmail.com>
** 
** Started on  Tue Jun 29 23:31:52 2010 Faltad
** Last update Wed Jun 30 11:05:29 2010 Faltad
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

void	scroll_up(int n)
{
   char	*videoram = (char *)__VIDEORAM;

   memcpy(videoram, videoram + (COLS * n), (25 - n) * COLS);
   memset(videoram + COLS * (25 - n), 0, COLS * n);
}

void	kputchar(char c)
{
   char	*videoram = (char *)__VIDEORAM;

   if (c == '\n')
   {
      __kposX = 0;
      __kposY++;
   }
   else if (c == '\r')
      __kposX = 0;
   else if (c == '\t')
      __kposX += 4;
   else
   {
      *(videoram + __kposY * COLS + __kposX * 2)  = c;
      *(videoram + __kposY * COLS + __kposX * 2 + 1)  = __kattr;
      __kposX++;
   }
   if (__kposX > 79)
   {
      __kposX = __kposX - 80;
      __kposY++;
   }
   if (__kposY > 24)
   {
      __kposY = 24;
      scroll_up(1);
   }
}
