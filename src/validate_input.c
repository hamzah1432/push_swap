/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:33:14 by halmuhis          #+#    #+#             */
/*   Updated: 2025/02/25 20:55:33 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

static int	is_valid_number(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] == '-' || argv[i] == '+')
		i++;
	if (!argv[i])
		return (0);
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	check_int_limits(char *argv)
{
	long	num;
	int		sign;
	int		i;

	num = 0;
	sign = 1;
	i = 0;
	if (argv[i] == '-' || argv[i] == '+')
	{
		if (argv[i] == '-')
			sign = -1;
		i++;
	}
	while (argv[i])
	{
		num = (num * 10) + (argv[i] - '0');
		if ((sign == 1 && num > INT_MAX) || (i > 14)
			|| (sign == -1 && num * sign < INT_MIN))
			return (0);
		i++;
	}
	return (1);
}

static int	check_duplicates(char *argv[])
{
	int	i;
	int	j;
	int	num1;
	int	num2;

	i = 0;
	while (argv[i])
	{
		num1 = ft_atoi(argv[i]);
		j = i + 1;
		while (argv[j])
		{
			num2 = ft_atoi(argv[j]);
			if (num1 == num2)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	validate_input(char *argv[])
{
	int		i;

	i = 0;
	while (argv[++i])
	{
		if (!is_valid_number(argv[i]))
			exit_validate_error("Invalid number format");
		else if (!check_int_limits(argv[i]))
			exit_validate_error("Out of integer range");
	}
	if (!check_duplicates(argv))
		exit_validate_error("Duplicate numbers found");
}
