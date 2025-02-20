/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 21:01:15 by halmuhis          #+#    #+#             */
/*   Updated: 2025/02/20 07:06:32 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

/* Function to swap the first two elements at the top of stack */
void swap_stack(t_stack *stack_a)
{
    if (stack_a == NULL || stack_a->size < 2)
        return;
    t_node *first = stack_a->top;
    t_node *second = first->next;

    first->next = second->next;
    second->next = first;
    stack_a->top = second;
    write(1, "sa\n", 3);
}

/* Function to push the top element of second_s onto first_s */
void push_stack(t_stack *first_s, t_stack *second_s, char ab)
{
    if (second_s == NULL || second_s->size == 0)
        return;
    int value = pop(second_s);
    push(first_s, value);
    if (ab == 'b')
        write(1, "pb\n", 3);
    else
        write(1, "pa\n", 3);
}

/* Function to rotate stack: Shift up all elements by 1. The first element becomes the last one. */
void rotate_stack(t_stack *stack_a, char ab)
{
    if (stack_a == NULL || stack_a->size < 2)
        return;
    t_node *first = stack_a->top;
    stack_a->top = first->next;

    t_node *last = stack_a->top;
    while (last->next != NULL)
        last = last->next;
    last->next = first;
    first->next = NULL;
    if (ab == 'a')
        write(1, "ra\n", 3);
    else
        write(1, "rb\n", 3);
}

/* Function to reverse rotate stack a: Shift down all elements by 1. The last element becomes the first one. */
void reverse_rotate_stack(t_stack *stack_a, char ab)
{
    if (stack_a == NULL || stack_a->size < 2)
        return;
    t_node *second_last = stack_a->top;
    while (second_last->next != NULL && second_last->next->next != NULL)
        second_last = second_last->next;

    t_node *last = second_last->next;
    second_last->next = NULL;

    last->next = stack_a->top;
    stack_a->top = last;
    if (ab == 'a')
        write(1, "rra\n", 4);
    else
        write(1, "rrb\n", 4);
}
