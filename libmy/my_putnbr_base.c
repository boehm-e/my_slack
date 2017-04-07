/*
** my_putnbr_base.c for  in /home/boehm_e/Jour05C/my_putnbr_base
**
** Made by BOEHM ERWAN
** Login   <boehm_e@etna-alternance.net>
**
** Started on  Mon Oct  6 16:09:16 2014 BOEHM ERWAN
** Last update Mon Oct  6 18:19:00 2014 BOEHM ERWAN
*/
#include "../headers/struct.h"
void  my_put_nbr1(int nb, int base, char *str)
{
  if (nb < 0)
    {
      my_putchar('-');
      if (nb == -2147483648)
        {
          my_putstr("2147483648");
        }
      nb = nb * -1;
    }
  if (nb >= base)
    {
      my_put_nbr1(nb / base, base, str);
      my_put_nbr1(nb % base, base, str);
    }
  else
    my_putchar(str[(nb % base)]);
}

int	my_putnbr_base(int nbr, char *base)
{
  int j;

  j = my_strlen(base);

  my_put_nbr1(nbr, j, base);
    return (nbr);
}
