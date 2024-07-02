/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmourid <zmourid@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 13:06:58 by zmourid           #+#    #+#             */
/*   Updated: 2024/07/02 13:15:40 by zmourid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_range(int len)
{
	if (len <= 16)
		return (3);
	else if (len <= 100)
		return (15);
	else if (len <= 500)
		return (35);
	else
		return (45);
}

int	find_index(t_data *stack, int value)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->value == value)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
}
