/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uurbizu- <uurbizu-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:00:22 by uurbizu-          #+#    #+#             */
/*   Updated: 2023/12/16 20:06:44 by uurbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*fill_stack_values(char **args)
{
	t_stack	*stack_a;
	int		*nums;
	int		i;
	int		len;

	stack_a = NULL;
	len = 0;
	i = 0;
	nums = conv_nmbrs(args, &len);
	while (i < len)
	{
		if (i == 0)
			stack_a = stack_new(nums[i]);
		else
			stack_add_bottom(&stack_a, stack_new(nums[i]));
		i++;
	}
	free (nums);
	return (stack_a);
}

void	assign_index(t_stack *stack_a, int len)
{
	t_stack	*ptr;
	t_stack	*highest;
	int		value;

	while (len > 0)
	{
		ptr = stack_a;
		value = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->value >= value && ptr->index == 0)
			{
				value = ptr->value;
				highest = ptr;
			}
			ptr = ptr->next;
		}
		highest->index = len;
		len--;
	}
}
