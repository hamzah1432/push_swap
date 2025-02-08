/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 19:34:21 by halmuhis          #+#    #+#             */
/*   Updated: 2025/02/08 15:15:29 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void print_stack(t_stack *stack, char ab)
{
    t_node *cur;

    if (!stack || stack->size == 0)
    {
        printf("Stack is empty.");
        return;
    }
    cur = stack->top;
    while (cur)
    {
        printf("Top of stack_%c: %d \n", ab, cur->value);
        cur = cur->next;
    }
}

int main(int argc, char *argv[])
{
    t_stack *stack_a;
    t_stack *stack_b;

    // sort_stack(stack_a);
    if (argc != 2)
    {
        return (1);
    }

    stack_a = init_stack();
    stack_b = init_stack();
    validate_input(stack_a, argv[1]);
    print_stack(stack_a, 'a');
    free_stack(stack_a);
    free_stack(stack_b);
    return 0;
}