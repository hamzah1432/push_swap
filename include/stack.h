// stack.h
#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "../libft/libft.h"
typedef struct s_node
{
    int value;         
    struct s_node *next; 
} t_node;

typedef struct s_stack
{
    t_node *top; 
    int size;   
} t_stack;

typedef struct s_range
{
    int start;
    int end;
} t_range;

// Function prototypes
t_stack *init_stack();
void push(t_stack *stack, int value);
int pop(t_stack *stack);
int peek(t_node *stack);

void push_stack(t_stack *first_s, t_stack *second_s, char ab);
void swap_stack(t_stack *stack_a);
void rotate_stack(t_stack *stack_a, char ab);
void reverse_rotate_stack(t_stack *stack_a, char ab);

void	free_split(char **str);
void free_stack(t_stack *stack);



void validate_input(char *argv);






#endif // STACK_H