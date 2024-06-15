/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmouka <evmouka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:15:13 by evmouka           #+#    #+#             */
/*   Updated: 2024/06/13 16:52:14 by evmouka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->top > 0)
	{
		tmp = stack->data[stack->top];
		i = stack->top;
		while (i > 0)
		{
			stack->data[i] = stack->data[i - 1];
			i--;
		}
		stack->data[0] = tmp;
		write (1, "ra\n", 3);
	}
}

void	rb(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->top > 0)
	{
		tmp = stack->data[stack->top];
		i = stack->top;
		while (i > 0)
		{
			stack->data[i] = stack->data[i - 1];
			i--;
		}
		stack->data[0] = tmp;
		write (1, "rb\n", 3);
	}
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a);
	rb(stack_b);
	write(1, "rr\n", 3);
}

void	rra(t_stack *stack)
{
	int	i;
	int	tmp;

	if (stack->top > 0)
	{
		tmp = stack->data[0];
		i = 0;
		while (i < stack->top)
		{
			stack->data[i] = stack->data[i + 1];
			i++;
		}
		stack->data[stack->top] = tmp;
		write(1, "rra\n", 4);
	}
}

void	rrb(t_stack *stack)
{
	int	i;
	int	tmp;

	if (stack->top > 0)
	{
		tmp = stack->data[0];
		i = 0;
		while (i < stack->top)
		{
			stack->data[i] = stack->data[i + 1];
			i++;
		}
		stack->data[stack->top] = tmp;
		write(1, "rrb\n", 4);
	}
}
