/*
** my_strcat.c for  in /home/boehm_e/Jour04C/my_strcat
** 
** Made by BOEHM ERWAN
** Login   <boehm_e@etna-alternance.net>
** 
** Started on  Thu Oct  2 17:28:53 2014 BOEHM ERWAN
** Last update Sat Oct  4 19:52:36 2014 BOEHM ERWAN
*/
#include "../headers/struct.h"

char	*my_strcat(char *str1, char *str2) 
{
  int	i;
  int	j;

  j = 0;
  i = 0;

  while (str1[i] != '\0')
    {
      i++;
    } 

  while (str2[j] != '\0')
    {
      str1[i] = str2[j];
      i++;
      j++;
    }
  return (str1);
}
