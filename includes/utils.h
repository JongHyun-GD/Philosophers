/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongpark <jongpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 12:22:15 by jongpark          #+#    #+#             */
/*   Updated: 2021/07/15 17:23:14 by jongpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <time.h>
# include <sys/time.h>
# include <stdio.h>

int		my_atoi(char *str, int *res);
time_t	get_time_ms(void);

#endif
