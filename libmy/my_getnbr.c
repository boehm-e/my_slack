/*
** my_getnbr.c for  in /home/boehm_e/Jour03C/my_getnbr
** 
** Made by BOEHM ERWAN
** Login   <boehm_e@etna-alternance.net>
** 
** Started on  Wed Oct  1 10:00:01 2014 BOEHM ERWAN
** Last update Sat Oct  4 20:12:05 2014 BOEHM ERWAN
*/
#include "../headers/struct.h"

int	my_getnbr(char *str)
{
  int	signe;
  int	i;
  int	k;

  signe = 1;
  i = 0;
  k = 0;

  while ((str[i] < '0' || str[i] > '9') && str[i] != '\0')
    {    
      i++;
    }

  if (str[(i-1)] == '-')
    {
      signe = -1;
    }

  while (str[i] >= 48 && str[i] <= 57)
    {
      k = 10 * k;
      k = k + (str[i] - 48);
      i++;
    }
  return (k * signe);
}
