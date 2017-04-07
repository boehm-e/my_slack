/*
** my_strdup.c for  in /home/boehm_e/libmy_03/libmy_03
** 
** Made by BOEHM ERWAN
** Login   <boehm_e@etna-alternance.net>
** 
** Started on  Wed Oct  8 09:24:31 2014 BOEHM ERWAN
** Last update Wed Oct  8 09:26:26 2014 BOEHM ERWAN
*/
#include "../headers/struct.h"

char    *my_strcpy(char *dest, char *src)
{
  int   i;

  i = 0;

  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}

char    *my_strdup(char *str)
{
  char  *copy;
  int   i;

  for (i = 0; str[i] != '\0'; i++);
  copy = malloc(i * sizeof(char));
  my_strcpy(copy, str);
  return (copy);
}
