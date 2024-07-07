/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmourid <zmourid@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 23:07:06 by zakaria           #+#    #+#             */
/*   Updated: 2024/06/23 20:54:03 by zmourid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rev_rotate(t_data **stack, char *str)
{
	t_data	*current;
	t_data	*prev;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	current = *stack;
	while (current->next)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	ft_stack_addfront(stack, current);
	if (str)
		ft_putendl_fd(str, 1);
}

void	op_rrr(t_data **stack_a, t_data **stack_b)
{
	op_rotate(stack_a, NULL);
	op_rotate(stack_b, "rrr");
}
