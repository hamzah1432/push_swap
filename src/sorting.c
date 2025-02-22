/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 21:01:15 by halmuhis          #+#    #+#             */
/*   Updated: 2024/01/02 21:01:15 by halmuhis         ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

static void	handle_small_sort(t_stack **stack_a)
{
	if ((*stack_a)->size <= 1)
		return ;
	if ((*stack_a)->size == 2)
	{
		if ((*stack_a)->top->value > (*stack_a)->top->next->value)
			ft_swap_stack(*stack_a);
		return ;
	}
}

static int	get_max_bits(t_stack *stack)
{
	t_node	*current;
	int		max;
	int		max_bits;

	current = stack->top;
	max = current->value;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	max_bits = 0;
	while ((stack->size - 1) >> max_bits)
		max_bits++;
	return (max_bits);
}

static void	radix_sort(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	size = a->size;
	max_bits = get_max_bits(a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((a->top->value >> i) & 1) == 1)
				ft_rotate_stack(a, 'a');
			else
				ft_push_stack(b, a, 'b');
			j++;
		}
		while (b->size > 0)
			ft_push_stack(a, b, 'a');
		i++;
	}
}

void	sorting(t_stack **stack_a, t_stack **stack_b)
{
	handle_small_sort(stack_a);
	if ((*stack_a)->size <= 2)
		return ;
	radix_sort(*stack_a, *stack_b);
}
