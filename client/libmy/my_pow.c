/*
** my_pow.c for my_pow in /home/boehm-s/Documents/ETNA/boehm_s/libmy
** 
** Made by BOEHM Steven
** Login   <boehm_s@etna-alternance.net>
** 
** Started on  Sat Nov 12 04:00:36 2016 BOEHM Steven
** Last update Sat Nov 12 04:01:14 2016 BOEHM Steven
*/

float	my_pow(float n, int pow)
{
  float	tmp;

  if (pow == 0)
    return (1);
  tmp = my_pow(n, pow/2);
  if (pow % 2 == 0)
    return (tmp * tmp);
  else
    {
      if (pow > 0)
	return (n * tmp * tmp);
      else
	return (tmp * tmp) / n;
    }
}
