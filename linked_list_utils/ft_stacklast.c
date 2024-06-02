#include "linked_list.h"

t_data *ft_stacklast(t_data *head)
{
    if(!head)
        return NULL;
    while(head->next)
        head = head->next;
    return head;
}