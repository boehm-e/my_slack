/*
** my_putchar.c for  in /home/boehm_s/DEV_C/Libmy/boehm_s/libmy_01
** 
** Made by BOEHM Steven
** Login   <boehm_s@etna-alternance.net>
** 
** Started on  Fri Oct  3 17:43:26 2014 BOEHM Steven
** Last update Fri Oct  3 17:47:13 2014 BOEHM Steven
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void my_putchar(char c)
{
  write(1, &c, 1);
}

