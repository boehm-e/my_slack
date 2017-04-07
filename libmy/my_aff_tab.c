/*
** my_aff_tab.c for  in /home/boehm_e/Jour02C/my_aff_tab
**
** Made by BOEHM ERWAN
** Login   <boehm_e@etna-alternance.net>
**
** Started on  Tue Sep 30 09:02:07 2014 BOEHM ERWAN
** Last update Sat Oct  4 19:50:25 2014 BOEHM ERWAN
*/
#include "../headers/struct.h"

void my_aff_tab(int tab[], int len)
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
