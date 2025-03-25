/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmouka <evmouka@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 23:42:14 by evmouka           #+#    #+#             */
/*   Updated: 2025/03/24 23:30:19 by evmouka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>

# define PHILO_MAX 200
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define RESET "\033[0m"

typedef struct s_philosopher
{
	pthread_t		thread;
	int				id;
	int				number_of_philosophers;
	int				is_eating;
	int				meals_eaten;
	int				number_of_times_each_philosopher_must_eat;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	int				*dead;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*primary_fork;
	pthread_mutex_t	*secondary_fork;
	pthread_mutex_t	*write_mutex;
	pthread_mutex_t	*death_mutex;
	pthread_mutex_t	*meal_lock;
}				t_philosopher;

typedef struct s_table
{
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	t_philosopher	*philo;
}			t_table;

int		is_numeric(char *str);
int		is_valid_input(char **argv);
void	init_input(t_philosopher *philo, char **argv);
void	init_table(t_table *table, t_philosopher *philos);
void	init_philo(t_philosopher *philo, t_table *table,
			pthread_mutex_t *forks, char **argv);
void	init_forks(pthread_mutex_t *forks, int num_philo);
int		ft_atoi(const char *str);
long	getcurrenttime(void);
void	print_message(t_philosopher *philo, char *message);
void	ft_usleep(t_philosopher *philo, int time);
void	routine(t_philosopher *philo);
void	eating(t_philosopher *philo);
void	sleeping(t_philosopher *philo);
void	thinking(t_philosopher *philo);
void	*death_monitor(void *death_monitor);
void	create_threads(t_table *table, pthread_mutex_t *forks);
void	create_philosopher_threads(t_table *table, pthread_mutex_t *forks);
void	destroy_mutexes(t_table *table, pthread_mutex_t *forks, int exit_code);
int		check_dead_flag(t_philosopher *philo);
int		philo_has_died(t_philosopher *philo);
int		all_meals_eaten(t_philosopher *philo);
void	*philo_routine(void *philo);
void	destroy_mutexes(t_table *table, pthread_mutex_t *forks, int exit_code);
void	set_dead_flag(t_table *table);
void	*death_monitor(void *death_monitor);
void	fork_sorting(t_philosopher *philo);

#endif