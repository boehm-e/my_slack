/*
** my_isneg.c for  in /home/boehm_s/DEV_C/Libmy/boehm_s/libmy_01
** 
** Made by BOEHM Steven
** Login   <boehm_s@etna-alternance.net>
** 
** Started on  Fri Oct  3 17:44:08 2014 BOEHM Steven
** Last update Sat Nov 12 04:00:25 2016 BOEHM Steven
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int my_isneg(int n)
{
  if (n < 0)
    n = 0;
  else if (n >= 0)
    n = 1;
  return (n);
}
