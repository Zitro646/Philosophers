/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:46:11 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/02/15 16:25:44 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	monitor(t_philo *data)
{
	int	i;

	while (data->table->alive == 1)
	{
		i = 0;
		while (i < data->table->number_of_philosophers)
		{
			pthread_mutex_lock(data->table->meal_check);
			if (ft_get_time() - data[i].time_last_meal > data[i].table->time_to_die \
				&& data->table->alive)
			{
				print_order(&data[i], "is dead", \
					ft_get_time() - data[i].table->time_start);
				data->table->alive = 0;
			}
			pthread_mutex_unlock(data->table->meal_check);
			i++;
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
		//usleep(50);
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

//printf("Han comido todos? %i/1\n",everybody_ate(data));
//printf("Se acabo %i\n",get_time());
