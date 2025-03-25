/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmouka <evmouka@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:53:23 by evmouka           #+#    #+#             */
/*   Updated: 2025/03/21 11:29:47 by evmouka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_dead_flag(t_table *table)
{
	pthread_mutex_lock(&table->dead_lock);
	table->dead_flag = 1;
	pthread_mutex_unlock(&table->dead_lock);
}

int	philo_has_died(t_philosopher *philo)
{
	size_t	elapsed_time;
	int		is_eating;

	pthread_mutex_lock(philo->meal_lock);
	elapsed_time = getcurrenttime() - philo->last_meal;
	is_eating = philo->is_eating;
	pthread_mutex_unlock(philo->meal_lock);
	if (is_eating == 1)
		return (0);
	if (elapsed_time > philo->time_to_die)
	{
		pthread_mutex_lock(philo->death_mutex);
		if (*philo->dead == 0)
		{
			*philo->dead = 1;
			printf("%ld %d died\n",
				getcurrenttime() - philo->start_time, philo->id);
			fflush(stdout);
		}
		pthread_mutex_unlock(philo->death_mutex);
		return (1);
	}
	return (0);
}

int	all_meals_eaten(t_philosopher *philo)
{
	int	all_meals_eaten;
	int	i;

	if (philo->number_of_times_each_philosopher_must_eat == 0)
		return (1);
	all_meals_eaten = 1;
	i = 0;
	pthread_mutex_lock(philo->meal_lock);
	while (i < philo->number_of_philosophers)
	{
		if (philo[i].number_of_times_each_philosopher_must_eat > 0
			&& philo[i].meals_eaten
			< philo[i].number_of_times_each_philosopher_must_eat)
		{
			all_meals_eaten = 0;
			break ;
		}
		i++;
	}
	pthread_mutex_unlock(philo->meal_lock);
	return (all_meals_eaten);
}

int	meal_quota_complete(t_table *table)
{
	if (table->philo[0].number_of_times_each_philosopher_must_eat < 0)
		return (0);
	if (all_meals_eaten(table->philo) == 1)
	{
		usleep(10000);
		set_dead_flag(table);
		return (1);
	}
	return (0);
}

void	*death_monitor(void *agent)
{
	t_table	*table;
	int		i;

	table = (t_table *)agent;
	usleep(1000);
	while (1)
	{
		i = 0;
		while (i < table->philo->number_of_philosophers)
		{
			if (philo_has_died(&table->philo[i]))
			{
				set_dead_flag(table);
				return (NULL);
			}
			i++;
			usleep(50);
		}
		if (meal_quota_complete(table))
			return (NULL);
		usleep(200);
	}
	return (NULL);
}
