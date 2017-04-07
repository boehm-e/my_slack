/*
** my_isneg.c for  in /home/boehm_e/libr
** 
** Made by BOEHM ERWAN
** Login   <boehm_e@etna-alternance.net>
** 
** Started on  Sat Oct  4 17:25:47 2014 BOEHM ERWAN
** Last update Sat Oct  4 19:51:16 2014 BOEHM ERWAN
*/
#include "../headers/struct.h"

int my_isneg(int n)
{
  if ( n < 0 )
    {
      n = 0;
    }
  else if ( n >= 0 )
    {
      n = 1;
    }
  return n;
}
