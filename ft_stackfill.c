/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackfill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmourid <zmourid@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 21:05:01 by zmourid           #+#    #+#             */
/*   Updated: 2024/06/23 21:07:45 by zmourid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <limits.h>
#include <stdio.h>

t_data	**ft_stackfill(char **av, int ac, t_vars *my_vars)
{
	t_data	**head;
	t_data	*tmp;
	char	**temp;

	head = get_stack('a');
	if (check_empty(av, ac))
		clean_exit();
	my_vars->str = ft_strjoin_all(av + 1, ac);
	if (!my_vars->str)
		return (NULL);
	temp = ft_split(my_vars->str, ' ');
	my_vars->temp = temp;
	if (!temp || check_args(temp))
		clean_exit();
	while (*temp)
	{
		tmp = ft_newnode(ft_atoi(*temp++));
		if (!tmp)
			clean_exit();
		ft_stack_addback(head, tmp);
	}
	free(my_vars->str);
	free_split(my_vars->temp);
	return (head);
}
