/*
** my_strdup.c for  in /home/boehm_s/DEV_C/Jour07/my_strdup
** 
** Made by BOEHM Steven
** Login   <boehm_s@etna-alternance.net>
** 
** Started on  Mon Oct  6 10:53:03 2014 BOEHM Steven
** Last update Sat Nov 12 04:04:47 2016 BOEHM Steven
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*my_strcpy(char *dest, char *src);
int     my_strlen(char *str);

char	*my_strdup(char *str)
{
  char	*str2;

  str2 = malloc(my_strlen(str) * sizeof(*str));
  str2 = my_strcpy(str2, str);
  return (str2);
}
