/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:35:27 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/02/14 14:20:22 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_control(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		printf("No se han introducido los datos correctamente\n");
		return (0);
	}
	if (ft_atoi(argv[1]) <= 0)
	{
		printf("No hay suficientes filosofos para comer\n");
		return (-1);
	}
	if (ft_atoi(argv[2]) <= 0 || ft_atoi(argv[3]) <= 0 || ft_atoi(argv[4]) <= 0)
	{
		printf("El tiempo no esta bien indicado\n");
		return (-1);
	}
	if (argc == 6)
	{
		if (ft_atoi(argv[5]) <= 0)
		{
			printf("El numero de veces que come es erroneo\n");
			return (-1);
		}
	}
	return (1);
}
