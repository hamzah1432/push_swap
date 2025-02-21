/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:10:01 by halmuhis          #+#    #+#             */
/*   Updated: 2025/02/21 11:35:16 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

static void push_pro_max(t_stack **a, t_stack **b)
{
    int max;
	int	pos;

    if (!*b || !(*b)->top)
    	printf("i am empty \n");
    max = ft_find_max(*a);
    printf("i am max %d \n",max);
	pos = ft_search_stack(*a, max);
    printf("i am postion %d \n",pos);
    printf("i am size %d \n",(*a)->size);

}

void sorting(t_stack **a, t_stack **b)
{
    push_pro_max(&*a, &*b);
    
}