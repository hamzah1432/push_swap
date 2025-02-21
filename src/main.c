/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 19:34:21 by halmuhis          #+#    #+#             */
/*   Updated: 2025/02/21 21:48:31 by halmuhis         ###   ########.fr       */
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

static void	fill_stack(char *argv, t_stack **a, t_stack **b)
{
	char	**str;
	int		i;

	*a = ft_init_stack();
	*b = ft_init_stack();
	str = ft_split(argv, ' ');
	if (!str || !*a || !*b)
		exit_main_error(str, a, b, "Memory allocation failed");
	i = 0;
	while (str[i])
		i++;
	while (--i >= 0 && str[i])
	{
		if (!ft_push(*a, ft_atoi(str[i])))
			exit_main_error(str, a, b, "Memory allocation failed");
	}
	free_split(str);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc != 2)
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	validate_input(argv[1]);
	fill_stack(argv[1], &stack_a, &stack_b);
	sorting(&stack_a, &stack_b);
	// print_stack(stack_b, 'b');
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
