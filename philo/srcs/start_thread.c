/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:46:11 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/02/02 16:39:21 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*metodo_filosofo(void *arg)
{
	usleep(1000);
	printf("El filosofo ha terminado %p\n",arg);
	return (arg);
}

void	*metodo_tenedor(void *arg)
{
	usleep(1000);
	printf("El tenedor ha terminado %p\n",arg);
	return (arg);
}

void	start_thread(t_philo data)
{
	int	i;

	i = 0;
	printf("Antes de todo \n");
	while (i < data.number_of_philosophers)
	{
		printf("Movimiento %i \n", i);
		pthread_create(data.philo_threats[i], NULL, metodo_filosofo, &data);
		printf("El filosofo %i ha empezado\n", i);
		pthread_create(&data.fork_threats[i], NULL, metodo_tenedor, &data);
		printf("El tenedor %i ha empezado\n", i);
		i++;
	}
	i = 0;
	while (i < data.number_of_philosophers)
	{
		pthread_join(data.philo_threats[i], NULL);
		pthread_join(data.fork_threats[i], NULL);
		i++;
	}
}
