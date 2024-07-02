/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmourid <zmourid@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:42:38 by zmourid           #+#    #+#             */
/*   Updated: 2024/07/02 13:15:14 by zmourid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adjust_stack_b(t_data **stack_b, int max)
{
	int	i;

	i = find_index(*stack_b, max);
	if (i > ft_stacksize(*stack_b) / 2)
	{
		i = ft_stacksize(*stack_b) - i;
		while (i--)
			op_rev_rotate(stack_b, "rrb");
	}
	else
	{
		while (i--)
			op_rotate(stack_b, "rb");
	}
}

void	push_back(t_data **stack_a, t_data **stack_b)
{
	int	max;

	max = find_max(*stack_b);
	while (*stack_b)
	{
		if ((*stack_b)->value == max)
		{
			op_push(stack_b, stack_a, "pa");
			max = find_max(*stack_b);
		}
		else
			adjust_stack_b(stack_b, max);
	}
}

void	update_range(int *start,
		int *end, int len)
{
	if (*end < len - 1)
		(*end)++;
	(*start)++;
}

void	push_a_to_b_helper(t_data **stack_a, t_data **stack_b, int *array,
		int len)
{
	int	start;
	int	end;

	start = 0;
	end = ft_range(len) - 1;
	while (*stack_a)
	{
		if ((*stack_a)->value >= array[start]
			&& (*stack_a)->value <= array[end])
		{
			op_push(stack_a, stack_b, "pb");
			update_range(&start, &end, len);
		}
		else if ((*stack_a)->value < array[start])
		{
			op_push(stack_a, stack_b, "pb");
			update_range(&start, &end, len);
			op_rotate(stack_b, "rb");
		}
		else
			op_rotate(stack_a, "ra");
	}
}

void	push_a_to_b(t_data **stack_a, t_data **stack_b)
{
	int	len;
	int	*array;

	len = ft_stacksize(*stack_a);
	array = stack_to_array(*stack_a);
	push_a_to_b_helper(stack_a, stack_b, array, len);
	push_back(stack_a, stack_b);
	free(array);
}
