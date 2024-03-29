/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uurbizu- <uurbizu-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:41:27 by codespace         #+#    #+#             */
/*   Updated: 2023/12/21 22:25:43 by uurbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

# include "libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

/* Frees */

void		free_stack(t_stack **stack);
void		free_arr(char **arr);
void		exit_error(t_stack **stack_a, t_stack **stack_b);

/* Input Check */

long int	ft_atoi_ps(const char *nptr);
char		**generate_av_array(int ac, char **av);
int			is_numbers(char **args);
int			*conv_nmbrs(char **args, int *len);
int			is_not_duplicated(char **args);

/* Initialize */

t_stack		*fill_stack_values(char **args);
void		assign_index(t_stack *stack_a, int len);

/* Stack Functions */

t_stack		*stack_new(int value);
t_stack		*get_stack_bottom(t_stack *lst);
void		stack_add_bottom(t_stack **stack, t_stack *new);
t_stack		*get_stack_next_to_bottom(t_stack *lst);
int			get_stack_size(t_stack	*stack);

/* Operations */

void		sa(t_stack **stack_a);
void		sb(t_stack **stack_b);
void		ss(t_stack **stack_a, t_stack **stack_b);
void		pa(t_stack **stack_a, t_stack **stack_b);
void		pb(t_stack **stack_a, t_stack **stack_b);
void		ra(t_stack **stack_a);
void		rb(t_stack **stack_b);
void		rr(t_stack **stack_a, t_stack **stack_b);
void		rra(t_stack **stack_a);
void		rrb(t_stack **stack_b);
void		rrr(t_stack **stack_a, t_stack **stack_b);

/* Sorting */

int			is_sorted(t_stack *stack);
void		sort_three(t_stack **stack);
void		sort(t_stack **stack_a, t_stack **stack_b);

/* Position */

void		get_position(t_stack *stack);
void		get_target_position(t_stack *a, t_stack *b);
int			get_lowest_index_position(t_stack *stack);

/* Cost */

void		get_cost(t_stack *stack_a, t_stack *stack_b);
void		cheapest_move(t_stack **stack_a, t_stack **stack_b);

/* Move */

void		move(t_stack **a, t_stack **b, int cost_a, int cost_b);

/* Main */

void		push_swap(t_stack **stack_a, t_stack **stack_b, int len);

/* Checker_bonus */

void		checker_result(t_stack **stack_a, t_stack **stack_b);
int			do_commands(char *line, t_stack **stack_a, t_stack **stack_b);
void		read_do(t_stack **stack_a, t_stack **stack_b);

#endif