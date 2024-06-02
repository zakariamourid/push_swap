/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakaria <zakaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 21:59:09 by zakaria           #+#    #+#             */
/*   Updated: 2024/05/29 23:02:29 by zmourid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

int op_swap(t_data **stack,char *str)
{
    if(!stack || !*stack || !(*stack)->next)
        return 0;
    t_data *node;
    node = (*stack)->next;
    (*stack)->next = node->next;
    ft_stack_addfront(stack,node);
    if(str)
        printf("%s\n",str);
    return 1;
}
int op_ss(t_data **stack_a,t_data **stack_b)
{
    op_swap(stack_a,NULL);
    op_swap(stack_b,"ss");
    return 0;
}
