/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmouka <evmouka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:57:54 by evmouka           #+#    #+#             */
/*   Updated: 2024/06/13 16:53:56 by evmouka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index_of_target_in_b(t_stack *stack_b, int top_a)
{
	int	j;

	j = find_max(stack_b);
	if (top_a > stack_b->data[j])
		return (j);
	j--;
	if (j == -1)
		j = stack_b->top;
	while (j != find_max(stack_b) && top_a < stack_b->data[j])
	{
		j--;
		if (j == -1)
			j = stack_b->top;
	}
	return (j);
}

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->top > -1 && stack_a->top < 10)
		sort_small(stack_a, stack_b);
	else
	{
		pb(stack_a, stack_b);
		pb(stack_a, stack_b);
		move_stack_a_to_top(stack_a, stack_b);
		move_item_to_top_stack_b(stack_b, find_max(stack_b));
		while (stack_b->top > -1)
			pa(stack_a, stack_b);
	}
}
