/*
** classics.c for  in my_printf
** 
** Made by BOEHM Steven
** Login   <boehm_s@etna-alternance.net>
** 
** Started on  Tue Mar  3 18:15:20 2015 BOEHM Steven
** Last update Sat Nov 12 03:58:38 2016 BOEHM Steven
*/

#include "prototypes.h"

int	my_putnbr_unsigned(unsigned int nb)
{
  int	div;
  int	i;

  div = 1;
  while (nb / div > 9)
    div = div * 10;
  i = 0;
  while (div != 0)
    {
      my_putchar('0' + (nb / div) % 10);
      nb = nb % div;
      div = div /10;
      i++;
    }
  return (i);
}
