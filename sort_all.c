#include "push_swap.h"

int ft_range(int len)
{
	if(len <= 16)
		return 3;
	else if(len <= 100)
		return 15;
	else if(len <= 500)
		return 35;
	else
		return 45;
}
int find_index(t_data *stack,int value)
{
	int i = 0;
	while(stack)
	{
		if(stack->value == value)
			return i;
		stack = stack->next;
		i++;
	}
	return -1;
}

void push_back(t_data **stack_a, t_data **stack_b)
{
	int max;
	int i;
	max = find_max(*stack_b);
	i = 0;
	while(*stack_b)
	{
		if((*stack_b)->value == max)
		{
			op_push(stack_b,stack_a,"pa");
			max = find_max(*stack_b);
		}
		else
		{
			i  = find_index(*stack_b,max);
			if(i > ft_stacksize(*stack_b) / 2)
			{
				i = ft_stacksize(*stack_b) - i;
				while(i--)
					op_rev_rotate(stack_b, "rrb");
			}
			else
			{
				while(i--)
					op_rotate(stack_b,"rb");
			}
		}
	}
}
void push_a_to_b(t_data **stack_a, t_data **stack_b)
{
	int len;
	len = ft_stacksize(*stack_a);
	int *array = stack_to_array(*stack_a);
					
	int start;
	start = 0;
	int end = ft_range(len) - 1;
	while(*stack_a)
	{
		if((*stack_a)->value >= array[start] && (*stack_a)->value <= array[end])
		{
			op_push(stack_a,stack_b,"pb");
			if(end < len - 1)
				end++;
			start++;
		}
		else if((*stack_a)->value < array[start])
		{
			op_push(stack_a,stack_b,"pb");
			op_rotate(stack_b,"rb");
			if(end < len - 1)
				end++;
			start++;
		}
		else
			op_rotate(stack_a,"ra");
	}
	push_back(stack_a,stack_b);
	//print_ld(*stack_a,"A");
	free(array);
}
