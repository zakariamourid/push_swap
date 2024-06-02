#include "linked_list.h"

t_data *ft_newnode(int num) 
{
  t_data *node;

  node = (t_data *)malloc(sizeof(t_data));
  if (!node)
    return (NULL);
  node->value = num;
  node->next = NULL;
  return (node);
}
