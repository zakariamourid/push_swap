#include "linked_list.h"

void ft_stack_addback(t_data **head, t_data *node) 
{
  t_data *last_node;

  if (!head || !node)
    return;
	if (*head == NULL)
	{
		*head = node;
		return ;
	}
  last_node = *head;
  while (last_node->next)
   last_node = last_node->next;
  last_node->next = node;
}
