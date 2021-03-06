#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define my_printf printf


t_list		*list_new() {
  t_list	*self;

  if (!(self = malloc(sizeof(t_list))))
    return (NULL);
  self->head = NULL;
  self->tail = NULL;
  self->free_fn = NULL;
  self->compare = NULL;
  self->length = 0;
  return (self);
}


t_node		*list_create_node() {
  t_node	*node;

  node = malloc(sizeof(t_node));
  node->id = 0;
  node->data = NULL;
  node->prev = NULL;
  node->next = NULL;
  return (node);
}

void		list_destroy(t_list *list) {
  unsigned int	len;
  t_node	*next;
  t_node	*curr;

  len = list->length;
  curr = list->head;
  while (len--) {
    next = curr->next;
    if (list->free_fn)
      list->free_fn(curr->data);
    free(curr);
    curr = next;
  }
  free(list);
}

t_node		*list_append(t_list *list, t_node *node) {
  if (!node)
    return (NULL);

  if (list->length != 0) {
    node->id = list->tail->id + 1;
    node->prev = list->tail;
    node->next = NULL;
    list->tail->next = node;
    list->tail = node;
  } else {
    node->id = 0;
    list->head = node;
    list->tail = node;
    node->prev = NULL;
    node->next = NULL;
  }
  list->length++;
  return (node);
}

t_node		*list_prepend(t_list *list, t_node *node) {
  if (!node)
    return (NULL);

  if (list->length != 0) {
    node->prev = NULL;
    node->next = list->head;
    list->head->prev = node;
    list->head = node;
  } else {
    node->prev = NULL;
    node->next = NULL;
    list->head = node;
    list->tail = node;
  }
  list->length++;
  return (node);
}

int		list_size(t_list *list) {
  int		size;

  size = (int) list->length;
  return (size);
}

t_node		*list_find_node_by_id(t_list *list, unsigned int id) {
  t_node	*node;

  node = list->head;
  while (node != NULL) {
    if (node->id == (int) id) {
      return (node);
    }
    node = node->next;
  }
  return (NULL);
}


t_node		*list_find_node_by_data(t_list *list, void *data) {
  t_node	*node;

  if (list->compare == NULL)
    return (NULL);

  node = malloc(sizeof(t_node));
  node = list->head;
  while (node != NULL) {
    if (list->compare(node->data, data) == 0) {
      return (node);
    }
    node = node->next;
  }
  return (NULL);
}



void		list_delete_node(t_list *list, t_node *node) {

  if (!list->free_fn)
    return;

  if (node->prev) {
    node->prev->next = node->next;
  } else {
    list->head = node->next;
  }

  if (node->next) {
    node->next->prev = node->prev;
  } else {
    list->tail = node->prev;
  }
  list->free_fn(node->data);
  free(node);
  list->length--;
}



int		list_delete_node_by_id(t_list *list, unsigned int id) {
  t_node	*node;

  if (!list->free_fn)
    return (1);
  node = list->head;
  while (node != NULL) {
    if (node->id == (int) id) {
      list_delete_node(list, node);
      return (0);
    }
    node = node->next;
  }
  return (1);
}


int		list_delete_node_by_data(t_list *list, void *data) {
  t_node	*node;

  if (!list->free_fn)
    return (1);
  node = list->head;
  while (node != NULL) {
    if (list->compare(node->data, data) == 0) {
      list_delete_node(list, node);
      return (0);
    }
    node = node->next;
  }
  return (1);
}


void			list_display_list(t_list *list) {
  t_node	*node;

  if (!list->display)
    return;
  node = list->head;
  while (node != NULL) {
    my_printf("node ID : %i\n", node->id);
    list->display(node->data);
    my_printf("----------------------------------------------------------- \n\n");
    node = node->next;
  }
}
