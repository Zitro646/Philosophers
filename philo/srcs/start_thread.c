/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:46:11 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/02/08 18:14:13 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_thread(t_philo *data)
{
	int		i;

	i = 0;
	while (i < data->table->number_of_philosophers)
	{
		if (i % 2 == 0)
		{
			pthread_create(&data[i].id_threats, NULL, \
				metodo_filosofo_pares, &data[i]);
		}
		else
		{
			pthread_create(&data[i].id_threats, NULL, \
				metodo_filosofo_impares, &data[i]);
		}
		i++;
	}
	i = 0;
	while (i < data->table->number_of_philosophers)
	{
		pthread_join(data[i].id_threats, NULL);
		i++;
	}
	//printf("Se acabo %i\n",get_time());
}
