/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:46:11 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/03/17 13:46:29 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_thread(t_philo *data)
{
	int		i;

	i = 0;
	pthread_mutex_lock(data->table->start);
	while (i < data->table->number_of_philosophers)
	{
		pthread_create(&data[i].id_threats, NULL, \
			metodo_filosofo, &data[i]);
		i++;
	}
	data->table->time_start = ft_get_time();
	i = 0;
	while (i < data->table->number_of_philosophers)
	{
		data[i++].time_last_meal = data->table->time_start;
	}
	pthread_mutex_unlock(data->table->start);
	ft_usleep(1, data->table);
	monitor(data);
	i = 0;
	while (i < data->table->number_of_philosophers)
	{
		pthread_join(data[i].id_threats, NULL);
		i++;
	}
}
