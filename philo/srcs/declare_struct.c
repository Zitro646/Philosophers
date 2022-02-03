/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   declare_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:41:13 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/02/03 17:20:23 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_fork	*declare_forks(int n_philos)
{
	t_fork	*fork;
	int		i;

	i = 0;
	fork = ft_calloc(sizeof(t_fork), n_philos);
	while (i < n_philos)
	{
		fork[i].id = i;
		fork[i].ocupied = 0;
		i++;
	}
	return (fork);
}

t_philo	*declare_philos(int n_philos)
{
	t_philo	*philo;
	t_fork	*fork;
	int		i;

	i = 0;
	fork = declare_forks(n_philos);
	philo = ft_calloc(sizeof(t_philo), n_philos);
	while (i < n_philos)
	{
		philo[i].forks = fork;
		philo[i].id = i;
		i++;
	}
	return (philo);
}

t_table	declare_table(int argc, char **argv)
{
	t_table	data;

	data.number_of_times_each_philosopher_must_eat = -1;
	data.number_of_philosophers = ft_atoi(argv[1]);
	data.time_to_die = ft_atoi(argv[2]);
	data.time_to_eat = ft_atoi(argv[3]);
	data.time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data.number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	data.philosophers = declare_philos(data.number_of_philosophers);
	return (data);
}
