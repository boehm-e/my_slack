/*
** my_strncmp.c for  in /home/boehm_s/DEV_C/Libmy/boehm_s/libmy_01
** 
** Made by BOEHM Steven
** Login   <boehm_s@etna-alternance.net>
** 
** Started on  Fri Oct  3 18:27:52 2014 BOEHM Steven
** Last update Fri Oct  3 18:29:07 2014 BOEHM Steven
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	my_strncmp(char *s1, char *s2, int n)
{
  int	r;
  int	i;

  i = 0;
  while (s1[i] == s2[i] &&  i < n - 1)
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
