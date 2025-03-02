/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 19:34:21 by halmuhis          #+#    #+#             */
/*   Updated: 2025/03/02 13:28:37 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

void	print_stack(t_stack *stack, char ab)
{
	t_node	*cur;

	if (!stack || stack->size == 0)
	{
		ft_putendl_fd("Stack is empty.", 1);
		return ;
	}
	cur = stack->top;
	while (cur)
	{
		printf("Top of stack_%c: %d \n", ab, cur->value);
		cur = cur->next;
	}
}

static int	*calculate_normalized_values(t_stack *stack)
{
	t_node	*current;
	t_node	*compare;
	int		*normalized;
	int		i;

	normalized = (int *)malloc(sizeof(int) * stack->size);
	if (!normalized)
		return (NULL);
	i = 0;
	current = stack->top;
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
	return (normalized);
}

static void	normalize_stack(t_stack *stack, t_stack *stackb)
{
	t_node	*current;
	int		*normalized;
	int		i;

	normalized = calculate_normalized_values(stack);
	if (!normalized)
		exit_main_error(&stack, &stackb, "Memory allocation failed");
	current = stack->top;
	i = 0;
	while (current)
	{
		current->value = normalized[i++];
		current = current->next;
	}
	free(normalized);
}

static void	fill_stack(char *argv[], t_stack **a, t_stack **b)
{
	int		i;

	*a = ft_init_stack();
	*b = ft_init_stack();
	if (!*a || !*b)
		exit_main_error(a, b, "Memory allocation failed");
	i = 0;
	while (argv[i])
		i++;
	while (--i >= 1 && argv[i])
	{
		if (!ft_push(*a, ft_atoi(argv[i])))
			exit_main_error(a, b, "Memory allocation failed");
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (0);
	validate_input(argv);
	fill_stack(argv, &stack_a, &stack_b);
	normalize_stack(stack_a, stack_b);
	if (!is_sorted(stack_a))
		sorting(&stack_a, &stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
