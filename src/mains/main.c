/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uurbizu- <uurbizu-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:44:02 by uurbizu-          #+#    #+#             */
/*   Updated: 2023/12/21 10:34:03 by uurbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**************** funciones para imprimir stacks ********************

void	print_stack(t_stack *stack)
{
	while (stack != NULL)
	{
		printf("%d [%d]\n", stack->value, stack->index);
		stack = stack->next;
	}
	return ;
}

void	print_2stack(t_stack *stack_a, t_stack *stack_b)
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
	printf("\nA\t\t[i_A]\t\tB\t\t[i_B]\n\n");
	while (max > 0)
	{
		if (stack_a != NULL)
		{
			printf("%d\t\t[%d]", stack_a->value, stack_a->index);
			stack_a = stack_a->next;
		}
		else
			printf("\t\t");
		printf("\t\t");
		if (stack_b != NULL)
		{
			printf("%d\t\t[%d]", stack_b->value, stack_b->index);
			stack_b = stack_b->next;
		}
		printf("\n");
		max--;
	}
	return ;
}*/

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
	printf("\nA\t\t[A_ind]\t\t[A_pos]\t\t[A_tgt_pos]\t\tB\t\t[i_B]
												\t\t[B_pos]\t\t[B_tgt_pos]\n\n");
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

void	push_swap(t_stack **stack_a, t_stack **stack_b, int len)
{
	if (is_sorted(*stack_a))
		return ;
	else if (len == 2)
		sa(stack_a);
	else if (len == 3)
		sort_three(stack_a);
	else
		sort(stack_a, stack_b);
	return ;
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
	assign_index(stack_a, len);
	push_swap(&stack_a, &stack_b, len);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
