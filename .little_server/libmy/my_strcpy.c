/*
** my_strcpy.c for  in /home/boehm_s/DEV_C/Libmy/boehm_s/libmy_01
** 
** Made by BOEHM Steven
** Login   <boehm_s@etna-alternance.net>
** 
** Started on  Fri Oct  3 18:23:32 2014 BOEHM Steven
** Last update Fri Oct  3 18:24:57 2014 BOEHM Steven
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*my_strcpy(char *dest, char *src)
{
  int i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}
