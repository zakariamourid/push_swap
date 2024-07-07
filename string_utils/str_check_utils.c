/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmourid <zmourid@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 21:02:22 by zmourid           #+#    #+#             */
/*   Updated: 2024/07/02 13:19:42 by zmourid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(char *str)
{
	long	res;
	int		signe;

	res = 0;
	signe = 1;
	while (*str && *str == ' ')
		str++;
	if (*str && (*str == '-' || *str == '+'))
	{
		if (*str == '-')
			signe = -1;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		if (res * signe > INT_MAX || res * signe < INT_MIN)
		{
			clean_exit();
		}
		str++;
	}
	return (res * signe);
}

int	check_duplicates(char **args)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (args[i])
	{
		j = i + 1;
		while (args[j])
		{
			if (ft_atoi(args[i]) == ft_atoi(args[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_forbidden(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (1);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	check_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (check_forbidden(args[i]))
			return (1);
		i++;
	}
	return (0 + check_duplicates(args));
}

// check if string is only spaces
int	check_empty(char **args, int ac)
{
	int		i;
	char	**str;

	i = 1;
	while (i < ac)
	{
		str = ft_split(args[i], ' ');
		if (!str)
			return (1);
		if (!str[0])
			return (free(str), 1);
		free_split(str);
		i++;
	}
	return (0);
}
