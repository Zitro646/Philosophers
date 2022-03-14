/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:35:27 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/03/14 13:41:37 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_control(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		printf("Error not enougth args\n");
		return (0);
	}
	if (ft_atoi(argv[1]) <= 0)
	{
		printf("Error not enougth philos\n");
		return (-1);
	}
	if (ft_atoi(argv[2]) <= 0 || ft_atoi(argv[3]) <= 0 || ft_atoi(argv[4]) <= 0)
	{
		printf("Time is not well specified\n");
		return (-1);
	}
	if (argc == 6)
	{
		if (ft_atoi(argv[5]) <= 0)
		{
			printf("Wrong number of times to eat\n");
			return (-1);
		}
	}
	return (1);
}
