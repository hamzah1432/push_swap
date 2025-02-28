/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 21:01:15 by halmuhis          #+#    #+#             */
/*   Updated: 2024/01/02 21:01:15 by halmuhis         ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

static int	find_min_position(t_stack *stack)
{
	t_node	*current;
	int		min;
	int		pos;
	int		min_pos;

	current = stack->top;
	min = current->value;
	pos = 0;
	min_pos = 0;
	while (current)
	{
		if (current->value < min)
		{
			min = current->value;
			min_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (min_pos);
}

static void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->top->value;
	second = (*a)->top->next->value;
	third = (*a)->top->next->next->value;
	if (first > second && second < third && first < third)
		ft_swap_stack(*a);
	else if (first > second && second > third)
	{
		ft_swap_stack(*a);
		ft_reverse_rotate_stack(*a, 'a');
	}
	else if (first > second && second < third && first > third)
		ft_rotate_stack(*a, 'a');
	else if (first < second && second > third && first < third)
	{
		ft_swap_stack(*a);
		ft_rotate_stack(*a, 'a');
	}
	else if (first < second && second > third && first > third)
		ft_reverse_rotate_stack(*a, 'a');
}

static void	sort_four(t_stack **a, t_stack **b)
{
	int	min_pos;

	min_pos = find_min_position(*a);
	if (min_pos == 1)
		ft_swap_stack(*a);
	else if (min_pos == 2)
	{
		ft_rotate_stack(*a, 'a');
		ft_rotate_stack(*a, 'a');
	}
	else if (min_pos == 3)
		ft_reverse_rotate_stack(*a, 'a');
	ft_push_stack(*b, *a, 'b');
	sort_three(a);
	ft_push_stack(*a, *b, 'a');
}

static void	sort_five(t_stack **a, t_stack **b)
{
	int	min_pos;

	min_pos = find_min_position(*a);
	if (min_pos == 1)
		ft_swap_stack(*a);
	else if (min_pos == 2)
	{
		ft_rotate_stack(*a, 'a');
		ft_rotate_stack(*a, 'a');
	}
	else if (min_pos == 3)
	{
		ft_reverse_rotate_stack(*a, 'a');
		ft_reverse_rotate_stack(*a, 'a');
	}
	else if (min_pos == 4)
		ft_reverse_rotate_stack(*a, 'a');
	ft_push_stack(*b, *a, 'b');
	sort_four(a, b);
	ft_push_stack(*a, *b, 'a');
}

void	small_sort(t_stack **a, t_stack **b)
{
	if ((*a)->size == 2)
	{
		if ((*a)->top->value > (*a)->top->next->value)
			ft_swap_stack(*a);
	}
	else if ((*a)->size == 3)
		sort_three(a);
	else if ((*a)->size == 4)
		sort_four(a, b);
	else if ((*a)->size == 5)
		sort_five(a, b);
}
