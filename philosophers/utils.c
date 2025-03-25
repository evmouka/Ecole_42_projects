/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmouka <evmouka@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:56:50 by evmouka           #+#    #+#             */
/*   Updated: 2025/03/24 23:52:13 by evmouka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		if (result > 2147483647 && sign == 1)
			return (-1);
		i++;
	}
	return (result * sign);
}

long	getcurrenttime(void)
{
	struct timeval	time;
	long			current_time;

	gettimeofday(&time, NULL);
	current_time = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (current_time);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	print_message(t_philosopher *philo, char *message)
{
	time_t	elapsed_time;

	if (check_dead_flag(philo) == 1 && ft_strncmp(message, "died", 4) != 0)
		return ;
	pthread_mutex_lock(philo->write_mutex);
	elapsed_time = getcurrenttime() - philo->start_time;
	printf("%ld %d %s\n", elapsed_time, philo->id, message);
	fflush(stdout);
	pthread_mutex_unlock(philo->write_mutex);
}

void	ft_usleep(t_philosopher *philo, int time)
{
	long	start;
	long	end;

	start = getcurrenttime();
	end = start + time;
	while (getcurrenttime() < end)
	{
		if (check_dead_flag(philo) == 1)
			break ;
		usleep(500);
	}
}
