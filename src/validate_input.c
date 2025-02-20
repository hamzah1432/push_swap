/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:33:14 by halmuhis          #+#    #+#             */
/*   Updated: 2025/02/20 08:00:53 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

static int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	check_int_limits(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	if (len > 11)
		return (0);
	if (len == 10 && str[0] != '-' && str[0] != '+')
	{
		if (ft_strncmp(str, "2147483647", 10) > 0)
			return (0);
	}
	else if (len == 11 && str[0] == '-')
	{
		if (ft_strncmp(str, "-2147483648", 11) > 0)
			return (0);
	}
	return (1);
}

static int	check_duplicates(char **str)
{
	int	i;
	int	j;
	int	num1;
	int	num2;

	i = 0;
	while (str[i])
	{
		num1 = ft_atoi(str[i]);
		j = i + 1;
		while (str[j])
		{
			num2 = ft_atoi(str[j]);
			if (num1 == num2)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static void	exit_with_error(char **str, char *msg)
{
	if (str)
		free_split(str);
	ft_putendl_fd("Error with validation", 2);
	ft_putendl_fd(msg, 2);
	exit(EXIT_FAILURE);
}

void	validate_input(char *argv)
{
	char	**str;
	int		i;

	str = ft_split(argv, ' ');
	if (!str)
		exit_with_error(NULL, "Memory allocation failed");
	i = -1;
	while (str[++i])
	{
		if (!is_valid_number(str[i]))
			exit_with_error(str, "Invalid number format");
		else if (!check_int_limits(str[i]))
			exit_with_error(str, "Out of integer range");
	}
	if (!check_duplicates(str))
		exit_with_error(str, "Duplicate numbers found");
	free_split(str);
}
