/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongpark <jongpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 19:53:32 by jongpark          #+#    #+#             */
/*   Updated: 2021/10/29 13:44:00 by jongpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	philo_take_fork(t_philo *ptr)
{
	if (ptr->id % 2 == 1)
	{
		pthread_mutex_lock(ptr->left_fork);
		if (*(ptr->is_alive))
			printf("\033[32m%ldms %d has taken a fork\n\033[37m",
				get_time_ms() - ptr->start_time, ptr->id);
		pthread_mutex_lock(ptr->right_fork);
		if (*(ptr->is_alive))
			printf("\033[32m%ldms %d has taken a fork\n\033[37m",
				get_time_ms() - ptr->start_time, ptr->id);
	}
	else
	{
		pthread_mutex_lock(ptr->right_fork);
		if (*(ptr->is_alive))
			printf("\033[32m%ldms %d has taken a fork\n\033[37m",
				get_time_ms() - ptr->start_time, ptr->id);
		pthread_mutex_lock(ptr->left_fork);
		if (*(ptr->is_alive))
			printf("\033[32m%ldms %d has taken a fork\n\033[37m",
				get_time_ms() - ptr->start_time, ptr->id);
	}
	return (0);
}

int	philo_eat(t_philo *ptr)
{
	ptr->ate_time = get_time_ms();
	if (ptr->remained > 0)
		ptr->remained--;
	if (*(ptr->is_alive))
	{
		printf("\033[32m%ldms %d is eating\n\033[37m",
			get_time_ms() - ptr->start_time, ptr->id);
		usleep(ptr->time_eat * 1000);
	}
	pthread_mutex_unlock(ptr->left_fork);
	pthread_mutex_unlock(ptr->right_fork);
	return (0);
}

int	philo_sleep(t_philo *ptr)
{
	printf("%ldms %d is sleeping\n", get_time_ms() - ptr->start_time, ptr->id);
	usleep(ptr->time_sleep * 1000);
	if (!*(ptr->is_alive))
		return (0);
	printf("%ldms %d is thinking\n", get_time_ms() - ptr->start_time, ptr->id);
	usleep(50);
	return (0);
}

void	*philo(void *arg)
{
	t_philo	*ptr;

	ptr = arg;
	if (ptr->id % 2 == 1)
	{
		usleep(50);
	}
	while (*(ptr->is_alive) && (ptr->remained > 0 || ptr->remained == -42))
	{
		if (*(ptr->is_alive))
			philo_take_fork(ptr);
		philo_eat(ptr);
		if (ptr->remained == 0)
			return (0);
		if (*(ptr->is_alive))
			philo_sleep(ptr);
	}
	return (0);
}

void	*god(void *arg)
{
	t_philo	*ptr;

	ptr = arg;
	while (1)
	{
		if (!*(ptr->is_alive))
			return (0);
		if (ptr->remained == 0)
			return (0);
		if (get_time_ms() - ptr->ate_time > ptr->time_die)
		{
			pthread_mutex_lock(ptr->alive_mutex);
			if (*(ptr->is_alive))
			{
				printf("\033[31m%ldms %d died\n\033[37m",
					get_time_ms() - ptr->start_time, ptr->id);
				*(ptr->is_alive) = 0;
			}
			if (ptr->id == 0)
				pthread_mutex_unlock(ptr->left_fork);
			pthread_mutex_unlock(ptr->alive_mutex);
			return (0);
		}
	}
}
