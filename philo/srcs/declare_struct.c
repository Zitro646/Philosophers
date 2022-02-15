/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   declare_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:41:13 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/02/15 13:33:17 by mortiz-d         ###   ########.fr       */
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

t_philo	*declare_philos(int n_philos, t_table *table)
{
	t_philo			*philo;
	pthread_mutex_t	*fork;
	int				i;

	i = -1;
	fork = declare_forks(n_philos);
	table->forks = fork;
	philo = ft_calloc(sizeof(t_philo), n_philos);
	while (++i < n_philos)
	{
		if (i - 1 == -1)
			philo[i].l_fork = &fork[n_philos - 1];
		else
			philo[i].l_fork = &fork[i - 1];
		philo[i].r_fork = &fork[i];
		philo[i].id = i + 1;
		philo[i].table = table;
		philo[i].times_has_eaten = 0;
	}
	return (philo);
}

t_table	*declare_table(int argc, char **argv)
{
	t_table	*table;

	table = ft_calloc(sizeof(t_table), 1);
	table[0].alive = 1;
	table[0].number_of_philosophers = ft_atoi(argv[1]);
	table[0].time_to_die = ft_atoi(argv[2]);
	table[0].time_to_eat = ft_atoi(argv[3]);
	table[0].time_to_sleep = ft_atoi(argv[4]);
	table[0].number_of_times_must_eat = -1;
	if (argc == 6)
		table[0].number_of_times_must_eat = ft_atoi(argv[5]);
	return (table);
}

t_philo	*declare_struct(int argc, char **argv)
{
	t_table	*table;
	t_philo	*philos;

	table = declare_table(argc, argv);
	table->print = ft_calloc(sizeof(pthread_mutex_t), 1);
	pthread_mutex_init(table->print, NULL);
	table->live = ft_calloc(sizeof(pthread_mutex_t), 1);
	pthread_mutex_init(table->live, NULL);
	table->meal_check = ft_calloc(sizeof(pthread_mutex_t), 1);
	pthread_mutex_init(table->meal_check, NULL);
	philos = declare_philos(table[0].number_of_philosophers, table);
	return (philos);
}
