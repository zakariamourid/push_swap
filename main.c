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
t_data **get_stack(char s)
{
	static t_data *stack_a;
	static t_data *stack_b;
	if(s == 'a')
		return &stack_a;
	return &stack_b;
}

void sort_two(t_data **stack)
{
	if((*stack) && (*stack)->next && (*stack)->value > (*stack)->next->value)
		op_swap(stack,"sa");
}
int main(int ac,char **av)
{
  if(ac < 2)
    return 0;
	t_vars *my_vars = get_vars();
	my_vars->stack_a = ft_stackfill(av,ac,my_vars);
	if(!my_vars->stack_a)
		return 0;
	my_vars->size_a = ft_stacksize(*(my_vars->stack_a));
	my_vars->stack_b = get_stack('b');
	if(is_sorted(*(my_vars->stack_a)))
		return 0;
	if(my_vars->size_a == 2)
		sort_two(my_vars->stack_a);
	else if(my_vars->size_a == 3)
		sort_three(my_vars->stack_a);
	else if(my_vars->size_a == 4)
		sort_four(my_vars->stack_a,my_vars->stack_b);
	else if(my_vars->size_a == 5)
		sort_five(my_vars->stack_a,my_vars->stack_b);
	else
	push_a_to_b(my_vars->stack_a,my_vars->stack_b);
	//print_ld(*(my_vars->stack_a), "A");
	free_ps();
}
