/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 22:13:05 by halmuhis          #+#    #+#             */
/*   Updated: 2025/01/18 10:53:34 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

// Merge function to combine two sorted subarrays
void mergeStack(t_stack *stack_a, t_stack *stack_b, int start, int mid, int end)
{
    int n1 = mid - start + 1;
    int n2 = end - mid;

    // Create temporary arrays
    // int *left = (int *)malloc(n1 * sizeof(int));
    // int *right = (int *)malloc(n2 * sizeof(int));

    // Copy data to temporary arrays
    int i = 0;
    while (i < n1)
    {
        push_stack(stack_b, stack_a, 'b');
        // left[i] = arr[start + i];
        i++;
    }
    int j = 0;
    while (j < n2)
    {
        push_stack(stack_b, stack_a, 'b');
        // right[j] = arr[mid + 1 + j];
        j++;
    }
    
    while (stack_b->top)
    {
        pop_min_from_stack(stack_b, stack_a, 'b');
    }

}

//deletes the minimum value from the stack b and push it stack a
void pop_min_from_stack(t_stack *stack_b, t_stack *stack_a, char ab)
{
    if (!stack_b || stack_b->size == 0)
        return;

    t_node *current = stack_b->top;
    t_node *min_node = stack_b->top;
    int min_pos = 0, pos = 0;

    // Step 1: Find the minimum value and its position
    while (current)
    {
        if (current->value < min_node->value)
        {
            min_node = current;
            min_pos = pos;
        }
        current = current->next;
        pos++;
    }

    // Step 2: Rotate or reverse rotate to bring the min to the top
    int rotations = min_pos; // Number of rotations to bring min to the top
    if (min_pos > stack_b->size / 2)
    {
        // If closer to the bottom, reverse rotate
        rotations = stack_b->size - min_pos;
        for (int i = 0; i < rotations; i++)
            reverse_rotate_stack(stack_b, ab);
    }
    else
    {
        // If closer to the top, rotate
        for (int i = 0; i < rotations; i++)
            rotate_stack(stack_b, ab);
    }

    // Step 3: Pop the top node
    push_stack(stack_a, stack_b, ab);
}

void sort_stack(t_stack *stack) {
     t_stack *aux_stack = init_stack();

    // Sorting process
    while (stack->size > 0) {
        // Find the minimum element in the stack
        move_min_to_top(stack);

        // Push the minimum element to the auxiliary stack
        push_stack(aux_stack, stack, 'b');
    }

    // Transfer back to the original stack (now sorted in ascending order)
    while (aux_stack->size > 0) {
        push_stack(stack, aux_stack, 'a');
    }
}

t_node *new_node(int value) {
    t_node *node = (t_node *)malloc(sizeof(t_node));
    node->value = value;
    node->next = NULL;
    return node;
}


// Function to find and move the minimum element to the top
void move_min_to_top(t_stack *stack) {
    if (stack->size < 2) return;

    t_node *min_node = stack->top;
    t_node *current = stack->top->next;
    int min_value = min_node->value;
    
    // Find the minimum element
    while (current != NULL) {
        if (current->value < min_value) {
            min_value = current->value;
            min_node = current;
        }
        current = current->next;
    }

    // Move the minimum element to the top
    while (stack->top->value != min_value) {
        rotate_stack(stack, 'a');
    }
}