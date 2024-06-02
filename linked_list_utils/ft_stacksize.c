#include "linked_list.h"

int ft_stacksize(t_data *head)
{
    int i;
    i = 0;
    while(head)
    {
        head = head->next;
        i++;
    }
    return i;
}