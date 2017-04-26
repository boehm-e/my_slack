/*
** aff_functions.c for aff_functions in /root/Perso/FDI/DEVC/my_printf/boehm_s
** 
** Made by FAHMI Mohamad Kamal
** Login   <fahmi_m@etna-alternance.net>
** 
** Started on  Thu Mar  5 19:46:42 2015 FAHMI Mohamad Kamal
** Last update Sat Nov 12 03:57:53 2016 BOEHM Steven
*/

#include "prototypes.h"

int		aff_char(va_list *ap)
{
  char		c;

  c = va_arg(*ap, int);
  my_putchar(c);
  return (1);
}

int		aff_str(va_list *ap)
{
  char		*str;
  int		count;

  str = va_arg(*ap, char *);
  count = my_putstr(str);
  return (count);
}

int		aff_int(va_list *ap)
{
  int		nb;
  int		count;

  nb = va_arg(*ap, int);
  count = my_put_nbr(nb);
  return (count);
}

int		aff_int_unsigned(va_list *ap)
{
  unsigned int	nb;
  int		count;

  nb = va_arg(*ap, int);
  count = my_putnbr_unsigned(nb);
  return (count);
}

int		aff_octal(va_list *ap)
{
  int		nb;

  nb = va_arg(*ap, int);
  my_putnbr_base(nb, "01234567");
  return (0);
}
