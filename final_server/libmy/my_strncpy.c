/*
** my_strncpy.c for  in /home/boehm_s/DEV_C/Libmy/boehm_s/libmy_01
** 
** Made by BOEHM Steven
** Login   <boehm_s@etna-alternance.net>
** 
** Started on  Fri Oct  3 18:25:06 2014 BOEHM Steven
** Last update Sat Nov 12 04:06:37 2016 BOEHM Steven
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while (src[i] != src[n])
    {
      dest[i] = src[i];
      i = i + 1;
    }
  if (n > i)
    dest[i] = '\0';
  return (dest);
}
