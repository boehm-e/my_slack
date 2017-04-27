/*
** my_aff_tab.c for  in /home/boehm_s/DEV_C/Libmy/boehm_s/libmy_01
** 
** Made by BOEHM Steven
** Login   <boehm_s@etna-alternance.net>
** 
** Started on  Fri Oct  3 18:20:19 2014 BOEHM Steven
** Last update Sat Nov 12 03:59:51 2016 BOEHM Steven
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	my_putchar(char c);

void    my_put_nbr(int n);

void	my_aff_tab(int tab[], int len)
{
  int	i;

  i = 0;
  while (i < len)
    {
      my_put_nbr(tab[i]);
      my_putchar('\n');
      i++;
    }
}
