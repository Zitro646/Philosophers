/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:08:16 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/02/04 17:51:27 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//gcc main -pthread

int	main(int argc, char **argv)
{
	t_table	data;

	if (argc < 5 || argc > 6)
	{
		printf("No se han introducido los datos correctamente\n");
		return (0);
	}
	printf("declaramos los hilos\n");
	data = declare_table(argc, argv);
	printf("Empezamos los hilos\n");
	start_thread(data);
}
