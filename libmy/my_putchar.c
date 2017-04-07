/*
** my_putchar.c for   in /home/boehm_e/libr
**
** Made by BOEHM ERWAN
** Login   <boehm_e@etna-alternance.net>
**
** Started on  Sat Oct  4 17:24:06 2014 BOEHM ERWAN
** Last update Sat Oct  4 19:51:30 2014 BOEHM ERWAN
*/
#include "../headers/struct.h"

void my_putchar(char c)
{
  write(1, &c, 1);
}
