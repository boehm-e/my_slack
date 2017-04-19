/*
** my_str_to_wordtab.c for  in /home/boehm_s/DEV_C/Jour07/boehm_s/my_str_to_wordtab
** 
** Made by BOEHM Steven
** Login   <boehm_s@etna-alternance.net>
** 
** Started on  Mon Oct  6 11:29:29 2014 BOEHM Steven
** Last update Sat Nov 12 04:09:11 2016 BOEHM Steven
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	my_putchar(char c);
void	my_putstr(char *str);

int	is_alphanum(char c)
{
  int	r;

  if (c >= 'A' && c <= 'Z')
    r = 1;
  else if (c >= 'a' && c <= 'z')
    r = 1;
  else if (c >= '0' && c <= '9')
    r = 1;
  else if (c == '\n' || c == '\t')
    r = 1;
  else
    r = 0;
  return (r);
}

int	count_word(char *str)
{
  int	i;
  int	count;

  i = 0;
  count = 0;
  while (str[i])
    {
      if (!(is_alphanum(str[i + 1] || str[i + 1] == '\0')))
	count++;
      i++;
    }
  return (count);
}

int	len_word(char *str, int p)
{
  int	i;
  int	count2;

  i = p;
  count2 = 0;
  while (str[i] || is_alphanum(str[i]) == 1)
    {
      i++;
      count2++;
    }
  return (count2);
}

char	**my_str_to_wordtab(char *str)
{
  int	i;
  int	j;
  int	k;
  char	**tab;

  i = 0;
  j = 0;
  tab = malloc(sizeof(char *) * count_word(str) + 1);
  while (str[i])
    {
      while (str[i] && is_alphanum(str[i]) != 1)
	i++;
      tab[j] = malloc(sizeof(char) * (len_word(str, i)) + 1);
      k = 0;
      while (str[i] && is_alphanum(str[i]) != 0)
	{
	  tab[j][k] = str[i];
	  i++;
	  k++;
	}
      tab[j][k] = '\0';
      j++;
      i++;
    }
  return (tab);
}
