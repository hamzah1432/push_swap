/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 19:34:21 by halmuhis          #+#    #+#             */
/*   Updated: 2025/02/20 07:53:46 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

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

    if (argc != 2)
    {	
        ft_putendl_fd("Error: there must be one argument", 2);
        return (1);
    }
    validate_input(argv[1]);
    stack_a = init_stack();
    stack_b = init_stack();
    print_stack(stack_a, 'a');
    free_stack(stack_a);
    free_stack(stack_b);
    return 0;
}