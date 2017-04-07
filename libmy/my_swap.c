/*
** my_swap.c for  in /home/boehm_e/Jour03C/my_swap
** 
** Made by BOEHM ERWAN
** Login   <boehm_e@etna-alternance.net>
** 
** Started on  Wed Oct  1 09:08:20 2014 BOEHM ERWAN
** Last update Sat Oct  4 20:11:38 2014 BOEHM ERWAN
*/
#include "../headers/struct.h"

void	my_swap(int *a, int *b)
{
  int	c = *a;
  *a = *b;
  *b = c;
}
