/*
** screen.h for unicorn in /home/faltad/projets/Unicorn/src
** 
** Made by Faltad
** Login   <faltad@gmail.com>
** 
** Started on  Tue Jun 29 23:48:05 2010 Faltad
** Last update Wed Jun 30 23:06:16 2010 Faltad
*/

#ifndef __SCREEN_H_
#define __SCREEN_H_

#define __VIDEORAM	0xB8000
#define COLS		160

void	kputs(char *s);
void	kputchar(char c);
void	clear_screen(void);

#endif
