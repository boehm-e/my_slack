/*
** my_strncpy.c for  in /home/boehm_e/Jour04C/my_strncpy
** 
** Made by BOEHM ERWAN
** Login   <boehm_e@etna-alternance.net>
** 
** Started on  Thu Oct  2 09:35:08 2014 BOEHM ERWAN
** Last update Sat Oct  4 19:55:44 2014 BOEHM ERWAN
*/
#include "../headers/struct.h"

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  
  for (i = 0; ((src[i] != '\0') && (i < n)); i++)
    {
      dest[i] = src[i];
    }
  for (i = 0; ((src[i] != '\0') && (i > n)); i++)
    {
      dest[i] = 0;
    }
  return (dest);
}
