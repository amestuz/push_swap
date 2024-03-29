/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uurbizu- <uurbizu-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:55:24 by uurbizu-          #+#    #+#             */
/*   Updated: 2023/12/17 21:08:55 by uurbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_atoi_ps(const char *nptr)
{
	unsigned int	i;
	long int		num;
	long int		sign;

	i = 0;
	sign = 1;
	num = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\f' || \
			nptr[i] == '\r' || nptr[i] == '\n' || nptr[i] == '\v')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = num * 10 + (nptr[i] - '0');
		i++;
	}
	return ((long int)(num * sign));
}

char	**generate_av_array(int ac, char **av)
{
	int		i;
	char	*arx;
	char	*tmp;
	char	*tmp2;
	char	**args;

	i = 1;
	arx = ft_strdup("");
	while (i < ac)
	{
		tmp = ft_strjoin(av[i], " ");
		tmp2 = ft_strjoin(arx, tmp);
		free(arx);
		arx = ft_strdup(tmp2);
		free(tmp2);
		free(tmp);
		i++;
	}
	args = ft_split(arx, 32);
	free(arx);
	return (args);
}

int	is_numbers(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = 0;
		if (args[i][j] == '-' || args[i][j] == '+')
			j++;
		if (args[i][j] == '\0')
			return (0);
		while (args[i][j])
		{
			if (args[i][j] >= '0' && args[i][j] <= '9')
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	*conv_nmbrs(char **args, int *len)
{
	int			*nums;
	int			i;
	long int	nbr;

	i = 0;
	while (args[i])
	{
		*len = *len + 1;
		i++;
	}
	nums = calloc (*len, sizeof(int));
	i = 0;
	while (args[i])
	{
		nbr = ft_atoi_ps(args[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
		{
			free(nums);
			exit_error(NULL, NULL);
		}
		nums[i] = nbr;
		i++;
	}
	return (nums);
}

int	is_not_duplicated(char **args)
{
	int	*nums;
	int	i;
	int	j;
	int	len;

	len = 0;
	i = 0;
	nums = conv_nmbrs(args, &len);
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (nums[i] == nums[j])
			{
				free(nums);
				return (0);
			}
			j++;
		}
		i++;
	}
	free(nums);
	return (len);
}
