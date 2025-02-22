/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 21:01:15 by halmuhis          #+#    #+#             */
/*   Updated: 2025/02/23 01:32:00 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

static void normalize_stack(t_stack *stack)
{
    t_node *current;
    t_node *compare;
    int *normalized;
    int i;

    normalized = (int *)malloc(sizeof(int) * stack->size);
    if (!normalized)
        return;
    current = stack->top;
    i = 0;
    while (current)
    {
        normalized[i] = 0;
        compare = stack->top;
        while (compare)
        {
            if (current->value > compare->value)
                normalized[i]++;
            compare = compare->next;
        }
        current = current->next;
        i++;
    }
    current = stack->top;
    i = 0;
    while (current)
    {
        current->value = normalized[i++];
        current = current->next;
    }
    free(normalized);
}

static int get_max_bits(t_stack *stack)
{
    t_node *current;
    int max;
    int max_bits;

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

static void radix_sort(t_stack *a, t_stack *b)
{
    int i;
    int j;
    int size;
    int max_bits;

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

void sorting(t_stack **stack_a, t_stack **stack_b)
{
    if ((*stack_a)->size <= 1)
        return;
    
    if ((*stack_a)->size == 2)
    {
        if ((*stack_a)->top->value > (*stack_a)->top->next->value)
            ft_swap_stack(*stack_a);
        return;
    }
    
    // Normalize the stack before sorting
    normalize_stack(*stack_a);
    
    // For all other cases, use radix sort
    radix_sort(*stack_a, *stack_b);
}
