/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uurbizu- <uurbizu-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 08:52:33 by uurbizu-          #+#    #+#             */
/*   Updated: 2023/12/17 21:32:07 by uurbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort_three(t_stack **stack)
{
	int		ind_max;
	t_stack	*tmp_stk;

	tmp_stk = *stack;
	ind_max = tmp_stk->index;
	while (tmp_stk)
	{
		if (tmp_stk->index > ind_max)
			ind_max = tmp_stk->index;
		tmp_stk = tmp_stk->next;
	}
	if ((*stack)->index == ind_max)
		ra(stack);
	else if ((*stack)->next->index == ind_max)
		rra(stack);
	if (!is_sorted(*stack))
		sa(stack);
	return ;
}

/* push_all_except_three:
*	Pushes all the elements of stack a into stack b, except the three last ones.
*	Pushes the smaller values first to help with sorting efficiency.
*/
static void	push_all_except_three(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	pushed;
	int	i;

	stack_size = get_stack_size(*stack_a);
	pushed = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushed < stack_size / 2)
	{
		if ((*stack_a)->index <= stack_size / 2)
		{
			pb(stack_a, stack_b);
			pushed++;
		}
		else
			ra(stack_a);
		i++;
	}
	while (stack_size - pushed > 3)
	{
		pb(stack_a, stack_b);
		pushed++;
	}
}

/* shift_stack:
*	After the bulk of the stack is sorted, shifts stack a until the lowest
*	value is at the top. If it is in the bottom half of the stack, reverse
*	rotate it into position, otherwise rotate until it is at the top of the
*	stack.
*/

static void	shift_stack(t_stack **stack_a)
{
	int	low_pos;
	int	size;

	size = get_stack_size(*stack_a);
	low_pos = get_lowest_index_position(*stack_a);
	if (low_pos > size / 2)
	{
		while (low_pos < size)
		{
			rra(stack_a);
			low_pos++;
		}
	}
	else
	{
		while (low_pos > 0)
		{
			ra(stack_a);
			low_pos--;
		}
	}
}

/* sort:
*	Sorting algorithm for a stack larger than 3.
*		Push everything but 3 numbers to stack B.
*		Sort the 3 numbers left in stack A.
*		Calculate the most cost-effective move and do it.
*		Shift elements until stack A is in order.
*/

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	push_all_except_three(stack_a, stack_b);
	sort_three(stack_a);
	while (*stack_b)
	{
		get_target_position(*stack_a, *stack_b);
		get_cost(*stack_a, *stack_b);
		cheapest_move(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		shift_stack(stack_a);
}
