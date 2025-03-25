/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmouka <evmouka@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 23:45:32 by evmouka           #+#    #+#             */
/*   Updated: 2025/03/21 13:05:09 by evmouka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thinking(t_philosopher *philo)
{
	print_message(philo, "is thinking");
}

void	sleeping(t_philosopher *philo)
{
	if (philo->is_eating == 0)
	{
		print_message(philo, "is sleeping");
		ft_usleep(philo, philo->time_to_sleep);
	}
}

void	eating(t_philosopher *philo)
{
	pthread_mutex_lock(philo->primary_fork);
	print_message(philo, "has taken a fork");
	if (check_dead_flag(philo) == 1 || philo->number_of_philosophers == 1)
	{
		if (philo->number_of_philosophers == 1)
			ft_usleep(philo, philo->time_to_die);
		pthread_mutex_unlock(philo->primary_fork);
		return ;
	}
	pthread_mutex_lock(philo->secondary_fork);
	print_message(philo, "has taken a fork");
	pthread_mutex_lock(philo->meal_lock);
	philo->is_eating = 1;
	philo->last_meal = getcurrenttime();
	pthread_mutex_unlock(philo->meal_lock);
	print_message(philo, "is eating");
	ft_usleep(philo, philo->time_to_eat);
	pthread_mutex_lock(philo->meal_lock);
	philo->meals_eaten++;
	philo->is_eating = 0;
	pthread_mutex_unlock(philo->meal_lock);
	pthread_mutex_unlock(philo->secondary_fork);
	pthread_mutex_unlock(philo->primary_fork);
}
