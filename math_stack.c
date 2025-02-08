/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:24:57 by halmuhis          #+#    #+#             */
/*   Updated: 2025/01/11 18:11:23 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int get_median(t_stack *stack)
{
    int mid;
    t_node *cur;

    if (!stack || stack->size == 0)
        return (0);
    mid = stack->size / 2;
    if (stack->size % 2 == 1)
        mid++;
    cur = stack->top;
    while (--mid)
        cur = cur->next;
    if (stack->size % 2 != 0)
        return (cur->value);
    return ((cur->value + cur->next->value) / 2);
}

int get_abs(int num)
{
    if (num < 0)
        num = num * -1;
    return num;
}