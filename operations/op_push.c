/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakaria <zakaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 23:03:33 by zakaria           #+#    #+#             */
/*   Updated: 2024/05/29 23:03:10 by zmourid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	op_push(t_data **stack_1, t_data **stack_2, char *str)
{
	if (!stack_1 || !*stack_1)
		return ;
	ft_stack_addfront(stack_2, ft_newnode((*stack_1)->value));
	ft_delnode(stack_1, (*stack_1)->value);
	if (str)
		ft_putendl_fd(str, 1);
}
