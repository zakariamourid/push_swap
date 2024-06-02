#include "linked_list.h"

void ft_stack_addfront(t_data **head, t_data *node) 
{
  if (!head || !node)
    return;
  node->next = *head;
  *head = node;
}