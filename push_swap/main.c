/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmouka <evmouka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:31:07 by evmouka           #+#    #+#             */
/*   Updated: 2024/06/13 14:57:11 by evmouka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		*arr;
	int		size;
	int		i;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc <= 1)
		exit(EXIT_FAILURE);
	size = argc - 1;
	arr = NULL;
	validate_input(argc, argv, &arr);
	init_stack(&stack_a, size);
	init_stack(&stack_b, size);
	i = size - 1;
	while (i >= 0)
	{
		push(stack_a, arr[i]);
		i--;
	}
	if (!stack_sorted(stack_a))
		sort_stack(stack_a, stack_b);
	stack_destroy(stack_a);
	stack_destroy(stack_b);
	free(arr);
	return (0);
}
