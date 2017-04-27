/*
** my_getnbr.c for  in /home/boehm_s/DEV_C/Libmy/boehm_s/libmy_01
** 
** Made by BOEHM Steven
** Login   <boehm_s@etna-alternance.net>
** 
** Started on  Fri Oct  3 18:18:41 2014 BOEHM Steven
** Last update Fri Oct  3 18:19:58 2014 BOEHM Steven
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int     my_getnbr(char *str)
{
  int   i;
  int   i2;
  int   n;
  int   ng;

  n = 0;
  ng = 1;
  if (str == NULL)
      return (0);
  i = 0;
  while (str[i] > '9' || str[i] < '0')
    i++;
  if (str[i - 1] == '-')
      ng = -1;
  i2 = i;
  while (str[i2] <= '9' && str[i2] >= '0')
    i2++;
  n = (n * 10) + (str[i2] - '0');
  return (n * ng);
}
