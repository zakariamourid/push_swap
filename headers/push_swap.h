#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

// Define ANSI color escape codes
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define RESET                                                                  \
  "\x1b[0m" // Reset to default color
            //
#include "linked_list.h"

#include "libft.h"
typedef struct s_vars
{
	char *str;
	char **args;
	char **temp;
	t_data **stack_a;
	t_data **stack_b;
} t_vars;
int op_swap(t_data **stack, char *str);
int op_ss(t_data **stack_a, t_data **stack_b);
void op_rotate(t_data **stack, char *str);
void op_rr(t_data **stack_a, t_data **stack_b);
void op_push(t_data **stack_1, t_data **stack_2, char *str);
void op_rev_rotate(t_data **stack, char *str);
void sort_three(t_data **stack);
// string functions
t_data **ft_stackfill(char **av,int ac,t_vars *my_vars);
void print_ld(t_data *head, const char *str);
t_data **get_stack(char s);
t_vars *get_vars();
void clean_exit();
char *ft_strjoin_all(char **av, int ac);
int *ft_fill_array(t_data *head);
void print_ld(t_data *head, const char *str) ;
void push_to_b(t_data **stack_a, t_data **stack_b);
void free_ps();
#endif
