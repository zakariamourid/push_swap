/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmourid <zmourid@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 20:55:32 by zmourid           #+#    #+#             */
/*   Updated: 2024/06/23 20:55:33 by zmourid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	find_max(t_data *iterator)
{
	int	max;

	max = INT_MIN;
	while (iterator)
	{
		if (iterator->value > max)
			max = iterator->value;
		iterator = iterator->next;
	}
	return ((int)max);
}

void	sort_three(t_data **stack)
{
	int	max;

	if (!stack)
		return ;
	max = find_max(*stack);
	if ((*stack)->value == max)
		op_rotate(stack, "ra");
	else if ((*stack)->next->value == max)
		op_rev_rotate(stack, "rra");
	if ((*stack)->next->value < (*stack)->value)
		op_swap(stack, "sa");
}

void	sort_four(t_data **stack_a, t_data **stack_b)
{
	int	max;

	if (!stack_a || !stack_b)
		return ;
	max = find_max(*stack_a);
	while ((*stack_a)->value != max)
	{
		if (find_index(*stack_a, max) > ft_stacksize(*stack_a) / 2)
			op_rev_rotate(stack_a, "rra");
		else
			op_rotate(stack_a, "ra");
	}
	op_push(stack_a, stack_b, "pb");
	sort_three(stack_a);
	op_push(stack_b, stack_a, "pa");
	op_rotate(stack_a, "ra");
}

void	sort_five(t_data **stack_a, t_data **stack_b)
{
	int	max;

	if (!stack_a || !stack_b)
		return ;
	max = find_max(*stack_a);
	while ((*stack_a)->value != max)
	{
		if (find_index(*stack_a, max) > ft_stacksize(*stack_a) / 2)
			op_rev_rotate(stack_a, "rra");
		else
			op_rotate(stack_a, "ra");
	}
	op_push(stack_a, stack_b, "pb");
	sort_four(stack_a, stack_b);
	op_push(stack_b, stack_a, "pa");
	op_rotate(stack_a, "ra");
}
