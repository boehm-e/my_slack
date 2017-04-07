/*
** my_putstr.c for  in /home/boehm_e/Jour02C/my_putstr
**
** Made by BOEHM ERWAN
** Login   <boehm_e@etna-alternance.net>
**
** Started on  Tue Sep 30 11:00:08 2014 BOEHM ERWAN
** Last update Sat Oct  4 17:33:15 2014 BOEHM ERWAN
*/
#include "../headers/struct.h"
void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      ++i;
    }
}
