/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:46:11 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/02/04 17:55:59 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	long	current_time;
	struct timeval	start;

	gettimeofday(&start, NULL);
	current_time = (start.tv_sec) * 1000 + (start.tv_usec) / 1000;
	return (current_time);
}

void	*metodo_filosofo_impares(void *arg)
{
	t_philo			*philo;
	int				nvueltas;
	long			time_start;

	nvueltas = 0;
	philo = (t_philo *)arg;
	time_start = get_time();
	while (nvueltas < philo->number_of_times_must_eat)
	{
		if (philo->id - 1 == -1)
			pthread_mutex_lock(&philo->forks[philo->number_of_philosophers - 1]);
		else
			pthread_mutex_lock(&philo->forks[philo->id - 1]);
		pthread_mutex_lock(&philo->forks[philo->id]);
		printf("%li - El filosofo %i empieza a comer\n", (get_time() - time_start), philo->id);
		usleep((philo->time_to_eat * 100));
		if (philo->id - 1 == -1)
			pthread_mutex_unlock(&philo->forks[philo->number_of_philosophers - 1]);
		else
			pthread_mutex_unlock(&philo->forks[philo->id - 1]);
		pthread_mutex_unlock(&philo->forks[philo->id]);
		usleep((philo->time_to_sleep * 100));
		nvueltas++;
	}
	return (arg);
}

void	*metodo_filosofo_pares(void *arg)
{
	t_philo			*philo;
	int				nvueltas;
	long			time_start;

	nvueltas = 0;
	philo = (t_philo *)arg;
	time_start = get_time();
	while (nvueltas < 3)
	{
		pthread_mutex_lock(&philo->forks[philo->id]);
		if (philo->id - 1 == -1)
			pthread_mutex_lock(&philo->forks[philo->number_of_philosophers - 1]);
		else
			pthread_mutex_lock(&philo->forks[philo->id - 1]);
		printf("%li - El filosofo %i empieza a comer\n", (get_time() - time_start), philo->id);
		usleep((philo->time_to_eat * 100));
		//printf("%i - El filosofo %i termina de comer\n", get_time() - time_start, philo->id);
		pthread_mutex_unlock(&philo->forks[philo->id]);
		if (philo->id - 1 == -1)
			pthread_mutex_unlock(&philo->forks[philo->number_of_philosophers - 1]);
		else
			pthread_mutex_unlock(&philo->forks[philo->id - 1]);
		usleep((philo->time_to_sleep * 100));
		nvueltas++;
	}
	return (arg);
}

void	start_thread(t_table data)
{
	int		i;

	i = 0;
	while (i < data.number_of_philosophers)
	{
		if (i % 2 == 0)
		{
			pthread_create(&data.philosophers[i].id_threats, NULL, \
				metodo_filosofo_pares, &data.philosophers[i]);
		}
		else
		{
			pthread_create(&data.philosophers[i].id_threats, NULL, \
				metodo_filosofo_impares, &data.philosophers[i]);
		}
		i++;
	}
	i = 0;
	while (i < data.number_of_philosophers)
	{
		pthread_join(data.philosophers[i].id_threats, NULL);
		i++;
	}
	//printf("Se acabo %i\n",get_time());
}
