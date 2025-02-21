/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:00:35 by halmuhis          #+#    #+#             */
/*   Updated: 2025/02/21 21:34:53 by halmuhis         ###   ########.fr       */
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

int	ft_find_min(t_stack *stack)
{
	t_node	*current;
	int		min;

	if (!stack || !stack->top)
		return (0);
	current = stack->top;
	min = current->value;
	while (current)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

int	ft_find_prev(t_stack *stack, int num, char status)
{
	t_node	*current;
	int		prev;

	if (!stack || !stack->top)
		return (0);
	current = stack->top;
	prev = INT_MIN;
	if (status == 'l')
		prev = INT_MAX;
	while (current)
	{
		if (status == 'u' && current->value < num && current->value > prev)
			prev = current->value;
		if (status == 'l' && current->value > num && current->value < prev)
			prev = current->value;
		current = current->next;
	}
	return (prev);
}

int	ft_find_median(t_stack *stack)
{
	t_node	*current;
	t_node	*temp;
	int		count;
	int		target;

	if (!stack || !stack->top)
		return (0);
	target = stack->size / 2;
	current = stack->top;
	while (current)
	{
		count = 0;
		temp = stack->top;
		while (temp)
		{
			if (temp->value < current->value)
				count++;
			temp = temp->next;
		}
		if (count == target)
			return (current->value);
		current = current->next;
	}
	return (current->value);
}
