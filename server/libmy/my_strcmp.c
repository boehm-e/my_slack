/*
** my_strcmp.c for  in /home/boehm_s/DEV_C/Libmy/boehm_s/libmy_01
** 
** Made by BOEHM Steven
** Login   <boehm_s@etna-alternance.net>
** 
** Started on  Fri Oct  3 18:26:36 2014 BOEHM Steven
** Last update Fri Oct  3 18:27:35 2014 BOEHM Steven
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	my_strcmp(char *s1, char *s2)
{
  int	r;
  int	i;

  i = 0;
  while (s1[i] == s2[i] && s1[i] != '\0')
    {
      r = 0;
      i = i + 1;
    }
  if (s1[i] != s2[i])
    {
      if (s1[i] - s2[i] > 0)
	{
	  r = 1;
	}
      else if (s1[i] - s2[i] < 0)
	{
	  r = -1;
	}
      else if (s1[i-1] == s2[i-1])
	{
	  r = 0;
	}
    }
  return (r);
}
