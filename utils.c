/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongpark <jongpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 12:15:47 by jongpark          #+#    #+#             */
/*   Updated: 2021/11/01 16:15:04 by jongpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	my_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	my_atoi(char *str, int *res)
{
	unsigned long long	num;
	int					idx;
	int					len;
	int					sign;

	num = 0;
	idx = 0;
	len = my_strlen(str);
	sign = 1;
	*res = 0;
	if (str[0] == '-' && ++idx)
		sign = -1;
	while (idx < len)
	{
		if (str[idx] < '0' || str[idx] > '9')
			*res = -1;
		num *= 10;
		num += str[idx] - '0';
		idx++;
	}
	if ((sign == 1 && num >= 2147483648) || (sign == -1 && num >= 2147483649))
		*res = -1;
	return (num * sign);
}

time_t	get_time_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, 0);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	printf_safe(char *str, time_t start_time,
	int id, pthread_mutex_t *print_mutex)
{
	pthread_mutex_lock(print_mutex);
	printf(str, get_time_ms() - start_time, id);
	pthread_mutex_unlock(print_mutex);
}
