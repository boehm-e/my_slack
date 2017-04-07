/*
** my_strstr.c for  in /home/boehm_e/libr
** 
** Made by BOEHM ERWAN
** Login   <boehm_e@etna-alternance.net>
** 
** Started on  Sat Oct  4 18:43:17 2014 BOEHM ERWAN
** Last update Mon Oct  6 10:25:09 2014 BOEHM ERWAN
*/
#include "../headers/struct.h"

char *my_strstr(char *str, char *to_find)
{
  int i;
  int i2;
  int num;

  i2 = 0;
  for (num = 0; to_find[num] != '\0'; num++)
    for (i = 0; str[i] != '\0'; i++)
      {
	i2 = 0;
	while (i2 < num && str[(i + i2)] == to_find[i2] && str[(i + i2)] != '\0')
	  {
	    i2++;
	  }
	if (i2 == num)
	  {
	    return (&str[i]);
	  }
      }
  str = "null";
  return (str);
}
