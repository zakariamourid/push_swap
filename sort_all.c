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
	free(array);

}
void push_to_b(t_data **stack_a, t_data **stack_b)
{
	int len = ft_stacksize(*stack_a);
	int *array = stack_to_array(*stack_a);
	int start = 0;	
	int end  = ft_range(len) - 1;
	if(!stack_a || !*stack_a)
		return;
	while(*stack_a)
	{
		if((*stack_a)->value <= array[end])
			op_push(stack_a,stack_b,"pb");
		else if((*stack_a)->value < array[start])
		{
			op_push(stack_a,stack_b,"pb");
			op_rotate(stack_b,"rb");
		}
		else
		{
			op_rotate(stack_a,"ra");
			continue;
		}
		if(end < len -1)
			end++;
		start++;
	}
	//print_ld(*stack_b, "stack b");
}
