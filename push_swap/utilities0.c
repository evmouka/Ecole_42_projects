/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmouka <evmouka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:47:44 by evmouka           #+#    #+#             */
/*   Updated: 2024/06/13 16:51:46 by evmouka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->top >= 0)
	{
		stack_b->top++;
		stack_b->data[stack_b->top] = stack_a->data[stack_a->top];
		stack_a->top--;
	}
	else
		exit(EXIT_FAILURE);
	write(1, "pb\n", 3);
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->top >= 0)
	{
		stack_a->top++;
		stack_a->data[stack_a->top] = stack_b->data[stack_b->top];
		stack_b->top--;
	}
	else
		exit(EXIT_FAILURE);
	write(1, "pa\n", 3);
}

void	sa(t_stack *stack)
{
	int	tmp;

	if (stack->top > 0)
	{
		tmp = stack->data[stack->top];
		stack->data[stack->top] = stack->data[stack->top -1];
		stack->data[stack->top -1] = tmp;
	}
	write(1, "sa\n", 3);
}

void	sb(t_stack *stack) // swap the top two elements of stack b
{
	int	tmp;

	if (stack->data[stack->top] > 0)
	{
		tmp = stack->data[stack->top];
		stack->data[stack->top] = stack->data[stack->top -1];
		stack->data[stack->top -1] = tmp;
	}
	write(1, "sb\n", 3);
}

void	ss(t_stack *stack_a, t_stack *stack_b) // sa and sb at the same time
{
	sa(stack_a);
	sb(stack_b);
	write(1, "ss\n", 3);
}
