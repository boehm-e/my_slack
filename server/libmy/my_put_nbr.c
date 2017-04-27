/*
** my_put_nbr.c for  in /home/boehm_s/DEV_C/Libmy/boehm_s/libmy_01
** 
** Made by BOEHM Steven
** Login   <boehm_s@etna-alternance.net>
** 
** Started on  Fri Oct  3 17:49:13 2014 BOEHM Steven
** Last update Sat Oct  4 20:39:01 2014 BOEHM Steven
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	my_putchar(char c);

int	my_put_nbr(int nb)
{
  int	i;
  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * (-1);
    }
  if (nb == -2147483648)
    {
      write(1, "2147483648", 10);
    }
  if (nb >= 0)
    {
      if (nb >= 10)
	{
	  i = (nb % 10);
          nb = (nb - i) / 10;
	  my_put_nbr(nb);
	  my_putchar(48 + i);
        }
      else
        my_putchar(48 + nb % 10);
    }
}
