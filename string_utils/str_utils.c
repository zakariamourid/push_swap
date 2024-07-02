/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmourid <zmourid@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 21:02:15 by zmourid           #+#    #+#             */
/*   Updated: 2024/06/23 21:02:16 by zmourid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

char	*ft_strjoin_all(char **av, int ac)
{
	char	*str;
	char	*tmp;
	int		i;

	i = 0;
	str = NULL;
	while (i < ac)
	{
		tmp = ft_strjoin(str, " ");
		free(str);
		str = ft_strjoin(tmp, av[i]);
		free(tmp);
		i++;
	}
	return (str);
}
