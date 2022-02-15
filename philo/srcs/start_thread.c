/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:46:11 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/02/15 19:15:46 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	monitor(t_philo *data)
{
	int	i;

	while (!data->table->all_eaten)
	{
		i = 0;
		while (i < data->table->number_of_philosophers)
		{
			pthread_mutex_lock(data->table->meal_check);
			if (ft_get_time() - data[i].time_last_meal > \
				data[i].table->time_to_die && data->table->alive)
			{
				print_order(&data[i], "is dead", \
					ft_get_time() - data[i].table->time_start);
				data->table->alive = 0;
			}
			pthread_mutex_unlock(data->table->meal_check);
			i++;
		}
		if (!data->table->alive)
			break ;
		i = 0;
		while (data->table->number_of_times_must_eat != -1 && \
			i < data->table->number_of_philosophers && \
			data[i].times_has_eaten >= data->table->number_of_times_must_eat)
			i++;
		if (i == data->table->number_of_philosophers)
		{
			pthread_mutex_lock(data->table->meal_check);
			data->table->all_eaten = 1;
			data->table->alive = 0;
			printf("Se ha terminado\n");
			pthread_mutex_unlock(data->table->meal_check);
		}
	}
}

void	start_thread(t_philo *data)
{
	int		i;

	i = 0;
	data->table->time_start = ft_get_time();
	while (i < data->table->number_of_philosophers)
	{
		pthread_create(&data[i].id_threats, NULL, \
			metodo_filosofo, &data[i]);
		i++;
	}
	ft_usleep(1);
	monitor(data);
	i = 0;
	while (i < data->table->number_of_philosophers)
	{
		pthread_join(data[i].id_threats, NULL);
		i++;
	}
}
