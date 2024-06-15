/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmouka <evmouka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:05:34 by evmouka           #+#    #+#             */
/*   Updated: 2024/06/13 16:40:57 by evmouka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->top == 1)
		ra(stack_a);
	else if (stack_a->top == 2)
	{
		sort_three(stack_a);
		return ;
	}
	while (stack_a->top > 2)
	{
		move_min_to_top(stack_a);
		pb(stack_a, stack_b);
	}
	if (!stack_sorted(stack_a))
		sort_three(stack_a);
	while (stack_b->top >= 0)
	{
		pa(stack_a, stack_b);
	}
}
