/*
** my_strcpy.c for  in /home/boehm_e/Jour04C/my_strcpy
** 
** Made by BOEHM ERWAN
** Login   <boehm_e@etna-alternance.net>
** 
** Started on  Thu Oct  2 09:03:56 2014 BOEHM ERWAN
** Last update Fri Oct  3 22:32:32 2014 BOEHM ERWAN
*/
#include "../headers/struct.h"

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;

  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}
