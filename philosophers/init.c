/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmouka <evmouka@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 23:36:34 by evmouka           #+#    #+#             */
/*   Updated: 2025/03/21 13:02:35 by evmouka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_input(t_philosopher *philo, char **argv)
{
	philo->number_of_philosophers = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		philo->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	else
		philo->number_of_times_each_philosopher_must_eat = -1;
}

void	fork_sorting(t_philosopher *philo)
{
	if (philo->id % 2 == 0)
	{
		philo->primary_fork = philo->l_fork;
		philo->secondary_fork = philo->r_fork;
	}
	else
	{
		philo->primary_fork = philo->r_fork;
		philo->secondary_fork = philo->l_fork;
	}
}

void	init_philo(t_philosopher *philo, t_table *table,
	pthread_mutex_t *forks, char **argv)
{
	int	i;
	int	num_philo;

	i = 0;
	num_philo = ft_atoi(argv[1]);
	while (i < num_philo)
	{
		philo[i].id = i + 1;
		philo[i].is_eating = 0;
		philo[i].meals_eaten = 0;
		init_input(&philo[i], argv);
		philo[i].start_time = getcurrenttime();
		philo[i].last_meal = getcurrenttime();
		philo[i].write_mutex = &table->write_lock;
		philo[i].death_mutex = &table->dead_lock;
		philo[i].meal_lock = &table->meal_lock;
		philo[i].dead = &table->dead_flag;
		philo[i].l_fork = &forks[i];
		philo[i].r_fork = &forks[(i + 1) % num_philo];
		fork_sorting(&philo[i]);
		i++;
	}
}

void	init_forks(pthread_mutex_t *forks, int num_philo)
{
	int	i;

	i = 0;
	while (i < num_philo)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	init_table(t_table *table, t_philosopher *philo)
{
	table->dead_flag = 0;
	table->philo = philo;
	pthread_mutex_init(&table->dead_lock, NULL);
	pthread_mutex_init(&table->meal_lock, NULL);
	pthread_mutex_init(&table->write_lock, NULL);
}
