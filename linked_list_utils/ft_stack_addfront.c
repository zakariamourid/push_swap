/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_addfront.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmourid <zmourid@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 20:52:16 by zmourid           #+#    #+#             */
/*   Updated: 2024/06/23 20:52:17 by zmourid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	ft_stack_addfront(t_data **head, t_data *node)
{
	if (!head || !node)
		return ;
	node->next = *head;
	*head = node;
}
