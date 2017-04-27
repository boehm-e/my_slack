#ifndef                 _STRUCT_
# define                _STRUCT_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

typedef struct s_node t_node;

struct                  s_node
{
  int                 index;
  void                *value;
  t_node*             prev;
  t_node*             next;
  int                 (*functionPtr)();
  };

typedef struct          s_list
{
  int                 nb_elem;
  t_node*             first;
  t_node*             last;
  int                 (*compare)(void *, void*);
} t_list;

typedef struct          s_launch
{
    char*               str;
    int                (*ptr)();
    int               required;
} t_launch_ptr;

void		add_node_to_list(t_list *list, t_node* node);
t_list		*create_list();
int show_list(t_list* list);
t_node *create_node();
void	del_node_from_list(t_list *list, t_node *node);
t_node *search_node_by_index(t_list *list, int index);
t_node *search_node_by_value(t_list *list, void *value);
int my_compare(void *char1, void *char2);
int print_usage();
int get_bonus(t_list *list, char *option);
int optionF(void *param);
int optionV(void *param);
int optionX(void *param);
int fill_list_args(t_list *list, char **argv, int argc);
void init_pointer_function(t_list *list);
int check_required_params(t_list *list);
int launch_option_function(t_list *list, char *option, void *param);
int get_required_count();


void my_aff_tab(int tab[], int len);
int	my_getnbr(char *str);
void	my_swap(int *a, int *b);
char *my_strstr(char *str, char *to_find);
char	*my_strncpy(char *dest, char *src, int n);
int my_strncmp(char *s1, char *s2, int n);
int	my_strlen(char *str);
char    *my_strcpy(char *dest, char *src);
char	*my_strcpy(char *dest, char *src);
int	my_strcmp(char *s1, char *s2);
char	*my_strcat(char *str1, char *str2);
char    **my_str_to_wordtab(char *str);
void	my_putstr(char *str);
void  my_put_nbr1(int nb, int base, char *str);
int  my_put_nbr(int nb);
void my_putchar(char c);
int my_isneg(int n);
char *my_strncat(char *str1, char *str2, int n);

#endif                   /* !_STRUCT_ */
