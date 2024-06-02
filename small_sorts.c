#include "push_swap.h"
#include <limits.h>


int find_max(t_data **stack)
{
    t_data *iterator = *stack;
    int max = INT_MIN;
    while(iterator)
    {
        if(iterator->value > max)
            max = iterator->value;
        iterator = iterator->next;
    }
    return (int)max;
}

void sort_three(t_data **stack)
{
    if(!stack)
        return;
    int max = find_max(stack);
    if((*stack)->value == max)
        op_rotate(stack, "ra");
    else if((*stack)->next->value == max)
        op_rev_rotate(stack, "rra");
    if((*stack)->next->value < (*stack)->value)
        op_swap(stack, "sa");
}