// stack.h
#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
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
void free_stack(t_stack *stack);

void push_stack(t_stack *first_s, t_stack *second_s, char ab);
void swap_stack(t_stack *stack_a);
void rotate_stack(t_stack *stack_a, char ab);
void reverse_rotate_stack(t_stack *stack_a, char ab);

int get_median(t_stack *stack);
int get_abs(int num);

void mergeStack(t_stack *stack_a, t_stack *stack_b, int start, int mid, int end);
void pop_min_from_stack(t_stack *stack_b, t_stack *stack_a, char ab);
void sort_stack(t_stack *stack);
void move_min_to_top(t_stack *stack);

char **ft_split(char const *s, char c);
int	ft_atoi(const char *nptr);
int	ft_isdigit(int i);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(char const *s);


void validate_input(t_stack *a, char *argv);






#endif // STACK_H