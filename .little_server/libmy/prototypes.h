/*
** prototypes.h for libmy in /home/boehm-s/Documents/ETNA/boehm_s/libmy
**
** Made by BOEHM Steven
** Login   <boehm_s@etna-alternance.net>
**
** Started on  Sat Nov 12 03:55:48 2016 BOEHM Steven
** Last update Wed Apr 26 13:51:40 2017 BOEHM Steven
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "./liblist/list.h"

int	my_strlen(char *str);
void	my_putchar(char c);
int	my_putstr(char *str);
void	my_putstr_error(char *str);
int	my_putnbr(int nb);
int	my_putnbr_unsigned(unsigned int nb);
int	my_putnbr_base(int nbr, char *base);
int	aff_char(va_list *ap);
int	aff_str(va_list *ap);
int	aff_int(va_list *ap);
int	aff_int_unsigned(va_list *ap);
int	aff_octal(va_list *ap);
int	aff_hexadecimal(va_list *ap);
int	aff_hexadecimal_maj(va_list *ap);
int	my_printf(char *str, ...);

typedef struct	s_fnc
{
  char	opt;
  int	(*p)(va_list *ap);
} t_fnc;
