/*
** my_put_nbr.c for  in /home/boehm_e/Libmy/libmy_01
**
** Made by BOEHM ERWAN
** Login   <boehm_e@etna-alternance.net>
**
** Started on  Sat Oct  4 19:58:35 2014 BOEHM ERWAN
** Last update Sat Oct  4 19:58:37 2014 BOEHM ERWAN
*/
#include "../headers/struct.h"
int  my_put_nbr(int nb)
{
  int   negat;

  negat = 0;
  if (nb < 0)
    {
      my_putchar('-');
      if (nb == -2147483648)
        {
          negat = 1;
          nb++;
        }
      nb = nb * -1;
    }
  if (nb >= 10)
    my_put_nbr(nb / 10);
  if (negat == 1)
    {
      negat = 0;
      my_putchar(nb % 10 + '1');
    }
  else
    my_putchar(nb % 10 + '0');
  return 0;
}
