/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:10:01 by halmuhis          #+#    #+#             */
/*   Updated: 2025/02/21 19:47:00 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

static void	push_pro_max(t_stack **a, t_stack **b)
{
	int	max;
	int	dir;

	if (!*b || !(*b)->top)
		printf("i am empty \n");
	max = ft_find_max(*a);
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

void	sorting(t_stack **a, t_stack **b)
{
	push_pro_max(&*a, &*b);
}
