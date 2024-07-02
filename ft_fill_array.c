/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmourid <zmourid@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 20:57:18 by zmourid           #+#    #+#             */
/*   Updated: 2024/06/23 20:57:39 by zmourid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bubble_sort(int *array, int len)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int	*stack_to_array(t_data *stack)
{
	int	*arr;
	int	i;
	int	size;

	i = 0;
	size = ft_stacksize(stack);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	while (stack)
	{
		arr[i++] = stack->value;
		stack = stack->next;
	}
	ft_bubble_sort(arr, size);
	return (arr);
}
