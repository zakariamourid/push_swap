/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackfill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakaria <zakaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:35:50 by zakaria           #+#    #+#             */
/*   Updated: 2024/05/15 11:51:54y zakaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <limits.h>
#include <stdio.h>

static void	free_split(char **str)
{
	if(!str)
		return;
	int i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}
void clean_exit()
{
	printf("wewe\n");
	t_vars *my_vars = get_vars();
	if(my_vars->temp)
		free_split(my_vars->temp);
	if(my_vars->str)
		free(my_vars->str);
	exit(0);
}
long ft_atoi(char *str)
{
    long res;
    int signe;
    res = 0;
    signe = 1;
    while(*str && *str == ' ')
        str++;
    if(*str && (*str == '-' || *str == '+') )
    {
        if(*str == '-')
            signe = -1;
        str++;
    }
    while(*str && *str >= '0' && *str <= '9')
    {
        res = res * 10 + (*str - '0');
		if(res *signe	> INT_MAX || res * signe < INT_MIN)
		{
			clean_exit();
		}
        str++;
    }
    return res * signe;
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
void free_ps()
{
		free_stack(get_vars()->stack_a);
		free_stack(get_vars()->stack_b);
	//clean_exit();
}

int check_duplicates(char **args)
{
	int i = 0;
	int j = 0;
	while(args[i])
	{
		j = i + 1;
		while(args[j])
		{
			if(ft_atoi(args[i]) == ft_atoi(args[j]))
				return 1;
			j++;
		}
		i++;
	}
	return 0;
}

int check_forbidden(char *str)
{
  int i = 0;
if(str[i] == '-' || str[i] =='+')
	i++;
  while(str[i])
  {
	if(!ft_isdigit(str[i]))// && str[i] != ' ' && str[i] != '-')
		return 1;
	i++;
  }
  return 0;
}

int check_args(char **args)
{
	int i = 0;
	while(args[i])
	{
		if(check_forbidden(args[i]))
			return 1;
		i++;
	}
	return 0 + check_duplicates(args);
}

int check_empty(char **args,int ac)
{
	int i = 1;
	while(i < ac)
	{
		if(args[i][0] == 0)
			return 1;
		ac--;
	}
	return 0;
}

t_data **ft_stackfill(char **av,int ac,t_vars *my_vars)
{		//TODO complete this function
    t_data **head;
	int i = 0;
	head = get_stack('a');
	if(check_empty(av ,ac))
		printf("wa khoya wach nta mrid \n");
	my_vars->str = ft_strjoin_all(av+1, ac);
	if(!my_vars->str)
		return NULL;
	char **temp = ft_split(my_vars->str, ' ');
	my_vars->temp = temp;
	if( !temp || check_args(temp))
	{
		free_ps();
		free_split(temp - i);
		printf("Error\n");
		exit(1);
		return NULL;
	}
	while(*temp) {
		i++;
        ft_stack_addback(head,ft_newnode(ft_atoi(*temp++)));
	}
	free(my_vars->str);
	my_vars->str = NULL;
	free_split(temp - i);
    return head;
}
