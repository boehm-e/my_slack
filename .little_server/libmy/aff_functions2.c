/*
** aff_functions2.c for aff_functions2 in /root/Perso/FDI/DEVC/my_printf/boehm_s
** 
** Made by FAHMI Mohamad Kamal
** Login   <fahmi_m@etna-alternance.net>
** 
** Started on  Fri Mar  6 12:00:26 2015 FAHMI Mohamad Kamal
** Last update Fri Mar  6 12:09:03 2015 FAHMI Mohamad Kamal
*/

#include "prototypes.h"

int	aff_hexadecimal(va_list *ap)
{
  int	nb;

  nb = va_arg(*ap, int);
  my_putnbr_base(nb, "0123456789abcdef");
  return (0);
}

int	aff_hexadecimal_maj(va_list *ap)
{
  int	nb;

  nb = va_arg(*ap, int);
  my_putnbr_base(nb, "0123456789ABCDEF");
  return (0);
}
