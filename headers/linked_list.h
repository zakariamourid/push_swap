/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmourid <zmourid@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 21:06:01 by zmourid           #+#    #+#             */
/*   Updated: 2024/06/23 21:06:02 by zmourid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_data
{
	int				value;
	struct s_data	*next;
}					t_data;

// stack functions
t_data				*ft_newnode(int num);
void				ft_stack_addback(t_data **head, t_data *node);
void				ft_stack_addfront(t_data **head, t_data *node);
int					ft_stacksize(t_data *head);
t_data				*ft_stacklast(t_data *head);
void				ft_delnode(t_data **head, int data);
