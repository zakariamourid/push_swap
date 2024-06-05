#include "push_swap.h"

void	free_split(char **str)
{
	if(!str)
		return;
	int i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void free_stack(t_data **stack)
{
	t_data *tmp;
	if(!stack)
		return;
	while(*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

void clean_exit()
{
	ft_putstr_fd("Error\n",2);
	t_vars *my_vars = get_vars();
	if(my_vars->temp)
		free_split(my_vars->temp);
	if(my_vars->str)
		free(my_vars->str);
	free_ps();
	exit(0);
}
void free_ps()
{
		free_stack(get_vars()->stack_a);
		free_stack(get_vars()->stack_b);
	//clean_exit();
}