// stack.c
#include "stack.h"


t_stack *init_stack() {
    t_stack *stack = (t_stack *)malloc(sizeof(t_stack));
    if (!stack)
        return NULL; // Memory allocation failed
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

void push(t_stack *stack, int value) {
    t_node *new_node = (t_node *)malloc(sizeof(t_node));
    if (!new_node)
        return; // Memory allocation failed
    new_node->value = value;
    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;
}

int pop(t_stack *stack) {
    if (stack->size == 0)
        return -1; // Stack is empty (you can define an error value or handle this differently)
    t_node *temp = stack->top;
    int value = temp->value;
    stack->top = temp->next;
    free(temp);
    stack->size--;
    return value;
}

int peek(t_node *node) {
    if (node == 0)
        return -1; // Stack is empty
    return node->value;
}

void free_stack(t_stack *stack) {
    t_node *current = stack->top;
    t_node *next_node;

    while (current) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    free(stack);
}

