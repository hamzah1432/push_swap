/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:00:35 by halmuhis          #+#    #+#             */
/*   Updated: 2025/02/21 11:33:53 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

int	ft_search_stack(t_stack *stack, int target)
{
	t_node	*current;
	int		position;

	if (!stack || !stack->top)
		return (-1);
	current = stack->top;
	position = 0;
	while (current)
	{
		if (current->value == target)
			return (position);
		current = current->next;
		position++;
	}
	return (-1);
}

int	ft_stack_len(t_stack *stack)
{
	t_node	*current;
	int		len;

	if (!stack)
		return (0);
	current = stack->top;
	len = 0;
	while (current)
	{
		len++;
		current = current->next;
	}
	return (len);
}

int	ft_find_max(t_stack *stack)
{
	t_node	*current;
	int		max;

	if (!stack || !stack->top)
		return (0);
	current = stack->top;
	max = current->value;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

int	ft_find_prev(t_stack *stack, int num)
{
	t_node	*current;
	int		prev;

	if (!stack || !stack->top)
		return (0);
	current = stack->top;
	prev = INT_MIN;
	while (current)
	{
		if (current->value < num && current->value > prev)
			prev = current->value;
		current = current->next;
	}
	return (prev);
}
