/*
** libmy.h for my_FTL in /home/boehm-s/Documents/ETNA/boehm_s
** 
** Made by BOEHM Steven
** Login   <boehm_s@etna-alternance.net>
** 
** Started on  Sat Nov 12 03:26:07 2016 BOEHM Steven
** Last update Sat Nov 12 11:57:55 2016 BOEHM Steven
*/

#ifndef _LIBMY_H_
#define _LIBMY_H_

void	my_putchar(char c);
void	my_putstr(char *str);
int	my_getnbr(char *str);
void	my_aff_tab(int tab[], int len);
int	my_put_nbr(int nb);
int	my_putnbr_base(int nbr, char *base);
char	*my_strcpy(char *dest, char *src);
char	*my_strncpy(char *dest, char *src, int n);
int	my_strlen(char *str);
char	*my_strdup(char *str);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int n);
int	my_isneg(int n);
char	*my_strcat(char *str1, char *str2);
char	*my_strncat(char *str1, char *str2, int n);
int	my_strlen(char *str);
char	*my_strstr(char *str, char *to_find);
char	**my_str_to_wordtab(char *str);
int	my_printf(char *str, ...);
float	my_pow(float n, int pow);

#endif /* !_LIBMY_H_ */
