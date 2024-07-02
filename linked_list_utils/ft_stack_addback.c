/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_addback.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmourid <zmourid@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 20:46:25 by zakaria           #+#    #+#             */
/*   Updated: 2024/06/23 20:51:57 by zmourid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	ft_stack_addback(t_data **head, t_data *node)
{
	t_data	*last_node;

	if (!head || !node)
		return ;
	if (*head == NULL)
	{
		*head = node;
		return ;
	}
	last_node = *head;
	while (last_node->next)
		last_node = last_node->next;
	last_node->next = node;
}
