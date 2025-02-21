/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 10:00:00 by halmuhis          #+#    #+#             */
/*   Updated: 2025/02/21 08:41:47 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>
# include "../libft/libft.h"

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

typedef struct s_range
{
	int	start;
	int	end;
}	t_range;

/* Stack initialization and basic operations */
t_stack	*ft_init_stack(void);
int		ft_push(t_stack *stack, int value);
int		ft_pop(t_stack *stack);
int		ft_peek(t_node *stack);

/* Stack manipulation operations */
void	ft_push_stack(t_stack *first_s, t_stack *second_s, char ab);
void	ft_swap_stack(t_stack *stack_a);
void	ft_rotate_stack(t_stack *stack_a, char ab);
void	ft_reverse_rotate_stack(t_stack *stack_a, char ab);

/* Memory management */
void	free_split(char **str);
void	free_stack(t_stack *stack);

/* Input validation */
void	validate_input(char *argv);

#endif