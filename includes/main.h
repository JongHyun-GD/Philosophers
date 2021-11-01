/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyun <hyun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 12:10:03 by jongpark          #+#    #+#             */
/*   Updated: 2021/10/31 13:46:26 by hyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <time.h>
# include <sys/time.h>
# include <string.h>
# include "utils.h"

typedef struct s_philo
{
	pthread_t		tid;
	pthread_t		god_tid;
	int				id;
	time_t			start_time;
	time_t			ate_time;
	time_t			time_die;
	time_t			time_eat;
	time_t			time_sleep;
	int				remained;
	int				*is_alive;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*alive_mutex;
	pthread_mutex_t *print_mutex;
}					t_philo;

typedef struct s_rule
{
	int				num_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				num_eat;
	pthread_mutex_t	*forks;
	t_philo			*philos;
	int				is_alive;
}					t_rule;

int		philo_take_fork(t_philo *ptr);
int		philo_eat(t_philo *ptr);
int		philo_sleep(t_philo *ptr);
void	*philo(void *arg);
void	*god(void *arg);

#endif
