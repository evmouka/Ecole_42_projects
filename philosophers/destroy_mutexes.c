/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mutexes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmouka <evmouka@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:56:30 by evmouka           #+#    #+#             */
/*   Updated: 2025/03/19 14:56:34 by evmouka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutexes(t_table *table, pthread_mutex_t *forks, int exit_code)
{
	int	i;

	i = 0;
	while (i < table->philo->number_of_philosophers)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	pthread_mutex_destroy(&table->dead_lock);
	pthread_mutex_destroy(&table->write_lock);
	pthread_mutex_destroy(&table->meal_lock);
	if (exit_code == 1)
		exit(1);
}
