/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:02:37 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/02/09 14:52:56 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	leaks_control(t_philo *data)
{
	t_table	*table;
	int		i;
	int		max;

	max = data->table->number_of_philosophers;
	table = data->table;
	i = 0;
	//printf("Liberamos los forks : %p\n", table->forks);
	free(table->forks);
	//printf("Liberamos la mesa : %p\n", table);
	free(table);
	//printf("Liberamos los filosofos : %p\n", data);
	while (i < max)
	{
		pthread_mutex_destroy(data[i].r_fork);
		i++;
	}
	free(data);
}
