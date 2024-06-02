/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delnode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakaria <zakaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 23:04:42 by zakaria           #+#    #+#             */
/*   Updated: 2024/05/29 23:02:04 by zmourid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void ft_delnode(t_data **head,int data)
{
    t_data *node;
    t_data *tmp;
    tmp = NULL;
    if(!head)
        return;
    node = *head;
    if(node->value == data)
    {
        (*head) = node->next;
        free(node);
        return;
    }
    while(node && node->next)
    {
        if(node->next->value == data)
        {
            tmp = node->next;
            node->next = node->next->next;
            free(tmp);
            return;
        }
        node = node->next;
    }
}
