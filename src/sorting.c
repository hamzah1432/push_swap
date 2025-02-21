/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:10:01 by halmuhis          #+#    #+#             */
/*   Updated: 2025/02/21 21:41:59 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

static void	push_median(t_stack **a, t_stack **b)
{
	int	median;
	int	dir;

	if (!*b || !(*b)->top)
		printf("i am empty \n");
	median = ft_find_median(*a);
	dir = 0;
	if (ft_search_stack(*a, median) > (*a)->size / 2)
		dir = 1;
	while (dir && ft_peek((*a)->top) != median)
		ft_reverse_rotate_stack(*a, 'a');
	while (!dir && ft_peek((*a)->top) != median)
		ft_rotate_stack(*a, 'a');
	if (!ft_push_stack(*b, *a, 'b'))
		exit_sorting_error(&*a, &*b, "Memory allocation failed");
}

static void	push_max(t_stack **a, t_stack **b)
{
	int	max;
	int	dir;

	if (!*b || !(*b)->top)
		printf("i am empty \n");
	max = ft_find_prev(*a, ft_find_max(*b), 'u');
	dir = 0;
	if (ft_search_stack(*a, max) > (*a)->size / 2)
		dir = 1;
	while (dir && ft_peek((*a)->top) != max)
		ft_reverse_rotate_stack(*a, 'a');
	while (!dir && ft_peek((*a)->top) != max)
		ft_rotate_stack(*a, 'a');
	if (!ft_push_stack(*b, *a, 'b'))
		exit_sorting_error(&*a, &*b, "Memory allocation failed");
}

static void	push_min(t_stack **a, t_stack **b)
{
	int	min;
	int	dir;

	if (!*b || !(*b)->top)
		printf("i am empty \n");
	min = ft_find_prev(*a, ft_find_min(*b), 'l');
	dir = 0;
	if (ft_search_stack(*a, min) > (*a)->size / 2)
		dir = 1;
	while (dir && ft_peek((*a)->top) != min)
		ft_reverse_rotate_stack(*a, 'a');
	while (!dir && ft_peek((*a)->top) != min)
		ft_rotate_stack(*a, 'a');
	if (!ft_push_stack(*b, *a, 'b'))
		exit_sorting_error(&*a, &*b, "Memory allocation failed");
}

static char	most_value(t_stack *a, t_stack *b)
{
	int max;
	int	maxp;
	int	min;
	int	minp;

	max = ft_find_prev(a, ft_find_max(b), 'u');
	maxp = ft_search_stack(a, max);
	min = ft_find_prev(a, ft_find_min(b), 'l');
	minp = ft_search_stack(a, min);
	if(maxp > a->size / 2)
		maxp = maxp - a->size;
	if(minp > a->size / 2)
		minp = minp - a->size;
	if (minp - maxp > 0)
		return ('l');
	return ('m');
}


void	print_stackb(t_stack *stack, char ab)
{
	t_node	*cur;

	if (!stack || stack->size == 0)
	{
		ft_putendl_fd("Stack is empty.", 1);
		return ;
	}
	cur = stack->top;
	while (cur)
	{
		printf("Top of stack_%c: %d \n", ab, cur->value);
		cur = cur->next;
	}
}

void	sorting(t_stack **a, t_stack **b)
{
	push_median(&*a, &*b);

	while((*a)->size)
	{
		if(most_value(*a, *b) == 'm')
		{
			push_max(&*a, &*b);
			ft_rotate_stack(*b,'b');
		}
		else
			push_min(&*a, &*b);
	}
}
