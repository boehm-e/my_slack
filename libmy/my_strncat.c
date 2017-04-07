/*
** my_strncat.c for  in /home/boehm_e/libr
** 
** Made by BOEHM ERWAN
** Login   <boehm_e@etna-alternance.net>
** 
** Started on  Sat Oct  4 18:03:36 2014 BOEHM ERWAN
** Last update Sat Oct  4 19:55:12 2014 BOEHM ERWAN
*/
#include "../headers/struct.h"

char *my_strncat(char *str1, char *str2, int n)
{
  int	i;
  int	j;

  j = 0;
  i = 0;

  while (str1[i] != '\0')
    {
      i++;
    } 

  while ((str2[j] != '\0') && (j < n))
    {
      str1[i] = str2[j];
      i++;
      j++;
    }
  return (str1);
}
