/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   declare_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:41:13 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/02/04 17:49:16 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t	*declare_forks(int n_philos)
{
	pthread_mutex_t	*fork;
	int				i;

	i = 0;
	fork = ft_calloc(sizeof(pthread_mutex_t), n_philos);
	while (i < n_philos)
	{
		pthread_mutex_init(&fork[i], NULL);
		i++;
	}
	return (fork);
}

t_philo	*declare_philos(int n_philos, char **argv, int argc)
{
	t_philo			*philo;
	pthread_mutex_t	*fork;
	int				i;

	i = 0;
	fork = declare_forks(n_philos);
	philo = ft_calloc(sizeof(t_philo), n_philos);
	while (i < n_philos)
	{
		philo[i].forks = fork;
		philo[i].id = i;
		philo[i].number_of_philosophers = ft_atoi(argv[1]);
		philo[i].time_to_die = ft_atoi(argv[2]);
		philo[i].time_to_eat = ft_atoi(argv[3]);
		philo[i].time_to_sleep = ft_atoi(argv[4]);
		philo[i].number_of_times_must_eat = -1;
		if (argc == 6)
			philo[i].number_of_times_must_eat = ft_atoi(argv[5]);
		i++;
	}
	return (philo);
}

t_table	declare_table(int argc, char **argv)
{
	t_table	data;

	
	data.number_of_philosophers = ft_atoi(argv[1]);
	
	data.philosophers = declare_philos(data.number_of_philosophers, argv, argc);
	return (data);
}
