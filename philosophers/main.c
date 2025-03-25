/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmouka <evmouka@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 23:40:10 by evmouka           #+#    #+#             */
/*   Updated: 2025/03/24 23:47:43 by evmouka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_input(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		long long int	num;

		num = ft_atoi(argv[i]);
		if (!is_numeric(argv[i]))
			return (0);
		if (num < 0 || num > INT_MAX)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_table			table;
	t_philosopher	philos[PHILO_MAX];
	pthread_mutex_t	forks[PHILO_MAX];

	if (argc < 5 || argc > 6)
	{
		printf("Error: invalid number of arguments\n");
		return (1);
	}
	if (!is_valid_input(argv))
	{
		printf("Error: invalid argument\n");
		return (1);
	}
	init_table(&table, philos);
	init_forks(forks, ft_atoi(argv[1]));
	init_philo(philos, &table, forks, argv);
	printf("Starting simulation with %d philosophers\n", ft_atoi(argv[1]));
	fflush(stdout);
	create_threads(&table, forks);
	destroy_mutexes(&table, forks, 0);
	return (0);
}
