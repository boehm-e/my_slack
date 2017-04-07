/*
** my_strcmp.c for  in /home/boehm_e/Jour04C/my_strcmp
** 
** Made by BOEHM ERWAN
** Login   <boehm_e@etna-alternance.net>
** 
** Started on  Thu Oct  2 13:58:32 2014 BOEHM ERWAN
** Last update Sat Oct  4 19:53:17 2014 BOEHM ERWAN
*/
#include "../headers/struct.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;
  int	j;
  int	ret;
  
  i = 0;
  j = 0;
  ret = 0;

  while ((s1[i] != '\0') || (s2[i] != '\0'))
    {
      j = s1[i] - s2[i];
     
      if (j < 0)
	{
	  ret = -1;
	  return (ret);
	}
      else if (j > 0)
	{
	  ret = 1;
	  return (ret);
	}
      else if (j == 0)
	{
	  ret = 0;
	}
      i++;
    }
  return (ret);
}
