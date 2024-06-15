/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmouka <evmouka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:13:36 by evmouka           #+#    #+#             */
/*   Updated: 2024/06/13 16:52:51 by evmouka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_min_to_top(t_stack *stack)
{
	int		min_index;
	int		pivot;

	min_index = find_min(stack);
	pivot = stack->top / 2;
	while (min_index >= 0 && min_index < stack->top)
	{
		if (min_index > pivot)
		{
			while (min_index < stack->top)
			{
				ra (stack);
				min_index++;
			}
		}
		else
		{
			while (min_index >= 0)
			{
				rra (stack);
				min_index--;
			}
		}
	}
}

void	move_max_to_top(t_stack *stack)
{
	int		max_index;
	int		pivot;

	max_index = find_max(stack);
	pivot = stack->top / 2;
	while (max_index >= 0)
	{
		if (max_index > pivot)
		{
			while (max_index < stack->top)
			{
				ra (stack);
				max_index++;
			}
		}
		else
		{
			while (max_index >= 0)
			{
				rra (stack);
				max_index--;
			}
		}
	}
}

void	move_item_to_top_stack_a(t_stack *stack, int item_index)
{
	int	pivot;

	pivot = stack->top / 2;
	if (item_index > pivot)
	{
		while (item_index < stack->top)
		{
			ra (stack);
			item_index++;
		}
	}
	else
	{
		while (item_index > -1)
		{
			rra (stack);
			item_index--;
		}
	}
}

void	move_item_to_top_stack_b(t_stack *stack, int item_index)
{
	int	pivot;

	pivot = stack->top / 2;
	if (item_index > pivot)
	{
		while (item_index < stack->top)
		{
			rb (stack);
			item_index++;
		}
	}
	else
	{
		while (item_index > -1)
		{
			rrb (stack);
			item_index--;
		}
	}
}

void	sort_three(t_stack *stack)
{
	if (stack->data[stack->top] > stack->data[stack->top -1])
	{
		if (stack->data[stack->top -1] > stack->data[stack->top -2])
		{
			ra (stack);
			sa (stack);
		}
		else if (stack->data[stack->top -1] < stack->data[stack->top -2])
		{
			if (stack->data[stack->top] > stack->data[stack->top -2])
				ra (stack);
			else if (stack->data[stack->top] < stack->data[stack->top -2])
				sa (stack);
		}
	}
	else if (stack->data[stack->top] > stack->data[stack->top -2])
		rra(stack);
	else if (stack->data[stack->top -1] > stack->data[stack->top -2])
	{
		sa (stack);
		ra (stack);
	}
}
