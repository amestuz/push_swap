/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uurbizu- <uurbizu-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 08:52:55 by uurbizu-          #+#    #+#             */
/*   Updated: 2023/12/21 20:38:45 by uurbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new(int value)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->pos = -1;
	new->target_pos = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	return (new);
}

t_stack	*get_stack_bottom(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != 0)
	{
		lst = lst->next;
	}
	return (lst);
}

void	stack_add_bottom(t_stack **stack, t_stack *new)
{
	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	get_stack_bottom(*stack)->next = new;
}

t_stack	*get_stack_next_to_bottom(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next->next != 0)
	{
		lst = lst->next;
	}
	return (lst);
}

int	get_stack_size(t_stack	*stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}
