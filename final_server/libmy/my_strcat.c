/*
** my_strcat.c for  in /home/boehm_s/DEV_C/Libmy/boehm_s/libmy_01
** 
** Made by BOEHM Steven
** Login   <boehm_s@etna-alternance.net>
** 
** Started on  Fri Oct  3 18:29:59 2014 BOEHM Steven
** Last update Fri Oct  3 18:31:20 2014 BOEHM Steven
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*my_strcat(char *str1, char *str2)
{
  int	i;
  int	a;

  i = 0;
  a = 0;

  while (str1[i] != '\0')
    {
      i = i + 1;
    }

  while (str2[a] != '\0')
    {
      str1[i] = str2[a];
      i = i + 1;
      a = a + 1;
    }
  return (str1);
}
