/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:38:56 by halmuhis          #+#    #+#             */
/*   Updated: 2025/02/25 20:59:50 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

void	exit_validate_error(char *msg)
{
	ft_putendl_fd("Error with validation.c", 2);
	ft_putendl_fd(msg, 2);
	exit(EXIT_FAILURE);
}

void	exit_main_error(t_stack **a, t_stack **b, char *msg)
{
	if (*a)
		free_stack(*a);
	if (*b)
		free_stack(*b);
	ft_putendl_fd("Error with main.c", 2);
	ft_putendl_fd(msg, 2);
	exit(EXIT_FAILURE);
}

void	exit_sorting_error(t_stack **a, t_stack **b, char *msg)
{
	if (*a)
		free_stack(*a);
	if (*b)
		free_stack(*b);
	ft_putendl_fd("Error with sorting.c", 2);
	ft_putendl_fd(msg, 2);
	exit(EXIT_FAILURE);
}
