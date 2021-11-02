/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongpark <jongpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 21:26:03 by jongpark          #+#    #+#             */
/*   Updated: 2021/11/02 21:32:41 by jongpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

int	is_valid_argv(int argc, char **argv)
{
	int	i;
	int	it;

	i = 1;
	if (argc != 5 && argc != 6)
	{
		printf("\033[31mError: invalid arguments\n\033[037m");
		return (-1);
	}
	while (i < argc)
	{
		it = 0;
		while (argv[i][it])
		{
			if (argv[i][it] < '0' || argv[i][it] > '9')
			{
				printf("\033[31mError: invalid arguments\n\033[037m");
				return (-1);
			}
			it++;
		}
		i++;
	}
	return (0);
}
