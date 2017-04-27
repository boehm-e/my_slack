/*                                                                             
** my_strncat.c for  in /home/boehm_s/DEV_C/Jour04/boehm_s                     
**                                                                             
** Made by BOEHM Steven                                                        
** Login   <boehm_s@etna-alternance.net>                                       
**                                                                             
** Started on  Fri Oct  3 18:40:56 2014 BOEHM Steven                           
** Last update Fri Oct  3 18:53:44 2014 BOEHM Steven
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char    *my_strncat(char *str1, char *str2, int n)
{
  int   i;
  int   a;

  i = 0;
  a = 0;

  while (str1[i] != '\0')
    {
      i = i + 1;
    }

  while (str2[a] != str2[n])
    {
      str1[i] = str2[a];
      i = i + 1;
      a = a + 1;
    }
  return (str1);
}
