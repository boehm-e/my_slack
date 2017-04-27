/*
** my_putstr.c for  in /home/boehm_s/DEV_C/Libmy/boehm_s/libmy_01
** 
** Made by BOEHM Steven
** Login   <boehm_s@etna-alternance.net>
** 
** Started on  Fri Oct  3 18:15:20 2014 BOEHM Steven
** Last update Sat Nov 12 04:03:42 2016 BOEHM Steven
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	my_putchar(char c);

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  if (!(str == NULL))
    {
      while (str[i] != '\0')
	{
	  my_putchar(str[i++]);
	}
    }
}
