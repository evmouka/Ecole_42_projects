/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmouka <evmouka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:31:22 by evmouka           #+#    #+#             */
/*   Updated: 2024/06/14 15:39:20 by evmouka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_destroy(t_stack *stack)
{
	free(stack->data);
	free(stack);
}

void	error_exit(int **arr)
{
	free(*arr);
	write (2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	validate_input(int argc, char **argv, int **arr)
{
	int		i;
	int		j;
	long	val;

	*arr = (int *)malloc((argc - 1) * sizeof(int));
	if (!(*arr))
		exit(EXIT_FAILURE);
	i = 0;
	while (i < argc - 1)
	{
		val = ft_atoi(argv[i + 1]);
		if (val < INT_MIN || val > INT_MAX)
			error_exit(arr);
		j = 0;
		while (j < i)
		{
			if ((*arr)[j] == val)
				error_exit(arr);
			j++;
		}
		(*arr)[i] = val;
		i++;
	}
}

void	print_stack(t_stack *stack)
{
	int	j;

	j = stack->top;
	while (j >= 0)
	{
		printf("%d ", stack->data[j]);
		j--;
	}
	printf("\n");
}

void	push(t_stack *stack, int item)
{
	stack->data[++stack->top] = item;
}
