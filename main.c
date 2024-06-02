/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakaria <zakaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:14:34 by zmourid           #+#    #+#             */
/*   Updated: 2024/05/20 13:33:06 by zmourid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int is_sorted(t_data *stack)
{
  while(stack && stack->next)
  {
    if(stack->value > stack->next->value)
      return 0;
    stack = stack->next;
  }
  return 1;
}
t_vars *get_vars()
{
	static t_vars my_vars;
	return &my_vars;

}

int main(int ac,char **av)
{
  if(ac < 2)
    return 0;
	(void)av;
	t_vars *my_vars =get_vars();
	my_vars->stack_a = ft_stackfill(av,ac,my_vars);
	if(is_sorted(*(my_vars->stack_a)))
	{
	printf(GREEN "it's sorted mate \n");
	}
	print_ld(*(my_vars->stack_a), "A");
	free_ps();
	//	push_to_b(&stack_a,&stack_b);
}
