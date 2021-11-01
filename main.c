/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongpark <jongpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 12:05:21 by jongpark          #+#    #+#             */
/*   Updated: 2021/11/01 16:25:55 by jongpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	make_rule(t_rule *rule, int argc, char **argv)
{
	int	t;

	if (argc != 5 && argc != 6)
	{
		printf("\033[31mError: invalid arguments\n\033[037m");
		return (-1);
	}
	rule->num_philo = my_atoi(argv[1], &t);
	rule->time_die = my_atoi(argv[2], &t);
	rule->time_eat = my_atoi(argv[3], &t);
	rule->time_sleep = my_atoi(argv[4], &t);
	if (argc == 6)
	{
		rule->num_eat = my_atoi(argv[5], &t);
		if (rule->num_eat < 0)
			return (-1);
	}
	else
		rule->num_eat = -42;
	if (rule->num_philo <= 0 || rule->time_die < 0
		|| rule->time_eat < 0 || rule->time_sleep < 0)
		return (-1);
	rule->is_alive = 1;
	return (0);
}

void	start_threads(t_philo *philo_t)
{
	pthread_t	tid;

	pthread_create(&tid, 0, philo, philo_t);
	philo_t->tid = tid;
	pthread_create(&tid, 0, god, philo_t);
	philo_t->god_tid = tid;
}

int	init_fork_mutex(t_rule *rule, pthread_mutex_t *alive_mutex)
{
	int	t;

	rule->forks = (pthread_mutex_t *)malloc
		(sizeof(pthread_mutex_t) * rule->num_philo);
	if (!rule->forks)
		return (-1);
	t = -1;
	while (++t < rule->num_philo)
		pthread_mutex_init(&rule->forks[t], 0);
	pthread_mutex_init(alive_mutex, 0);
	return (0);
}

void	init_philos(t_rule *rule, t_philo *philos,
				pthread_mutex_t *alive_mutex, pthread_mutex_t *print_mutex)
{
	int			t;
	time_t		start_time;

	t = -1;
	start_time = get_time_ms();
	while (++t < rule->num_philo)
	{
		philos[t].id = t;
		philos[t].time_die = rule->time_die;
		philos[t].time_eat = rule->time_eat;
		philos[t].time_sleep = rule->time_sleep;
		philos[t].start_time = start_time;
		philos[t].ate_time = philos[t].start_time;
		philos[t].remained = rule->num_eat;
		philos[t].is_alive = &(rule->is_alive);
		philos[t].left_fork = &rule->forks[t];
		philos[t].alive_mutex = alive_mutex;
		philos[t].print_mutex = print_mutex;
		if (t < rule->num_philo - 1)
			philos[t].right_fork = &rule->forks[t + 1];
		else
			philos[t].right_fork = &rule->forks[0];
		start_threads(&philos[t]);
	}
}

int	main(int argc, char **argv)
{
	t_rule			rule;
	int				t;
	t_philo			*philos;
	pthread_mutex_t	alive_mutex;
	pthread_mutex_t	print_mutex;

	if (make_rule(&rule, argc, argv) == -1
		|| init_fork_mutex(&rule, &alive_mutex) == -1)
		return (-1);
	philos = (t_philo *)malloc(sizeof(t_philo) * rule.num_philo);
	if (!philos)
		return (-1);
	init_philos(&rule, philos, &alive_mutex, &print_mutex);
	rule.philos = &philos[0];
	t = -1;
	while (++t < rule.num_philo)
	{
		pthread_join(philos[t].god_tid, 0);
		pthread_join(philos[t].tid, 0);
	}
	t = -1;
	while (++t < rule.num_philo)
		pthread_mutex_destroy(&rule.forks[t]);
	return (0);
}
