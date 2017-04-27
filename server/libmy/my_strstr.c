/*
** my_strstr.c for  in /home/boehm_s/DEV_C/Libmy/boehm_s/libmy_01
** 
** Made by BOEHM Steven
** Login   <boehm_s@etna-alternance.net>
** 
** Started on  Fri Oct  3 18:54:30 2014 BOEHM Steven
** Last update Sat Nov 12 04:07:35 2016 BOEHM Steven
*/

char	*my_strstr(char *str, char *to_find)
{
  int	i;

  if (str[0] == '\0')
    return ("null");
  if (str[0] != '\0')
    {
      i = 0;
      while (to_find[i] != '\0')
	{
	  if (to_find[i] != str[i])
	    return (my_strstr(str + 1, to_find));
	  i++;
	}
      return (str);
    }
  else
    return ("null");
}
