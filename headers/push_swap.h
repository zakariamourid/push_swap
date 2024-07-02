/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmourid <zmourid@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 21:06:04 by zmourid           #+#    #+#             */
/*   Updated: 2024/07/02 13:08:22 by zmourid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Define ANSI color escape codes
# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define RESET \
	"\x1b[0m" // Reset to default color
				//
# include "libft.h"
# include "linked_list.h"
# include <limits.h>

typedef struct s_vars
{
	char	*str;
	char	**args;
	char	**temp;
	t_data	**stack_a;
	int		size_a;
	t_data	**stack_b;
}			t_vars;
// operations
int			op_swap(t_data **stack, char *str);
int			op_ss(t_data **stack_a, t_data **stack_b);
void		op_rotate(t_data **stack, char *str);
void		op_rr(t_data **stack_a, t_data **stack_b);
void		op_push(t_data **stack_1, t_data **stack_2, char *str);
void		op_rev_rotate(t_data **stack, char *str);
// sorting functions
void		sort_three(t_data **stack);
void		sort_four(t_data **stack_a, t_data **stack_b);
void		sort_five(t_data **stack_a, t_data **stack_b);
int			*stack_to_array(t_data *stack);
// parsing && validations
long		ft_atoi(char *str);
int			check_empty(char **args, int ac);
int			check_duplicates(char **args);
int			check_args(char **args);
int			check_forbidden(char *str);
// string functions
t_data		**ft_stackfill(char **av, int ac, t_vars *my_vars);
void		print_ld(t_data *head, const char *str);
t_data		**get_stack(char s);
int			find_max(t_data *iterator);
t_vars		*get_vars(void);
void		clean_exit(void);
int			find_index(t_data *stack, int value);
char		*ft_strjoin_all(char **av, int ac);
int			*stack_to_array(t_data *stack);
int			ft_range(int len);
int			find_index(t_data *stack, int value);
// free functions

void		free_split(char **str);
void		clean_exit(void);
void		free_ps(void);
void		free_stack(t_data **stack);
// void print_ld(t_data *head, const char *str) ;
void		push_to_b(t_data **stack_a, t_data **stack_b);
void		push_a_to_b(t_data **stack_a, t_data **stack_b);
void		free_ps(void);
#endif
