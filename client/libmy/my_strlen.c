/*
** my_putstr.c for  in /home/boehm_s/DEV_C/Libmy/boehm_s/libmy_01
** 
** Made by BOEHM Steven
** Login   <boehm_s@etna-alternance.net>
** 
** Started on  Fri Oct  3 18:11:36 2014 BOEHM Steven
** Last update Sat Nov 12 04:05:41 2016 BOEHM Steven
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;

  return (i);
}
