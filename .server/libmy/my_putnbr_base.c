/*
** my_putnbr_base.c for  in /home/boehm_s/DEV_C/Jour05/boehm_s/my_putnbr_base
**
** Made by BOEHM Steven
** Login   <boehm_s@etna-alternance.net>
**
** Started on  Fri Oct  3 10:44:14 2014 BOEHM Steven
** Last update Mon Oct  6 10:38:04 2014 BOEHM Steven
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	my_putchar(char c);

int	my_strlen(char *str);

int	 my_putnbr_base(int nbr, char *base)
{
  if (nbr < 0)
    {
      nbr = nbr * (-1);
      my_putchar('-');
    }
  if (nbr >= my_strlen(base))
    {
      my_putnbr_base(nbr /  my_strlen(base), base);
      my_putchar(base[nbr % my_strlen(base)]);
    }
  if (nbr >= 0 && nbr < my_strlen(base))
    {
      my_putchar(base[nbr]);
    }
  return (nbr);
}
