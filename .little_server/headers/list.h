#ifndef _LIST_H_
#define _LIST_H_

typedef struct		s_node
{
  int			id;
  void			*data;
  struct s_node		*prev;
  struct s_node		*next;
} t_node;


typedef struct		s_list {
  unsigned int		length;
  t_node		*head;
  t_node		*tail;
  void			(*free_fn)(void *d);
  int			(*compare)(void *data1, void *data2);
  void			(*display)(void *data);
} t_list;


t_list			*list_new();
void			list_destroy(t_list *list);

t_node			*list_create_node();

t_node			*list_append(t_list *list, t_node *node);
t_node			*list_prepend(t_list *list, t_node *node);
int			list_size(t_list *list);

t_node			*list_find_node_by_id(t_list *list, unsigned int id);
t_node			*list_find_node_by_data(t_list *list, void *data);

void			list_delete_node(t_list *list, t_node *node);
int			list_delete_node_by_id(t_list *list, unsigned int id);
int			list_delete_node_by_data(t_list *list, void *data);

void			list_display_list(t_list *list);

#endif /* !_LIST_H_ */
