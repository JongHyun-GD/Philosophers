/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongpark <jongpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 12:22:15 by jongpark          #+#    #+#             */
/*   Updated: 2021/11/02 21:34:35 by jongpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <time.h>
# include <sys/time.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>

int		my_atoi(char *str, int *res);
time_t	get_time_ms(void);
void	printf_safe(char *str, time_t time,
			int id, pthread_mutex_t *print_mutex);
void	my_sleep(time_t time_to_sleep);
int		is_valid_argv(int argc, char **argv);

#endif
