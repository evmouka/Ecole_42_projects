/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmouka <evmouka@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 23:50:30 by evmouka           #+#    #+#             */
/*   Updated: 2025/03/21 13:04:29 by evmouka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_dead_flag(t_philosopher *philo)
{
	int	dead;

	pthread_mutex_lock(philo->death_mutex);
	dead = *philo->dead;
	if (dead == 1)
	{
		pthread_mutex_unlock(philo->death_mutex);
		return (1);
	}
	pthread_mutex_unlock(philo->death_mutex);
	return (dead);
}

void	routine(t_philosopher *philo)
{
	if (philo->id % 2 == 0)
	{
		thinking(philo);
		ft_usleep(philo, 2);
	}
	while (!check_dead_flag(philo))
	{
		eating(philo);
		if (check_dead_flag(philo) == 1)
			break ;
		sleeping(philo);
		if (check_dead_flag(philo) == 1)
			break ;
		thinking(philo);
	}
}

void	create_philosopher_threads(t_table *table, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < table->philo->number_of_philosophers)
	{
		if (pthread_create(&table->philo[i].thread, NULL,
				(void *)routine, &table->philo[i]) != 0)
		{
			printf("Error creating thread\n");
			destroy_mutexes(table, forks, 1);
		}
		if (table->philo->number_of_philosophers > 50)
			usleep(100);
		i++;
	}
}

void	create_threads(t_table *table, pthread_mutex_t *forks)
{
	int			i;
	pthread_t	death_monitor_thread;

	if (pthread_create(&death_monitor_thread, NULL, death_monitor, table) != 0)
	{
		printf("Error creating thread\n");
		destroy_mutexes(table, forks, 1);
	}
	create_philosopher_threads(table, forks);
	if (pthread_join(death_monitor_thread, NULL))
	{
		printf("Error joining thread\n");
		destroy_mutexes(table, forks, 1);
	}
	i = 0;
	while (i < table->philo->number_of_philosophers)
	{
		if (pthread_join(table->philo[i].thread, NULL))
		{
			printf("Error joining thread\n");
			destroy_mutexes(table, forks, 1);
		}
		i++;
	}
}
