/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmourid <zmourid@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 22:42:14 by zakaria           #+#    #+#             */
/*   Updated: 2024/06/23 20:54:52 by zmourid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	op_rotate(t_data **stack, char *str)
{
	t_data	*node;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	node = (*stack);
	*stack = (*stack)->next;
	node->next = NULL;
	ft_stack_addback(stack, node);
	if (str)
		ft_putendl_fd(str, 1);
}

void	op_rr(t_data **stack_a, t_data **stack_b)
{
	op_rotate(stack_a, NULL);
	op_rotate(stack_b, "rr");
}
