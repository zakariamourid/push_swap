/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmourid <zmourid@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 21:04:16 by zmourid           #+#    #+#             */
/*   Updated: 2024/06/23 21:04:38 by zmourid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	free_stack(t_data **stack)
{
	t_data	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

void	clean_exit(void)
{
	t_vars	*my_vars;

	ft_putstr_fd("Error\n", 2);
	my_vars = get_vars();
	if (my_vars->temp)
		free_split(my_vars->temp);
	if (my_vars->str)
		free(my_vars->str);
	free_ps();
	exit(0);
}

// clean_exit();
void	free_ps(void)
{
	free_stack(get_vars()->stack_a);
	free_stack(get_vars()->stack_b);
}
