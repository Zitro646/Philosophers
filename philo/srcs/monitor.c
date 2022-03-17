/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:39:16 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/03/17 13:56:32 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	end_threads(t_philo *data)
{
	pthread_mutex_lock(data->table->live);
	data->table->alive = 0;
	pthread_mutex_unlock(data->table->live);
}

int	ft_check_philo_alive(t_philo *philo, int i)
{
	pthread_mutex_lock(&philo[i].meal_check);
	if ((ft_get_time() - philo[i].time_last_meal) > philo[i].table->time_to_die)
	{
		pthread_mutex_unlock(&philo[i].meal_check);
		return (1);
	}
	pthread_mutex_unlock(&philo[i].meal_check);
	return (0);
}

static int	ft_check_everyone_ate(t_philo *data)
{
	int	i;
	int	full;

	full = 0;
	i = 0;
	if (data->table->number_of_times_must_eat == -1)
		return (0);
	while (i < data->table->number_of_philosophers)
	{
		pthread_mutex_lock(&data[i].meal_check);
		if (data[i].times_has_eaten >= data[i].table->number_of_times_must_eat)
			full++;
		pthread_mutex_unlock(&data[i].meal_check);
		i++;
	}
	if (full == data->table->number_of_philosophers)
		return (1);
	return (0);
}

void	monitor(t_philo *data)
{
	int	i;
	int	some_one_dead;
	int	all_have_eaten;

	some_one_dead = 0;
	all_have_eaten = 0;
	while (!some_one_dead && !all_have_eaten)
	{
		i = 0;
		while (i < data->table->number_of_philosophers)
		{
			some_one_dead = ft_check_philo_alive(data, i);
			all_have_eaten = ft_check_everyone_ate(data);
			if (some_one_dead || all_have_eaten)
				break ;
			i++;
		}
		if (!some_one_dead && !all_have_eaten)
			ft_usleep(1, data->table);
	}
	if (some_one_dead)
		print_order(&data[i], "died", \
					ft_get_time() - data[i].table->time_start);
	end_threads(data);
}
