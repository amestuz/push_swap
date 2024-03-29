/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uurbizu- <uurbizu-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:43:37 by uurbizu-          #+#    #+#             */
/*   Updated: 2023/12/21 22:29:53 by uurbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void	print_2stack_pos(t_stack *stack_a, t_stack *stack_b)
{
	int		max = 0;
	int		lenb = 0;
	t_stack	*tmp_a = stack_a;
	t_stack	*tmp_b = stack_b; 
	
	while (tmp_a != NULL)
	{
		max++;
		tmp_a = tmp_a->next;
	}
	while (tmp_b != NULL)
	{
		lenb++;
		tmp_b = tmp_b->next;
	}
	if (lenb > max)
		max = lenb;
	printf("\nA\t\t[A_ind]\t\t[A_pos]\t\t[A_tgt_pos]\t\tB\t\t[i_B]\t\t
										[B_pos]\t\t[B_tgt_pos]\n\n");
	while (max > 0)
	{
		if (stack_a != NULL)
		{
			printf("%d\t\t[%d]\t\t[%d]\t\t[%d]", stack_a->value, 
							stack_a->index, stack_a->pos, stack_a->target_pos);
			stack_a = stack_a->next;
		}
		else
			printf("\t\t\t\t\t\t");
		printf("\t\t\t");
		if (stack_b != NULL)
		{
			printf("%d\t\t[%d]\t\t[%d]\t\t[%d]", stack_b->value, 
							stack_b->index, stack_b->pos, stack_b->target_pos);
			stack_b = stack_b->next;
		}
		printf("\n");
		max--;
	}
	return ;
} */

void	checker_result(t_stack **stack_a, t_stack **stack_b)
{
	if (is_sorted(*stack_a) && !(*stack_b))
		ft_putendl_fd("OK\n", 1);
	else
		ft_putendl_fd("KO\n", 1);
	free_stack(stack_a);
	free_stack(stack_b);
}

int	do_commands(char *line, t_stack **stack_a, t_stack **stack_b)
{
	if (!(ft_strncmp(line, "sa", 2)))
		return (sa(stack_a), 0);
	if (!(ft_strncmp(line, "sb", 2)))
		return (sb(stack_b), 0);
	if (!(ft_strncmp(line, "ss", 2)))
		return (ss(stack_a, stack_b), 0);
	if (!(ft_strncmp(line, "pa", 2)))
		return (pa(stack_a, stack_b), 0);
	if (!(ft_strncmp(line, "pb", 2)))
		return (pb(stack_a, stack_b), 0);
	if (!(ft_strncmp(line, "rra", 3)))
		return (rra(stack_a), 0);
	if (!(ft_strncmp(line, "rrb", 3)))
		return (rrb(stack_b), 0);
	if (!(ft_strncmp(line, "rrr", 3)))
		return (rrr(stack_a, stack_b), 0);
	if (!(ft_strncmp(line, "ra", 2)))
		return (ra(stack_a), 0);
	if (!(ft_strncmp(line, "rb", 2)))
		return (rb(stack_b), 0);
	if (!(ft_strncmp(line, "rr", 2)))
		return (rr(stack_a, stack_b), 0);
	return (1);
}

void	read_do(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while ((line))
	{
		if (do_commands(line, stack_a, stack_b))
			exit_error(stack_a, stack_b);
		free(line);
		line = get_next_line(0);
	}
	free(line);
}

int	main(int ac, char **av)
{
	char	**args;
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		len;

	if (ac < 2)
		return (0);
	args = generate_av_array(ac, av);
	len = is_not_duplicated(args);
	if (!is_numbers(args) || !(len))
	{
		free_arr(args);
		exit_error(NULL, NULL);
	}
	stack_b = NULL;
	stack_a = fill_stack_values(args);
	free_arr(args);
	read_do(&stack_a, &stack_b);
	checker_result(&stack_a, &stack_b);
	return (0);
}
