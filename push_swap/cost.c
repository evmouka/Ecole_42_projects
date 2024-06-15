/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmouka <evmouka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:58:49 by evmouka           #+#    #+#             */
/*   Updated: 2024/06/13 15:00:00 by evmouka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_cost(int index, int size)
{
	if (index >= size / 2)
		return (size - index);
	return (index + 1);
}

static int	find_cost_stack_b(t_stack *stack_a, t_stack *stack_b, int i)
{
	int	j;

	j = find_max(stack_b);
	if (stack_a->data[i] > stack_b->data[j])
		return (calculate_cost(j, stack_b->top));
	j--;
	if (j == -1)
		j = stack_b->top;
	while (j != find_max(stack_b) && stack_a->data[i] < stack_b->data[j])
	{
		j--;
		if (j == -1)
			j = stack_b->top;
	}
	return (calculate_cost(j, stack_b->top));
}

int	find_cheapest_index_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	cost;
	int	best_cost;
	int	cost_index;

	i = stack_a->top;
	best_cost = INT_MAX;
	while (i > -1)
	{
		cost = calculate_cost(i, stack_a->top);
		cost += find_cost_stack_b(stack_a, stack_b, i);
		if (cost < best_cost)
		{
			best_cost = cost;
			cost_index = i;
		}
		i--;
	}
	return (cost_index);
}

void	move_target_in_stack_b_to_top(t_stack *stack_a, t_stack *stack_b)
{
	int	j;

	j = get_index_of_target_in_b(stack_b, stack_a->data[stack_a->top]);
	move_item_to_top_stack_b(stack_b, j);
}

void	move_stack_a_to_top(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	while (stack_a->top > -1)
	{
		i = find_cheapest_index_stack_a(stack_a, stack_b);
		move_item_to_top_stack_a(stack_a, i);
		move_target_in_stack_b_to_top(stack_a, stack_b);
		pb(stack_a, stack_b);
	}
}
