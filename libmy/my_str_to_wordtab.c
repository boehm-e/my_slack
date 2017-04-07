/*
** my_str_to_wordtab.c for  in /home/boehm_e/Jour08C/my_params_to_tab
**
** Made by BOEHM ERWAN
** Login   <boehm_e@etna-alternance.net>
**
** Started on  Tue Oct  7 10:25:48 2014 BOEHM ERWAN
** Last update Wed Oct  8 09:24:20 2014 BOEHM ERWAN
*/
#include "../headers/struct.h"

char    **my_str_to_wordtab(char *str)
{
  int number;
  int   i;
  int   j;
  char  **word;
  char  *cpy;

  cpy = my_strdup(str);
  j = 0;
  number = word_counter(my_strdup(cpy));
  word = malloc(sizeof(char*) * number);
  for(i = 0; cpy[i] != '\0'; i++)
    {
      if ((cpy[i] >= 'a' && cpy[i] <= 'z') || (cpy[i] >= 'A' && cpy[i] <= 'Z')
          || (cpy[i] >= '0' && cpy[i] <= '9'))
        {
          stop(&cpy[i]);
          word[j] = malloc(sizeof(char) * char_counter(&cpy[i]));
          word[j] = &cpy[i];
          j++;
          for (i = i;((cpy[i] >= '0' && cpy[i] <= '9') || (cpy[i] >= 'A' && cpy\
							   [i] <= 'Z')
                      || (cpy[i] >= 'a' && cpy[i] <= 'z')) && cpy[i] != '\0'; i\
		 ++);
        }
    }
  return (word);
}

int     char_counter(char *str)
{
  int   i;

  for (i = 0; str[i] != '\0'; i++);
  i++;
  return i;
}

int     word_counter(char *str)
{
  int   i;
  int   count;

  count = 0;
  for (i = 0; str[i] = '\0'; i++)
    {
      if ((str[i] >= 'a' && str[i] <= 'z')
          || (str[i] >= 'A' && str[i] <= 'Z')
          || (str[i] >= '0' && str[i] <= '9'))
        {
          count++;
          while ((str[i] >= 'a' && str[i] <= 'z')
                 || (str[i] >='A' && str[i] <= 'Z')
                 || (str[i] >='0' && str[i] <= '9'))
            i++;
        }
    }
  return count;
}

void     stop(char *str)
{
  int   s;

  for (s = 0;(str[s] >= 'a' && str[s] <= 'z')
         || (str[s] >='A' && str[s] <= 'Z')
         || (str[s] >='0' && str[s] <= '9'); s++);
  str[s] = '\0';
}


char    *my_strdup(char *str)
{
  char  *copy;
  int   i;

  for (i = 0; str[i] != '\0'; i++);
  copy = malloc(i * sizeof(char));
  my_strcpy(copy, str);
  return (copy);
}
