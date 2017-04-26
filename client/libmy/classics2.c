/*
** classics2.c for classics2 in /root/Perso/FDI/DEVC/my_printf/boehm_s
** 
** Made by FAHMI Mohamad Kamal
** Login   <fahmi_m@etna-alternance.net>
** 
** Started on  Fri Mar  6 12:16:58 2015 FAHMI Mohamad Kamal
** Last update Fri Mar  6 12:31:25 2015 FAHMI Mohamad Kamal
*/

#include "prototypes.h"

void	my_putstr_error(char *str)
{
  int	i;

  i = 0;
  if (!(str == NULL))
    {
      while (str[i] != '\0')
        {
          my_putchar(str[i++]);
        }
    }
  exit(1);
}
