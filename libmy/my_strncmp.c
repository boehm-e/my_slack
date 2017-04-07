/*
** my_strncmp.c for  in /home/boehm_e/Jour04C/my_strncmp
** 
** Made by BOEHM ERWAN
** Login   <boehm_e@etna-alternance.net>
** 
** Started on  Thu Oct  2 16:17:04 2014 BOEHM ERWAN
** Last update Fri Oct  3 22:33:33 2014 BOEHM ERWAN
*/
#include "../headers/struct.h"

int my_strncmp(char *s1, char *s2, int n)
{
  int i;
  int j;
  int ret;
  
  i = 0;
  j = 0;
  ret = 0;
  
  while (((s1[i] != '\0') || (s2[i] != '\0')) && (i < n))
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
