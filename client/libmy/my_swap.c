/*
** my_swap.c for  in /home/boehm_s/DEV_C/Libmy/boehm_s/libmy_01
** 
** Made by BOEHM Steven
** Login   <boehm_s@etna-alternance.net>
** 
** Started on  Fri Oct  3 18:09:34 2014 BOEHM Steven
** Last update Sat Oct  4 18:33:40 2014 BOEHM Steven
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	my_swap(int *a, int *b)
{
  int	c;
  c = *a;
  *a = *b;
  *b = c;
}
