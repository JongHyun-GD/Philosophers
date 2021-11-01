/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyun <hyun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 12:22:15 by jongpark          #+#    #+#             */
/*   Updated: 2021/10/31 13:52:34 by hyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <time.h>
# include <sys/time.h>
# include <stdio.h>
# include <pthread.h>

int		my_atoi(char *str, int *res);
time_t	get_time_ms(void);
void	printf_safe(char *str, time_t time, int id, pthread_mutex_t *print_mutex);

#endif
