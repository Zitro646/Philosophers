/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:46:11 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/02/03 17:26:17 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*metodo_filosofo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	printf("Hola! soy el filosofo nº %i con id %p\n", philo->id, philo->id_threats);
	return (arg);
}

void	*metodo_tenedor(void *arg)
{
	t_fork	*fork;

	fork = (t_fork *)arg;
	printf("Hola! soy el tenedor nº %i con id %p\n", fork->id, fork->id_threats);
	return (arg);
}

void	start_thread(t_table data)
{
	int		i;
	t_fork	*fork;

	i = 0;
	fork = data.philosophers->forks;
	while (i < data.number_of_philosophers)
	{
		pthread_create(&data.philosophers[i].id_threats, NULL, metodo_filosofo, \
			&data.philosophers[i]);
		pthread_create(&fork[i].id_threats, NULL, metodo_tenedor, &fork[i]);
		i++;
	}
	i = 0;
	while (i < data.number_of_philosophers)
	{
		pthread_join(data.philosophers[i].id_threats, NULL);
		pthread_join(fork[i].id_threats, NULL);
		i++;
	}
}
