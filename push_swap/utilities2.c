/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmouka <evmouka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:45:30 by evmouka           #+#    #+#             */
/*   Updated: 2024/06/13 15:13:16 by evmouka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	write(1, "rrr\n", 4);
}

void	init_stack(t_stack **stack, int size)
{
	(*stack) = (t_stack *)malloc(size * sizeof(t_stack));
	(*stack)->data = malloc(size * sizeof(int));
	(*stack)->top = -1;
	(*stack)->size = size;
}

int	find_min(t_stack *stack)
{
	int	i;
	int	min;
	int	min_index;

	min_index = 0;
	min = stack->data[0];
	i = 1;
	while (i <= stack->top)
	{
		if (stack->data[i] < min)
		{
			min = stack->data[i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

int	find_max(t_stack *stack)
{
	int	i;
	int	max;
	int	max_index;

	max_index = 0;
	max = stack->data[0];
	i = 1;
	while (i <= stack->top)
	{
		if (stack->data[i] > max)
		{
			max = stack->data[i];
			max_index = i;
		}
		i++;
	}
	return (max_index);
}

int	stack_sorted(t_stack *stack)
{
	int	i;

	i = stack->top;
	while (i > 0 && stack->data[i] < stack->data[i - 1])
		i--;
	if (i == 0)
		return (1);
	return (0);
}
