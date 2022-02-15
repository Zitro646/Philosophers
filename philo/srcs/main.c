/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:08:16 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/02/15 15:05:41 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//gcc main -pthread
void	leaks(void)
{
	system("leaks -q philo");
}

int	main(int argc, char **argv)
{
	t_philo	*data;

	//atexit(leaks);
	if (error_control(argc, argv) != 1)
		return (0);
	data = declare_struct(argc, argv);
	//printf("Empezamos los hilos\n");
	start_thread(data);
	//printf("Terminamos con los hilos\n");
	leaks_control(data);
}
