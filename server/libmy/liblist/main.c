//
// main.c for liblist in /home/boehm-s/Documents/ETNA/boehm_s/libmy/boehm_s/liblist
//
// Made by BOEHM Steven
// Login   <boehm_s@etna-alternance.net>
//
// Started on  Wed Feb  1 09:06:36 2017 BOEHM Steven
// Last update Wed Feb  1 21:30:01 2017 BOEHM Steven
//

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "list.h"

int	    compare(void *data1, void *data2);
void	    display(void *data);

int	    main() {
  t_list    *list;
  t_node    *node;
  t_node    *node2;
  t_node    *node3;
  t_node    *node_find;
  t_node    *node_find2;

  list = list_new();
  list->compare = &compare;
  list->display = &display;

  node = list_create_node(list);
  node->data = (char *)"coucou";
  list_append(list, node);

  node2 = list_create_node(list);
  node2->data = (char *)"hahah 2";
  list_append(list, node2);

  node3 = list_create_node(list);
  node3->data = (char *)"hey you";
  list_append(list, node3);

  node_find = malloc(sizeof(t_node));
  node_find = list_find_node_by_id(list, 1);

  node_find2 = malloc(sizeof(t_node));
  node_find2 = list_find_node_by_data(list, (char *)"hey you");

  if (node_find != NULL)
    printf("%s\n", node_find->data);

  if (node_find2 != NULL)
    printf("%i : %s\n", node_find2->id, node_find2->data);

  list_display_list(list);

  return (0);
}

int	    compare(void *data1, void *data2) {
  if (strcmp((char *)data1, (char *)data2) == 0)
    return 0;
  else
    return 1;
}

void	    display(void *data) {
  printf("data : %s\n", (char *) data);
}
