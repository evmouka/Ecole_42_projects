/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmouka <evmouka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:23:12 by evmouka           #+#    #+#             */
/*   Updated: 2024/06/13 15:04:56 by evmouka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct s_stack
{
	int	*data;
	int	top;
	int	size;
}					t_stack;

void	pb(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack_a, t_stack *stack_b);
void	init_stack(t_stack **stack, int size);
void	sort_three(t_stack *stack);
void	stack_destroy(t_stack *stack);
void	validate_input(int argc, char **argv, int **arr);
void	create_array(int argc, char **argv, int **arr);
void	sort_stack(t_stack *stack_a, t_stack *stack_b);
void	error_exit(void);
void	push(t_stack *stack, int item);
void	move_min_to_top(t_stack *stack);
void	sort_small(t_stack *stack_a, t_stack *stack_b);
void	move_item_to_top_stack_a(t_stack *stack, int item);
void	move_item_to_top_stack_b(t_stack *stack, int item);
void	print_stack(t_stack *stack);
void	move_target_in_stack_b_to_top(t_stack *stack_a, t_stack *stack_b);
void	move_stack_a_to_top(t_stack *stack_a, t_stack *stack_b);

int		check_duplicates(t_stack *stack);
int		is_empty(t_stack *stack);
int		stack_sorted(t_stack *stack);
int		find_min(t_stack *stack);
int		find_max(t_stack *stack);
int		ft_isdigit(int c);
int		pop(t_stack *stack);
int		calculate_cost(int index, int size);
int		find_cheapest_index_stack_a(t_stack *stack_a, t_stack *stack_b);
int		get_index_of_target_in_b(t_stack *stack_b, int top_a);

#endif