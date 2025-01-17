/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newnode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmourid <zmourid@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 20:46:20 by zakaria           #+#    #+#             */
/*   Updated: 2024/06/23 20:52:00 by zmourid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

t_data	*ft_newnode(int num)
{
	t_data	*node;

	node = (t_data *)malloc(sizeof(t_data));
	if (!node)
		return (NULL);
	node->value = num;
	node->next = NULL;
	return (node);
}
